 
#include "MavLinkMsg_sys_status.h"
#include "common/mavlink.h"



void FMavlinkMsg_sys_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_sys_status_pack(systemId, componentId, &msg,  onboard_control_sensors_present, onboard_control_sensors_enabled, onboard_control_sensors_health, load, voltage_battery, current_battery, battery_remaining, drop_rate_comm, errors_comm, errors_count1, errors_count2, errors_count3, errors_count4);
}

void FMavlinkMsg_sys_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_sys_status::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        onboard_control_sensors_present = mavlink_msg_sys_status_get_onboard_control_sensors_present(msg);
        onboard_control_sensors_enabled = mavlink_msg_sys_status_get_onboard_control_sensors_enabled(msg);
        onboard_control_sensors_health = mavlink_msg_sys_status_get_onboard_control_sensors_health(msg);
        load = mavlink_msg_sys_status_get_load(msg);
        voltage_battery = mavlink_msg_sys_status_get_voltage_battery(msg);
        current_battery = mavlink_msg_sys_status_get_current_battery(msg);
        drop_rate_comm = mavlink_msg_sys_status_get_drop_rate_comm(msg);
        errors_comm = mavlink_msg_sys_status_get_errors_comm(msg);
        errors_count1 = mavlink_msg_sys_status_get_errors_count1(msg);
        errors_count2 = mavlink_msg_sys_status_get_errors_count2(msg);
        errors_count3 = mavlink_msg_sys_status_get_errors_count3(msg);
        errors_count4 = mavlink_msg_sys_status_get_errors_count4(msg);
        battery_remaining = mavlink_msg_sys_status_get_battery_remaining(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SYS_STATUS_LEN? msg.len : MAVLINK_MSG_ID_SYS_STATUS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SYS_STATUS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

