 
#include "MavLinkMsg_orbit_execution_status.h"
#include "common/mavlink.h"



void FMavlinkMsg_orbit_execution_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_orbit_execution_status_pack(systemId, componentId, &msg,  time_usec, radius, frame, x, y, z);
}

void FMavlinkMsg_orbit_execution_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_orbit_execution_status::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_orbit_execution_status_get_time_usec(msg);
        radius = mavlink_msg_orbit_execution_status_get_radius(msg);
        x = mavlink_msg_orbit_execution_status_get_x(msg);
        y = mavlink_msg_orbit_execution_status_get_y(msg);
        z = mavlink_msg_orbit_execution_status_get_z(msg);
        frame = mavlink_msg_orbit_execution_status_get_frame(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_LEN? msg.len : MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

