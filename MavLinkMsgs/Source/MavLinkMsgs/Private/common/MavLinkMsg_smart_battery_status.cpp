 
#include "MavLinkMsg_smart_battery_status.h"
#include "common/mavlink.h"



void FMavlinkMsg_smart_battery_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_smart_battery_status_pack(systemId, componentId, &msg,  id, capacity_remaining, current, temperature, fault_bitmask, time_remaining, cell_offset, (uint16_t*)voltages);
}

void FMavlinkMsg_smart_battery_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_smart_battery_status::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        fault_bitmask = mavlink_msg_smart_battery_status_get_fault_bitmask(msg);
        time_remaining = mavlink_msg_smart_battery_status_get_time_remaining(msg);
        id = mavlink_msg_smart_battery_status_get_id(msg);
        capacity_remaining = mavlink_msg_smart_battery_status_get_capacity_remaining(msg);
        current = mavlink_msg_smart_battery_status_get_current(msg);
        temperature = mavlink_msg_smart_battery_status_get_temperature(msg);
        cell_offset = mavlink_msg_smart_battery_status_get_cell_offset(msg);
        voltages = mavlink_msg_smart_battery_status_get_voltages(msg, smart_battery_status->voltages);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SMART_BATTERY_STATUS_LEN? msg.len : MAVLINK_MSG_ID_SMART_BATTERY_STATUS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SMART_BATTERY_STATUS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

