 
#include "MavLinkMsg_mount_orientation.h"
#include "common/mavlink.h"



void FMavlinkMsg_mount_orientation::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_mount_orientation_pack(systemId, componentId, &msg,  time_boot_ms, roll, pitch, yaw, yaw_absolute);
}

void FMavlinkMsg_mount_orientation::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_mount_orientation::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_mount_orientation_get_time_boot_ms(msg);
        roll = mavlink_msg_mount_orientation_get_roll(msg);
        pitch = mavlink_msg_mount_orientation_get_pitch(msg);
        yaw = mavlink_msg_mount_orientation_get_yaw(msg);
        yaw_absolute = mavlink_msg_mount_orientation_get_yaw_absolute(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_MOUNT_ORIENTATION_LEN? msg.len : MAVLINK_MSG_ID_MOUNT_ORIENTATION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_MOUNT_ORIENTATION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

