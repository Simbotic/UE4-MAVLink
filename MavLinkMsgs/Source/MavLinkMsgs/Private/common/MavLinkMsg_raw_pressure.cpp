 
#include "MavLinkMsg_raw_pressure.h"
#include "common/mavlink.h"



void FMavlinkMsg_raw_pressure::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_raw_pressure_pack(systemId, componentId, &msg,  time_usec, press_abs, press_diff1, press_diff2, temperature);
}

void FMavlinkMsg_raw_pressure::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_raw_pressure::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_raw_pressure_get_time_usec(msg);
        press_abs = mavlink_msg_raw_pressure_get_press_abs(msg);
        press_diff1 = mavlink_msg_raw_pressure_get_press_diff1(msg);
        press_diff2 = mavlink_msg_raw_pressure_get_press_diff2(msg);
        temperature = mavlink_msg_raw_pressure_get_temperature(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_RAW_PRESSURE_LEN? msg.len : MAVLINK_MSG_ID_RAW_PRESSURE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_RAW_PRESSURE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

