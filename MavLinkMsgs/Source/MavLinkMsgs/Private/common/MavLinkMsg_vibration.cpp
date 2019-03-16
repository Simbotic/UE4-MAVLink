 
#include "MavLinkMsg_vibration.h"
#include "common/mavlink.h"



void FMavlinkMsg_vibration::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_vibration_pack(systemId, componentId, &msg,  time_usec, vibration_x, vibration_y, vibration_z, clipping_0, clipping_1, clipping_2);
}

void FMavlinkMsg_vibration::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_vibration::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_vibration_get_time_usec(msg);
        vibration_x = mavlink_msg_vibration_get_vibration_x(msg);
        vibration_y = mavlink_msg_vibration_get_vibration_y(msg);
        vibration_z = mavlink_msg_vibration_get_vibration_z(msg);
        clipping_0 = mavlink_msg_vibration_get_clipping_0(msg);
        clipping_1 = mavlink_msg_vibration_get_clipping_1(msg);
        clipping_2 = mavlink_msg_vibration_get_clipping_2(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_VIBRATION_LEN? msg.len : MAVLINK_MSG_ID_VIBRATION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_VIBRATION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

