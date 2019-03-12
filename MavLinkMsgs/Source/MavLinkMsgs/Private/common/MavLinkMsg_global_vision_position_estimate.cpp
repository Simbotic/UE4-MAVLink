 
#include "MavLinkMsg_global_vision_position_estimate.h"
#include "common/mavlink.h"



void FMavlinkMsg_global_vision_position_estimate::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_global_vision_position_estimate_pack(systemId, componentId, &msg,  usec, x, y, z, roll, pitch, yaw, covariance);
}

void FMavlinkMsg_global_vision_position_estimate::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_global_vision_position_estimate::Deserialize(const mavlink_message_t& msg)
{

}

