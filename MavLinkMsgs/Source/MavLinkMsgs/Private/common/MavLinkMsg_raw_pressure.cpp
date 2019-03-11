 
#include "MavLinkMsg_raw_pressure.h"
#include "common/mavlink.h"

void FMavlinkMsg_raw_pressure::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_raw_pressure_pack(systemId, componentId, &msg,  time_usec, press_abs, press_diff1, press_diff2, temperature);
}

void FMavlinkMsg_raw_pressure::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_raw_pressure::Deserialize(const mavlink_message_t& msg)
{

}

