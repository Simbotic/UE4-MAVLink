 
#include "MavLinkMsg_smart_battery_info.h"
#include "common/mavlink.h"



void FMavlinkMsg_smart_battery_info::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_smart_battery_info_pack(systemId, componentId, &msg,  id, capacity_full_specification, capacity_full, cycle_count, serial_number, (char*)device_name, weight, discharge_minimum_voltage, charging_minimum_voltage, resting_minimum_voltage);
}

void FMavlinkMsg_smart_battery_info::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_smart_battery_info::Deserialize(const mavlink_message_t& msg)
{

}

