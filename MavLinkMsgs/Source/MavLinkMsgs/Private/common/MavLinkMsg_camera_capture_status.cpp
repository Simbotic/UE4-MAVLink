 
#include "MavLinkMsg_camera_capture_status.h"
#include "common/mavlink.h"



void FMavlinkMsg_camera_capture_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_camera_capture_status_pack(systemId, componentId, &msg,  time_boot_ms, image_status, video_status, image_interval, recording_time_ms, available_capacity);
}

void FMavlinkMsg_camera_capture_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_camera_capture_status::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_camera_capture_status_get_time_boot_ms(msg);
        image_interval = mavlink_msg_camera_capture_status_get_image_interval(msg);
        recording_time_ms = mavlink_msg_camera_capture_status_get_recording_time_ms(msg);
        available_capacity = mavlink_msg_camera_capture_status_get_available_capacity(msg);
        image_status = mavlink_msg_camera_capture_status_get_image_status(msg);
        video_status = mavlink_msg_camera_capture_status_get_video_status(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_LEN? msg.len : MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

