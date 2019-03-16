 
#include "MavLinkMsg_statustext_long.h"
#include "common/mavlink.h"



void FMavlinkMsg_statustext_long::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_statustext_long_pack(systemId, componentId, &msg,  severity, (char*)text);
}

void FMavlinkMsg_statustext_long::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_statustext_long::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        severity = mavlink_msg_statustext_long_get_severity(msg);
        text = mavlink_msg_statustext_long_get_text(msg, statustext_long->text);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_STATUSTEXT_LONG_LEN? msg.len : MAVLINK_MSG_ID_STATUSTEXT_LONG_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_STATUSTEXT_LONG_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

