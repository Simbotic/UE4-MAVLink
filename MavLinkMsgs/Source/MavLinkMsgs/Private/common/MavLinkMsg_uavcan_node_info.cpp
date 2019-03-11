 
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
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_uavcan_node_info::Deserialize(const mavlink_message_t& msg)
{

}

