 
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
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_camera_capture_status::Deserialize(const mavlink_message_t& msg)
{

}

