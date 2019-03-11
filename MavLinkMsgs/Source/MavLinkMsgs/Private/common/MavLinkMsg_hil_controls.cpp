 
#include "MavLinkMsg_hil_controls.h"
#include "common/mavlink.h"

void FMavlinkMsg_hil_controls::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_hil_controls_pack(systemId, componentId, &msg,  time_usec, roll_ailerons, pitch_elevator, yaw_rudder, throttle, aux1, aux2, aux3, aux4, mode, nav_mode);
}

void FMavlinkMsg_hil_controls::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_hil_controls::Deserialize(const mavlink_message_t& msg)
{

}

