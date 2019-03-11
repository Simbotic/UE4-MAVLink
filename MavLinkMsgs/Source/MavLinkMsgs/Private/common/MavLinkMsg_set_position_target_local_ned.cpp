 
#include "MavLinkMsg_set_position_target_local_ned.h"
#include "common/mavlink.h"

void FMavlinkMsg_set_position_target_local_ned::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_set_position_target_local_ned_pack(systemId, componentId, &msg,  time_boot_ms, target_system, target_component, coordinate_frame, type_mask, x, y, z, vx, vy, vz, afx, afy, afz, yaw, yaw_rate);
}

void FMavlinkMsg_set_position_target_local_ned::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_set_position_target_local_ned::Deserialize(const mavlink_message_t& msg)
{

}
