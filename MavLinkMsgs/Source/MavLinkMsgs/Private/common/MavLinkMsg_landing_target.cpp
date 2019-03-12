 
#include "MavLinkMsg_landing_target.h"
#include "common/mavlink.h"



void FMavlinkMsg_landing_target::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_landing_target_pack(systemId, componentId, &msg,  time_usec, target_num, frame, angle_x, angle_y, distance, size_x, size_y, x, y, z, q, type, position_valid);
}

void FMavlinkMsg_landing_target::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_landing_target::Deserialize(const mavlink_message_t& msg)
{

}

