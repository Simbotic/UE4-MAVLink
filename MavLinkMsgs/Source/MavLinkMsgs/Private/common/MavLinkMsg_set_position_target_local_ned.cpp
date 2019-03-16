 
#include "MavLinkMsg_set_position_target_local_ned.h"
#include "common/mavlink.h"



void FMavlinkMsg_set_position_target_local_ned::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_set_position_target_local_ned_pack(systemId, componentId, &msg,  time_boot_ms, target_system, target_component, coordinate_frame, type_mask, x, y, z, vx, vy, vz, afx, afy, afz, yaw, yaw_rate);
}

void FMavlinkMsg_set_position_target_local_ned::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_set_position_target_local_ned::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_set_position_target_local_ned_get_time_boot_ms(msg);
        x = mavlink_msg_set_position_target_local_ned_get_x(msg);
        y = mavlink_msg_set_position_target_local_ned_get_y(msg);
        z = mavlink_msg_set_position_target_local_ned_get_z(msg);
        vx = mavlink_msg_set_position_target_local_ned_get_vx(msg);
        vy = mavlink_msg_set_position_target_local_ned_get_vy(msg);
        vz = mavlink_msg_set_position_target_local_ned_get_vz(msg);
        afx = mavlink_msg_set_position_target_local_ned_get_afx(msg);
        afy = mavlink_msg_set_position_target_local_ned_get_afy(msg);
        afz = mavlink_msg_set_position_target_local_ned_get_afz(msg);
        yaw = mavlink_msg_set_position_target_local_ned_get_yaw(msg);
        yaw_rate = mavlink_msg_set_position_target_local_ned_get_yaw_rate(msg);
        type_mask = mavlink_msg_set_position_target_local_ned_get_type_mask(msg);
        target_system = mavlink_msg_set_position_target_local_ned_get_target_system(msg);
        target_component = mavlink_msg_set_position_target_local_ned_get_target_component(msg);
        coordinate_frame = mavlink_msg_set_position_target_local_ned_get_coordinate_frame(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_LEN? msg.len : MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

