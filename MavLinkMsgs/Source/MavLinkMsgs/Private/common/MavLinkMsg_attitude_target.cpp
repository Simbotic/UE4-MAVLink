 
#include "MavLinkMsg_attitude_target.h"
#include "common/mavlink.h"



void FMavlinkMsg_attitude_target::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_attitude_target_pack(systemId, componentId, &msg,  time_boot_ms, type_mask, q, body_roll_rate, body_pitch_rate, body_yaw_rate, thrust);
}

void FMavlinkMsg_attitude_target::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_attitude_target::Deserialize(const mavlink_message_t& msg)
{

}

