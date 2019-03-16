 
#include "MavLinkMsg_mission_item.h"
#include "common/mavlink.h"



void FMavlinkMsg_mission_item::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_mission_item_pack(systemId, componentId, &msg,  target_system, target_component, seq, frame, command, current, autocontinue, param1, param2, param3, param4, x, y, z, mission_type);
}

void FMavlinkMsg_mission_item::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_mission_item::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        param1 = mavlink_msg_mission_item_get_param1(msg);
        param2 = mavlink_msg_mission_item_get_param2(msg);
        param3 = mavlink_msg_mission_item_get_param3(msg);
        param4 = mavlink_msg_mission_item_get_param4(msg);
        x = mavlink_msg_mission_item_get_x(msg);
        y = mavlink_msg_mission_item_get_y(msg);
        z = mavlink_msg_mission_item_get_z(msg);
        seq = mavlink_msg_mission_item_get_seq(msg);
        command = mavlink_msg_mission_item_get_command(msg);
        target_system = mavlink_msg_mission_item_get_target_system(msg);
        target_component = mavlink_msg_mission_item_get_target_component(msg);
        frame = mavlink_msg_mission_item_get_frame(msg);
        current = mavlink_msg_mission_item_get_current(msg);
        autocontinue = mavlink_msg_mission_item_get_autocontinue(msg);
        mission_type = mavlink_msg_mission_item_get_mission_type(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_MISSION_ITEM_LEN? msg.len : MAVLINK_MSG_ID_MISSION_ITEM_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_MISSION_ITEM_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

