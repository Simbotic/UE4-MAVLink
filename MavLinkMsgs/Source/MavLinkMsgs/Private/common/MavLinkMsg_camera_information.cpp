 
#include "MavLinkMsg_camera_information.h"
#include "common/mavlink.h"



void FMavlinkMsg_camera_information::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_camera_information_pack(systemId, componentId, &msg,  time_boot_ms, (uint8_t*)vendor_name, (uint8_t*)model_name, firmware_version, focal_length, sensor_size_h, sensor_size_v, resolution_h, resolution_v, lens_id, flags, cam_definition_version, (char*)cam_definition_uri);
}

void FMavlinkMsg_camera_information::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_camera_information::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_camera_information_get_time_boot_ms(msg);
        firmware_version = mavlink_msg_camera_information_get_firmware_version(msg);
        focal_length = mavlink_msg_camera_information_get_focal_length(msg);
        sensor_size_h = mavlink_msg_camera_information_get_sensor_size_h(msg);
        sensor_size_v = mavlink_msg_camera_information_get_sensor_size_v(msg);
        flags = mavlink_msg_camera_information_get_flags(msg);
        resolution_h = mavlink_msg_camera_information_get_resolution_h(msg);
        resolution_v = mavlink_msg_camera_information_get_resolution_v(msg);
        cam_definition_version = mavlink_msg_camera_information_get_cam_definition_version(msg);
        vendor_name = mavlink_msg_camera_information_get_vendor_name(msg, camera_information->vendor_name);
        model_name = mavlink_msg_camera_information_get_model_name(msg, camera_information->model_name);
        lens_id = mavlink_msg_camera_information_get_lens_id(msg);
        cam_definition_uri = mavlink_msg_camera_information_get_cam_definition_uri(msg, camera_information->cam_definition_uri);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_CAMERA_INFORMATION_LEN? msg.len : MAVLINK_MSG_ID_CAMERA_INFORMATION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_CAMERA_INFORMATION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

