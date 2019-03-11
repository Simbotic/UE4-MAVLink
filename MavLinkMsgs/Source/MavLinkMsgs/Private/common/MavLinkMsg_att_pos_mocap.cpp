 
#include "MavLinkMsg_att_pos_mocap.h"
#include "common/mavlink.h"

void FMavlinkMsg_att_pos_mocap::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_att_pos_mocap_pack(systemId, componentId, &msg,  time_usec, q, x, y, z, covariance);
}

void FMavlinkMsg_att_pos_mocap::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_att_pos_mocap::Deserialize(const mavlink_message_t& msg)
{

}

