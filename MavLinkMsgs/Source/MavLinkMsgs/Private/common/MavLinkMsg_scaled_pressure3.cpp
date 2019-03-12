 
#include "MavLinkMsg_scaled_pressure3.h"
#include "common/mavlink.h"



void FMavlinkMsg_scaled_pressure3::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_scaled_pressure3_pack(systemId, componentId, &msg,  time_boot_ms, press_abs, press_diff, temperature);
}

void FMavlinkMsg_scaled_pressure3::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_scaled_pressure3::Deserialize(const mavlink_message_t& msg)
{

}

