 
#include "MavLinkMsg_camera_image_captured.h"
#include "common/mavlink.h"



void FMavlinkMsg_camera_image_captured::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_camera_image_captured_pack(systemId, componentId, &msg,  time_boot_ms, time_utc, camera_id, lat, lon, alt, relative_alt, q, image_index, capture_result, (char*)file_url);
}

void FMavlinkMsg_camera_image_captured::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_camera_image_captured::Deserialize(const mavlink_message_t& msg)
{

}

