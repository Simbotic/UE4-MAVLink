 
#include "MavLinkMsg_camera_trigger.h"
#include "common/mavlink.h"



void FMavlinkMsg_camera_trigger::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_camera_trigger_pack(systemId, componentId, &msg,  time_usec, seq);
}

void FMavlinkMsg_camera_trigger::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_camera_trigger::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_camera_trigger_get_time_usec(msg);
        seq = mavlink_msg_camera_trigger_get_seq(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_CAMERA_TRIGGER_LEN? msg.len : MAVLINK_MSG_ID_CAMERA_TRIGGER_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_CAMERA_TRIGGER_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

