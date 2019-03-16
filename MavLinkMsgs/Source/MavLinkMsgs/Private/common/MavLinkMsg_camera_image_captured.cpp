 
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
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_utc = mavlink_msg_camera_image_captured_get_time_utc(msg);
        time_boot_ms = mavlink_msg_camera_image_captured_get_time_boot_ms(msg);
        lat = mavlink_msg_camera_image_captured_get_lat(msg);
        lon = mavlink_msg_camera_image_captured_get_lon(msg);
        alt = mavlink_msg_camera_image_captured_get_alt(msg);
        relative_alt = mavlink_msg_camera_image_captured_get_relative_alt(msg);
        q = mavlink_msg_camera_image_captured_get_q(msg, camera_image_captured->q);
        image_index = mavlink_msg_camera_image_captured_get_image_index(msg);
        camera_id = mavlink_msg_camera_image_captured_get_camera_id(msg);
        capture_result = mavlink_msg_camera_image_captured_get_capture_result(msg);
        file_url = mavlink_msg_camera_image_captured_get_file_url(msg, camera_image_captured->file_url);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_LEN? msg.len : MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

