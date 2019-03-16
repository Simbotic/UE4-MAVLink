// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPv4/IPv4Endpoint.h"
#include "UdpSocketReceiver.h"
#include "UdpSocketSender.h"
#include "MavLinkNode.generated.h"


class FUdpSocketReceiver;
class FUdpSocketSender;
class FSocket;
struct __mavlink_message;

/**
 * 
 */
UCLASS(BlueprintType)
class MAVLINKUE4_API UMavLinkNode : public UObject
{
	GENERATED_BODY()

    FUdpSocketReceiver* Receiver;
    FUdpSocketSender* Sender;
    FSocket* SocketTx;
    FSocket* SocketRx;
    TQueue<TSharedPtr<__mavlink_message>, EQueueMode::Spsc> MsgQueue;

	public:

    UMavLinkNode();
    ~UMavLinkNode();
	


	UFUNCTION(BlueprintCallable, Category="Mavlink")
	void Listen();
	void OnDataReceived(const FArrayReaderPtr& data, const FIPv4Endpoint& ip);
	UFUNCTION(BlueprintNativeEvent, Category = "Mavlink")
	void OnDataReceivedBP(const TArray<uint8>& data);
	UFUNCTION(BlueprintCallable, Category = "Mavlink")
	void SendHeartbeat();
    void GameTick(ELevelTick, float);
	
};
