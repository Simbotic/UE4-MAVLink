 
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

}

