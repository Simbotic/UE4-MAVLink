 
#include "MavLinkMsg_vibration.h"
#include "common/mavlink.h"



void FMavlinkMsg_vibration::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_vibration_pack(systemId, componentId, &msg,  time_usec, vibration_x, vibration_y, vibration_z, clipping_0, clipping_1, clipping_2);
}

void FMavlinkMsg_vibration::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_vibration::Deserialize(const mavlink_message_t& msg)
{

}

