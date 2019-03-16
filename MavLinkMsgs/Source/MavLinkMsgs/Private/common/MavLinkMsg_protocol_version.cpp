 
#include "MavLinkMsg_protocol_version.h"
#include "common/mavlink.h"



void FMavlinkMsg_protocol_version::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_protocol_version_pack(systemId, componentId, &msg,  version, min_version, max_version, (uint8_t*)spec_version_hash, (uint8_t*)library_version_hash);
}

void FMavlinkMsg_protocol_version::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_protocol_version::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        version = mavlink_msg_protocol_version_get_version(msg);
        min_version = mavlink_msg_protocol_version_get_min_version(msg);
        max_version = mavlink_msg_protocol_version_get_max_version(msg);
        spec_version_hash = mavlink_msg_protocol_version_get_spec_version_hash(msg, protocol_version->spec_version_hash);
        library_version_hash = mavlink_msg_protocol_version_get_library_version_hash(msg, protocol_version->library_version_hash);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_PROTOCOL_VERSION_LEN? msg.len : MAVLINK_MSG_ID_PROTOCOL_VERSION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_PROTOCOL_VERSION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

