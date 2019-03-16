 
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
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        capacity_full_specification = mavlink_msg_smart_battery_info_get_capacity_full_specification(msg);
        capacity_full = mavlink_msg_smart_battery_info_get_capacity_full(msg);
        serial_number = mavlink_msg_smart_battery_info_get_serial_number(msg);
        cycle_count = mavlink_msg_smart_battery_info_get_cycle_count(msg);
        weight = mavlink_msg_smart_battery_info_get_weight(msg);
        discharge_minimum_voltage = mavlink_msg_smart_battery_info_get_discharge_minimum_voltage(msg);
        charging_minimum_voltage = mavlink_msg_smart_battery_info_get_charging_minimum_voltage(msg);
        resting_minimum_voltage = mavlink_msg_smart_battery_info_get_resting_minimum_voltage(msg);
        id = mavlink_msg_smart_battery_info_get_id(msg);
        device_name = mavlink_msg_smart_battery_info_get_device_name(msg, smart_battery_info->device_name);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SMART_BATTERY_INFO_LEN? msg.len : MAVLINK_MSG_ID_SMART_BATTERY_INFO_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SMART_BATTERY_INFO_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

