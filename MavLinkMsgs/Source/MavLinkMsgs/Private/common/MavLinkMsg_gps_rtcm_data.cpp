 
#include "MavLinkMsg_gps_rtcm_data.h"
#include "common/mavlink.h"



void FMavlinkMsg_gps_rtcm_data::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_gps_rtcm_data_pack(systemId, componentId, &msg,  flags, len, (uint8_t*)data);
}

void FMavlinkMsg_gps_rtcm_data::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_gps_rtcm_data::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        flags = mavlink_msg_gps_rtcm_data_get_flags(msg);
        len = mavlink_msg_gps_rtcm_data_get_len(msg);
        data = mavlink_msg_gps_rtcm_data_get_data(msg, gps_rtcm_data->data);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_GPS_RTCM_DATA_LEN? msg.len : MAVLINK_MSG_ID_GPS_RTCM_DATA_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_GPS_RTCM_DATA_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

