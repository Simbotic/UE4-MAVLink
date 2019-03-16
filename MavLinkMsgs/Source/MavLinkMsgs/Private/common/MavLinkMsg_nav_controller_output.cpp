 
#include "MavLinkMsg_nav_controller_output.h"
#include "common/mavlink.h"



void FMavlinkMsg_nav_controller_output::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_nav_controller_output_pack(systemId, componentId, &msg,  nav_roll, nav_pitch, nav_bearing, target_bearing, wp_dist, alt_error, aspd_error, xtrack_error);
}

void FMavlinkMsg_nav_controller_output::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_nav_controller_output::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        nav_roll = mavlink_msg_nav_controller_output_get_nav_roll(msg);
        nav_pitch = mavlink_msg_nav_controller_output_get_nav_pitch(msg);
        alt_error = mavlink_msg_nav_controller_output_get_alt_error(msg);
        aspd_error = mavlink_msg_nav_controller_output_get_aspd_error(msg);
        xtrack_error = mavlink_msg_nav_controller_output_get_xtrack_error(msg);
        nav_bearing = mavlink_msg_nav_controller_output_get_nav_bearing(msg);
        target_bearing = mavlink_msg_nav_controller_output_get_target_bearing(msg);
        wp_dist = mavlink_msg_nav_controller_output_get_wp_dist(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_LEN? msg.len : MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

