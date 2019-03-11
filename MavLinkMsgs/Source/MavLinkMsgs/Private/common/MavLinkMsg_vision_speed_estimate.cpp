 
#include "MavLinkMsg_vision_speed_estimate.h"
#include "common/mavlink.h"

void FMavlinkMsg_vision_speed_estimate::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_vision_speed_estimate_pack(systemId, componentId, &msg,  usec, x, y, z, covariance);
}

void FMavlinkMsg_vision_speed_estimate::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_vision_speed_estimate::Deserialize(const mavlink_message_t& msg)
{

}

