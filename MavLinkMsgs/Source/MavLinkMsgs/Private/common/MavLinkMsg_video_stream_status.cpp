 
#include "MavLinkMsg_video_stream_status.h"
#include "common/mavlink.h"



void FMavlinkMsg_video_stream_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_video_stream_status_pack(systemId, componentId, &msg,  stream_id, flags, framerate, resolution_h, resolution_v, bitrate, rotation, hfov);
}

void FMavlinkMsg_video_stream_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_video_stream_status::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        framerate = mavlink_msg_video_stream_status_get_framerate(msg);
        bitrate = mavlink_msg_video_stream_status_get_bitrate(msg);
        flags = mavlink_msg_video_stream_status_get_flags(msg);
        resolution_h = mavlink_msg_video_stream_status_get_resolution_h(msg);
        resolution_v = mavlink_msg_video_stream_status_get_resolution_v(msg);
        rotation = mavlink_msg_video_stream_status_get_rotation(msg);
        hfov = mavlink_msg_video_stream_status_get_hfov(msg);
        stream_id = mavlink_msg_video_stream_status_get_stream_id(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_VIDEO_STREAM_STATUS_LEN? msg.len : MAVLINK_MSG_ID_VIDEO_STREAM_STATUS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_VIDEO_STREAM_STATUS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

