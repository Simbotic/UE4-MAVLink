 
#include "MavLinkMsg_heartbeat.h"
#include "common/mavlink.h"



void FMavlinkMsg_heartbeat::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_heartbeat_pack(systemId, componentId, &msg,  type, autopilot, base_mode, custom_mode, system_status);
}

void FMavlinkMsg_heartbeat::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_heartbeat::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        custom_mode = mavlink_msg_heartbeat_get_custom_mode(msg);
        type = mavlink_msg_heartbeat_get_type(msg);
        autopilot = mavlink_msg_heartbeat_get_autopilot(msg);
        base_mode = mavlink_msg_heartbeat_get_base_mode(msg);
        system_status = mavlink_msg_heartbeat_get_system_status(msg);
        mavlink_version = mavlink_msg_heartbeat_get_mavlink_version(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_HEARTBEAT_LEN? msg.len : MAVLINK_MSG_ID_HEARTBEAT_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_HEARTBEAT_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

