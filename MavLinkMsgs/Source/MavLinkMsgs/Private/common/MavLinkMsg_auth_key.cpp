 
#include "MavLinkMsg_auth_key.h"
#include "common/mavlink.h"



void FMavlinkMsg_auth_key::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_auth_key_pack(systemId, componentId, &msg,  (char*)key);
}

void FMavlinkMsg_auth_key::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_auth_key::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        key = mavlink_msg_auth_key_get_key(msg, auth_key->key);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_AUTH_KEY_LEN? msg.len : MAVLINK_MSG_ID_AUTH_KEY_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_AUTH_KEY_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

