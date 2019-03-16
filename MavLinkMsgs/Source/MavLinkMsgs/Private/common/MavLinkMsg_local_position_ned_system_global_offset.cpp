 
#include "MavLinkMsg_local_position_ned_system_global_offset.h"
#include "common/mavlink.h"



void FMavlinkMsg_local_position_ned_system_global_offset::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_local_position_ned_system_global_offset_pack(systemId, componentId, &msg,  time_boot_ms, x, y, z, roll, pitch, yaw);
}

void FMavlinkMsg_local_position_ned_system_global_offset::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_local_position_ned_system_global_offset::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_local_position_ned_system_global_offset_get_time_boot_ms(msg);
        x = mavlink_msg_local_position_ned_system_global_offset_get_x(msg);
        y = mavlink_msg_local_position_ned_system_global_offset_get_y(msg);
        z = mavlink_msg_local_position_ned_system_global_offset_get_z(msg);
        roll = mavlink_msg_local_position_ned_system_global_offset_get_roll(msg);
        pitch = mavlink_msg_local_position_ned_system_global_offset_get_pitch(msg);
        yaw = mavlink_msg_local_position_ned_system_global_offset_get_yaw(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET_LEN? msg.len : MAVLINK_MSG_ID_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

