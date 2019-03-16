 
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
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_hil_controls::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_hil_controls_get_time_usec(msg);
        roll_ailerons = mavlink_msg_hil_controls_get_roll_ailerons(msg);
        pitch_elevator = mavlink_msg_hil_controls_get_pitch_elevator(msg);
        yaw_rudder = mavlink_msg_hil_controls_get_yaw_rudder(msg);
        throttle = mavlink_msg_hil_controls_get_throttle(msg);
        aux1 = mavlink_msg_hil_controls_get_aux1(msg);
        aux2 = mavlink_msg_hil_controls_get_aux2(msg);
        aux3 = mavlink_msg_hil_controls_get_aux3(msg);
        aux4 = mavlink_msg_hil_controls_get_aux4(msg);
        mode = mavlink_msg_hil_controls_get_mode(msg);
        nav_mode = mavlink_msg_hil_controls_get_nav_mode(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_HIL_CONTROLS_LEN? msg.len : MAVLINK_MSG_ID_HIL_CONTROLS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_HIL_CONTROLS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

