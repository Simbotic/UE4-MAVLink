// Fill out your copyright notice in the Description page of Project Settings.

#include "MavLinkNode.h"
#include "SocketSubsystem.h"
#include "MavLinkUtils.h"
#include "UdpSocketBuilder.h"
#include "standard/mavlink.h"
#include "MavLinkDispatch.h"
#include "MavLink.h"


class FMavlinkHeartbeat
{
	TSharedRef<TArray<uint8>, ESPMode::ThreadSafe> GetData()
	{
		TSharedRef<TArray<uint8>, ESPMode::ThreadSafe> data;

		return data;
	}
};

UMavLinkNode::UMavLinkNode()
{
    FWorldDelegates::OnWorldTickStart.AddUObject(this, &UMavLinkNode::GameTick);
}

UMavLinkNode::~UMavLinkNode()
{

    delete Receiver;
    delete Sender;
    
    ISocketSubsystem* sub = ISocketSubsystem::Get();
    sub->DestroySocket(SocketRx);
    sub->DestroySocket(SocketTx);

    SocketRx = nullptr;
    SocketTx = nullptr;
   
}

void UMavLinkNode::Listen()
{
    SocketRx = FUdpSocketBuilder(TEXT("Mavlink Listener")).AsNonBlocking().BoundToPort(14540);
	Receiver = new FUdpSocketReceiver(SocketRx, FTimespan::FromMilliseconds(100), TEXT("Mavlink udp rx"));
    Receiver->OnDataReceived().BindUObject(this, &UMavLinkNode::OnDataReceived);
	Receiver->Start();
    

	
	SocketTx = FUdpSocketBuilder(TEXT("Mavlink sender")).AsNonBlocking().BoundToPort(15560);
	Sender = new FUdpSocketSender(SocketTx, TEXT("Mavlink udp tx"));

	
}

void UMavLinkNode::OnDataReceived(const FArrayReaderPtr& data, const FIPv4Endpoint& ip)
{
    TSharedPtr<__mavlink_message> msg = MakeShareable(new __mavlink_message);
    mavlink_status_t status;

    for (int i = 0; i < data->Num(); i++)
    {
        if (mavlink_parse_char(MAVLINK_COMM_0, (*data)[i], msg.Get(), &status))
        {
           
            MsgQueue.Enqueue(msg);
            // Packet received
            UE_LOG(LogTemp, Log, TEXT("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d"), msg->sysid, msg->compid, msg->len, msg->msgid);
        }
    }
	return;
}

void UMavLinkNode::SendHeartbeat()
{
    //mavlink_message_t msg;

    TSharedRef<TArray<uint8>, ESPMode::ThreadSafe> buffer = MakeShared<TArray<uint8>, ESPMode::ThreadSafe>();
    buffer->SetNum(256);
    
    FMavlinkMsg_hil_sensor sensor;

    sensor.Serialize(1, 1, buffer);
    Sender->Send(buffer, FIPv4Endpoint(FIPv4Address(127, 0, 0, 1), 14560));
    
}

void UMavLinkNode::GameTick(ELevelTick levelTick,  float dt)
{
    while (!MsgQueue.IsEmpty() )
    {
        TSharedPtr<__mavlink_message> msg;
        MsgQueue.Dequeue(msg);

        UMavLinkUtils::GetMavlinkMessages()->DispatchMessage(*msg);
    }
}

void UMavLinkNode::OnDataReceivedBP_Implementation(const TArray<uint8>& data)
{

}


