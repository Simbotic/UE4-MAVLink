 
#include "MavLinkMsg_local_position_ned.h"
#include "common/mavlink.h"



void FMavlinkMsg_local_position_ned::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_local_position_ned_pack(systemId, componentId, &msg,  time_boot_ms, x, y, z, vx, vy, vz);
}

void FMavlinkMsg_local_position_ned::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_local_position_ned::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_local_position_ned_get_time_boot_ms(msg);
        x = mavlink_msg_local_position_ned_get_x(msg);
        y = mavlink_msg_local_position_ned_get_y(msg);
        z = mavlink_msg_local_position_ned_get_z(msg);
        vx = mavlink_msg_local_position_ned_get_vx(msg);
        vy = mavlink_msg_local_position_ned_get_vy(msg);
        vz = mavlink_msg_local_position_ned_get_vz(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN? msg.len : MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

