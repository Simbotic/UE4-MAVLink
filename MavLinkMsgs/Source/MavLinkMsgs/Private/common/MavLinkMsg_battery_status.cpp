 
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
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_battery_status::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        current_consumed = mavlink_msg_battery_status_get_current_consumed(msg);
        energy_consumed = mavlink_msg_battery_status_get_energy_consumed(msg);
        temperature = mavlink_msg_battery_status_get_temperature(msg);
        voltages = mavlink_msg_battery_status_get_voltages(msg, battery_status->voltages);
        current_battery = mavlink_msg_battery_status_get_current_battery(msg);
        id = mavlink_msg_battery_status_get_id(msg);
        battery_function = mavlink_msg_battery_status_get_battery_function(msg);
        type = mavlink_msg_battery_status_get_type(msg);
        battery_remaining = mavlink_msg_battery_status_get_battery_remaining(msg);
        time_remaining = mavlink_msg_battery_status_get_time_remaining(msg);
        charge_state = mavlink_msg_battery_status_get_charge_state(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_BATTERY_STATUS_LEN? msg.len : MAVLINK_MSG_ID_BATTERY_STATUS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_BATTERY_STATUS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

