 
#include "MavLinkMsg_camera_settings.h"
#include "common/mavlink.h"



void FMavlinkMsg_camera_settings::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_camera_settings_pack(systemId, componentId, &msg,  time_boot_ms, mode_id, zoomLevel, focusLevel);
}

void FMavlinkMsg_camera_settings::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_camera_settings::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_camera_settings_get_time_boot_ms(msg);
        mode_id = mavlink_msg_camera_settings_get_mode_id(msg);
        zoomLevel = mavlink_msg_camera_settings_get_zoomLevel(msg);
        focusLevel = mavlink_msg_camera_settings_get_focusLevel(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN? msg.len : MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

