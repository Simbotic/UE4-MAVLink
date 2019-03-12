 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_home_position.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_home_position
{
    GENERATED_BODY()

    static const uint32 MsgId = 242;
    /*Latitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 latitude;

    /*Longitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 longitude;

    /*Altitude (MSL). Positive for up. [mm]*/
    UPROPERTY()
    int32 altitude;

    /*Local X position of this position in the local coordinate frame [m]*/
    UPROPERTY()
    float x;

    /*Local Y position of this position in the local coordinate frame [m]*/
    UPROPERTY()
    float y;

    /*Local Z position of this position in the local coordinate frame [m]*/
    UPROPERTY()
    float z;

    /*World to surface normal and heading transformation of the takeoff position. Used to indicate the heading and slope of the ground */
    UPROPERTY()
    float q[4];

    /*Local X position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone. [m]*/
    UPROPERTY()
    float approach_x;

    /*Local Y position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone. [m]*/
    UPROPERTY()
    float approach_y;

    /*Local Z position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone. [m]*/
    UPROPERTY()
    float approach_z;

    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
