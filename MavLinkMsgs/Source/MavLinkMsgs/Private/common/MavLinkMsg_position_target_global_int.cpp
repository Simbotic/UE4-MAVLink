 
#include "MavLinkMsg_position_target_global_int.h"
#include "common/mavlink.h"

void FMavlinkMsg_position_target_global_int::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_position_target_global_int_pack(systemId, componentId, &msg,  time_boot_ms, coordinate_frame, type_mask, lat_int, lon_int, alt, vx, vy, vz, afx, afy, afz, yaw, yaw_rate);
}

void FMavlinkMsg_position_target_global_int::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_position_target_global_int::Deserialize(const mavlink_message_t& msg)
{

}

