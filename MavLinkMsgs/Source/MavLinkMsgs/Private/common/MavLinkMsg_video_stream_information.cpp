 
#include "MavLinkMsg_video_stream_information.h"
#include "common/mavlink.h"



void FMavlinkMsg_video_stream_information::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_video_stream_information_pack(systemId, componentId, &msg,  stream_id, count, type, flags, framerate, resolution_h, resolution_v, bitrate, rotation, hfov, (char*)name, (char*)uri);
}

void FMavlinkMsg_video_stream_information::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_video_stream_information::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        framerate = mavlink_msg_video_stream_information_get_framerate(msg);
        bitrate = mavlink_msg_video_stream_information_get_bitrate(msg);
        flags = mavlink_msg_video_stream_information_get_flags(msg);
        resolution_h = mavlink_msg_video_stream_information_get_resolution_h(msg);
        resolution_v = mavlink_msg_video_stream_information_get_resolution_v(msg);
        rotation = mavlink_msg_video_stream_information_get_rotation(msg);
        hfov = mavlink_msg_video_stream_information_get_hfov(msg);
        stream_id = mavlink_msg_video_stream_information_get_stream_id(msg);
        count = mavlink_msg_video_stream_information_get_count(msg);
        type = mavlink_msg_video_stream_information_get_type(msg);
        name = mavlink_msg_video_stream_information_get_name(msg, video_stream_information->name);
        uri = mavlink_msg_video_stream_information_get_uri(msg, video_stream_information->uri);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_LEN? msg.len : MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

