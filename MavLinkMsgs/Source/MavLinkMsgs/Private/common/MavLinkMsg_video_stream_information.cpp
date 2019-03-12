 
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

}

