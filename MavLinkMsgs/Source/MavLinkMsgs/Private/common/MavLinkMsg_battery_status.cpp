 
#include "MavLinkMsg_battery_status.h"
#include "common/mavlink.h"

void FMavlinkMsg_battery_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_battery_status_pack(systemId, componentId, &msg,  id, battery_function, type, temperature, (uint16_t*)voltages, current_battery, current_consumed, energy_consumed, battery_remaining, time_remaining, charge_state);
}

void FMavlinkMsg_battery_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_battery_status::Deserialize(const mavlink_message_t& msg)
{

}

