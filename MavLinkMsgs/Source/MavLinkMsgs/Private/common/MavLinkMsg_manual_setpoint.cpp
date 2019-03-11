 
#include "MavLinkMsg_manual_setpoint.h"
#include "common/mavlink.h"

void FMavlinkMsg_manual_setpoint::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_manual_setpoint_pack(systemId, componentId, &msg,  time_boot_ms, roll, pitch, yaw, thrust, mode_switch, manual_override_switch);
}

void FMavlinkMsg_manual_setpoint::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_manual_setpoint::Deserialize(const mavlink_message_t& msg)
{

}

