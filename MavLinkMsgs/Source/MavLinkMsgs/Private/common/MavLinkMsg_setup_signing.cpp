 
#include "MavLinkMsg_setup_signing.h"
#include "common/mavlink.h"



void FMavlinkMsg_setup_signing::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_setup_signing_pack(systemId, componentId, &msg,  target_system, target_component, (uint8_t*)secret_key, initial_timestamp);
}

void FMavlinkMsg_setup_signing::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_setup_signing::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        initial_timestamp = mavlink_msg_setup_signing_get_initial_timestamp(msg);
        target_system = mavlink_msg_setup_signing_get_target_system(msg);
        target_component = mavlink_msg_setup_signing_get_target_component(msg);
        secret_key = mavlink_msg_setup_signing_get_secret_key(msg, setup_signing->secret_key);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SETUP_SIGNING_LEN? msg.len : MAVLINK_MSG_ID_SETUP_SIGNING_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SETUP_SIGNING_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

