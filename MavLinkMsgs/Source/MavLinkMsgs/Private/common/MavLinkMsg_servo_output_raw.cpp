 
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

}

