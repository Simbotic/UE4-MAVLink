 
#include "MavLinkMsg_servo_output_raw.h"
#include "common/mavlink.h"



void FMavlinkMsg_servo_output_raw::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_servo_output_raw_pack(systemId, componentId, &msg,  time_usec, port, servo1_raw, servo2_raw, servo3_raw, servo4_raw, servo5_raw, servo6_raw, servo7_raw, servo8_raw, servo9_raw, servo10_raw, servo11_raw, servo12_raw, servo13_raw, servo14_raw, servo15_raw, servo16_raw);
}

void FMavlinkMsg_servo_output_raw::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_servo_output_raw::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_servo_output_raw_get_time_usec(msg);
        servo1_raw = mavlink_msg_servo_output_raw_get_servo1_raw(msg);
        servo2_raw = mavlink_msg_servo_output_raw_get_servo2_raw(msg);
        servo3_raw = mavlink_msg_servo_output_raw_get_servo3_raw(msg);
        servo4_raw = mavlink_msg_servo_output_raw_get_servo4_raw(msg);
        servo5_raw = mavlink_msg_servo_output_raw_get_servo5_raw(msg);
        servo6_raw = mavlink_msg_servo_output_raw_get_servo6_raw(msg);
        servo7_raw = mavlink_msg_servo_output_raw_get_servo7_raw(msg);
        servo8_raw = mavlink_msg_servo_output_raw_get_servo8_raw(msg);
        port = mavlink_msg_servo_output_raw_get_port(msg);
        servo9_raw = mavlink_msg_servo_output_raw_get_servo9_raw(msg);
        servo10_raw = mavlink_msg_servo_output_raw_get_servo10_raw(msg);
        servo11_raw = mavlink_msg_servo_output_raw_get_servo11_raw(msg);
        servo12_raw = mavlink_msg_servo_output_raw_get_servo12_raw(msg);
        servo13_raw = mavlink_msg_servo_output_raw_get_servo13_raw(msg);
        servo14_raw = mavlink_msg_servo_output_raw_get_servo14_raw(msg);
        servo15_raw = mavlink_msg_servo_output_raw_get_servo15_raw(msg);
        servo16_raw = mavlink_msg_servo_output_raw_get_servo16_raw(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SERVO_OUTPUT_RAW_LEN? msg.len : MAVLINK_MSG_ID_SERVO_OUTPUT_RAW_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SERVO_OUTPUT_RAW_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

