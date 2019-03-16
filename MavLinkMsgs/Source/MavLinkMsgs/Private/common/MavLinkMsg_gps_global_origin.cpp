 
#include "MavLinkMsg_gps_global_origin.h"
#include "common/mavlink.h"



void FMavlinkMsg_gps_global_origin::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_gps_global_origin_pack(systemId, componentId, &msg,  latitude, longitude, altitude, time_usec);
}

void FMavlinkMsg_gps_global_origin::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_gps_global_origin::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        latitude = mavlink_msg_gps_global_origin_get_latitude(msg);
        longitude = mavlink_msg_gps_global_origin_get_longitude(msg);
        altitude = mavlink_msg_gps_global_origin_get_altitude(msg);
        time_usec = mavlink_msg_gps_global_origin_get_time_usec(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_LEN? msg.len : MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

