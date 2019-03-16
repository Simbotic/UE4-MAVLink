 
#include "MavLinkMsg_uavcan_node_status.h"
#include "common/mavlink.h"



void FMavlinkMsg_uavcan_node_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_uavcan_node_status_pack(systemId, componentId, &msg,  time_usec, uptime_sec, health, mode, sub_mode, vendor_specific_status_code);
}

void FMavlinkMsg_uavcan_node_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_uavcan_node_status::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_uavcan_node_status_get_time_usec(msg);
        uptime_sec = mavlink_msg_uavcan_node_status_get_uptime_sec(msg);
        vendor_specific_status_code = mavlink_msg_uavcan_node_status_get_vendor_specific_status_code(msg);
        health = mavlink_msg_uavcan_node_status_get_health(msg);
        mode = mavlink_msg_uavcan_node_status_get_mode(msg);
        sub_mode = mavlink_msg_uavcan_node_status_get_sub_mode(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_UAVCAN_NODE_STATUS_LEN? msg.len : MAVLINK_MSG_ID_UAVCAN_NODE_STATUS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_UAVCAN_NODE_STATUS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

