 
#include "MavLinkMsg_hil_actuator_controls.h"
#include "common/mavlink.h"



void FMavlinkMsg_hil_actuator_controls::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_hil_actuator_controls_pack(systemId, componentId, &msg,  time_usec, controls, mode, flags);
}

void FMavlinkMsg_hil_actuator_controls::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_hil_actuator_controls::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_hil_actuator_controls_get_time_usec(msg);
        flags = mavlink_msg_hil_actuator_controls_get_flags(msg);
        controls = mavlink_msg_hil_actuator_controls_get_controls(msg, hil_actuator_controls->controls);
        mode = mavlink_msg_hil_actuator_controls_get_mode(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_LEN? msg.len : MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

