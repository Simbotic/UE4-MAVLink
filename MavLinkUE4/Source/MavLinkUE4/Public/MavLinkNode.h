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



/**
 * 
 */
UCLASS(BlueprintType)
class MAVLINKUE4_API UMavLinkNode : public UObject
{
	GENERATED_BODY()

	public:

    UMavLinkNode();
    ~UMavLinkNode();
	FUdpSocketReceiver* Receiver;
	FUdpSocketSender* Sender;
    FSocket* SocketTx;
    FSocket* SocketRx;

	UFUNCTION(BlueprintCallable, Category="Mavlink")
	void Listen();
	void OnDataReceived(const FArrayReaderPtr& data, const FIPv4Endpoint& ip);
	UFUNCTION(BlueprintNativeEvent, Category = "Mavlink")
	void OnDataReceivedBP(const TArray<uint8>& data);
	UFUNCTION(BlueprintCallable, Category = "Mavlink")
	void SendHeartbeat();
	
};
