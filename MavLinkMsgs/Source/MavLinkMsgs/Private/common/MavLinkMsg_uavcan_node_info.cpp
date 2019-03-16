 
#include "MavLinkMsg_uavcan_node_info.h"
#include "common/mavlink.h"



void FMavlinkMsg_uavcan_node_info::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_uavcan_node_info_pack(systemId, componentId, &msg,  time_usec, uptime_sec, (char*)name, hw_version_major, hw_version_minor, (uint8_t*)hw_unique_id, sw_version_major, sw_version_minor, sw_vcs_commit);
}

void FMavlinkMsg_uavcan_node_info::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_uavcan_node_info::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_uavcan_node_info_get_time_usec(msg);
        uptime_sec = mavlink_msg_uavcan_node_info_get_uptime_sec(msg);
        sw_vcs_commit = mavlink_msg_uavcan_node_info_get_sw_vcs_commit(msg);
        name = mavlink_msg_uavcan_node_info_get_name(msg, uavcan_node_info->name);
        hw_version_major = mavlink_msg_uavcan_node_info_get_hw_version_major(msg);
        hw_version_minor = mavlink_msg_uavcan_node_info_get_hw_version_minor(msg);
        hw_unique_id = mavlink_msg_uavcan_node_info_get_hw_unique_id(msg, uavcan_node_info->hw_unique_id);
        sw_version_major = mavlink_msg_uavcan_node_info_get_sw_version_major(msg);
        sw_version_minor = mavlink_msg_uavcan_node_info_get_sw_version_minor(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_UAVCAN_NODE_INFO_LEN? msg.len : MAVLINK_MSG_ID_UAVCAN_NODE_INFO_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_UAVCAN_NODE_INFO_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

