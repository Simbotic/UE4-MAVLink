 
#include "MavLinkMsg_trajectory_representation_bezier.h"
#include "common/mavlink.h"

void FMavlinkMsg_trajectory_representation_bezier::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_trajectory_representation_bezier_pack(systemId, componentId, &msg,  time_usec, valid_points, pos_x, pos_y, pos_z, delta, pos_yaw);
}

void FMavlinkMsg_trajectory_representation_bezier::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_trajectory_representation_bezier::Deserialize(const mavlink_message_t& msg)
{

}
