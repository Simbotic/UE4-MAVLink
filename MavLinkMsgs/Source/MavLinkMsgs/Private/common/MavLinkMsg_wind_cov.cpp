 
#include "MavLinkMsg_wind_cov.h"
#include "common/mavlink.h"



void FMavlinkMsg_wind_cov::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_wind_cov_pack(systemId, componentId, &msg,  time_usec, wind_x, wind_y, wind_z, var_horiz, var_vert, wind_alt, horiz_accuracy, vert_accuracy);
}

void FMavlinkMsg_wind_cov::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_wind_cov::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_wind_cov_get_time_usec(msg);
        wind_x = mavlink_msg_wind_cov_get_wind_x(msg);
        wind_y = mavlink_msg_wind_cov_get_wind_y(msg);
        wind_z = mavlink_msg_wind_cov_get_wind_z(msg);
        var_horiz = mavlink_msg_wind_cov_get_var_horiz(msg);
        var_vert = mavlink_msg_wind_cov_get_var_vert(msg);
        wind_alt = mavlink_msg_wind_cov_get_wind_alt(msg);
        horiz_accuracy = mavlink_msg_wind_cov_get_horiz_accuracy(msg);
        vert_accuracy = mavlink_msg_wind_cov_get_vert_accuracy(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_WIND_COV_LEN? msg.len : MAVLINK_MSG_ID_WIND_COV_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_WIND_COV_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

