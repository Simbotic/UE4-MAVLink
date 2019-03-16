 
#include "MavLinkMsg_attitude.h"
#include "common/mavlink.h"



void FMavlinkMsg_attitude::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_attitude_pack(systemId, componentId, &msg,  time_boot_ms, roll, pitch, yaw, rollspeed, pitchspeed, yawspeed);
}

void FMavlinkMsg_attitude::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_attitude::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_attitude_get_time_boot_ms(msg);
        roll = mavlink_msg_attitude_get_roll(msg);
        pitch = mavlink_msg_attitude_get_pitch(msg);
        yaw = mavlink_msg_attitude_get_yaw(msg);
        rollspeed = mavlink_msg_attitude_get_rollspeed(msg);
        pitchspeed = mavlink_msg_attitude_get_pitchspeed(msg);
        yawspeed = mavlink_msg_attitude_get_yawspeed(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_ATTITUDE_LEN? msg.len : MAVLINK_MSG_ID_ATTITUDE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_ATTITUDE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

