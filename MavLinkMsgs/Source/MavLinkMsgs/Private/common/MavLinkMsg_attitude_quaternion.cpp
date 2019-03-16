 
#include "MavLinkMsg_attitude_quaternion.h"
#include "common/mavlink.h"



void FMavlinkMsg_attitude_quaternion::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_attitude_quaternion_pack(systemId, componentId, &msg,  time_boot_ms, q1, q2, q3, q4, rollspeed, pitchspeed, yawspeed);
}

void FMavlinkMsg_attitude_quaternion::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_attitude_quaternion::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_attitude_quaternion_get_time_boot_ms(msg);
        q1 = mavlink_msg_attitude_quaternion_get_q1(msg);
        q2 = mavlink_msg_attitude_quaternion_get_q2(msg);
        q3 = mavlink_msg_attitude_quaternion_get_q3(msg);
        q4 = mavlink_msg_attitude_quaternion_get_q4(msg);
        rollspeed = mavlink_msg_attitude_quaternion_get_rollspeed(msg);
        pitchspeed = mavlink_msg_attitude_quaternion_get_pitchspeed(msg);
        yawspeed = mavlink_msg_attitude_quaternion_get_yawspeed(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_ATTITUDE_QUATERNION_LEN? msg.len : MAVLINK_MSG_ID_ATTITUDE_QUATERNION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_ATTITUDE_QUATERNION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

