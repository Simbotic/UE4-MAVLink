 
#include "MavLinkMsg_autopilot_version.h"
#include "common/mavlink.h"



void FMavlinkMsg_autopilot_version::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_autopilot_version_pack(systemId, componentId, &msg,  capabilities, flight_sw_version, middleware_sw_version, os_sw_version, board_version, (uint8_t*)flight_custom_version, (uint8_t*)middleware_custom_version, (uint8_t*)os_custom_version, vendor_id, product_id, uid, (uint8_t*)uid2);
}

void FMavlinkMsg_autopilot_version::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_autopilot_version::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        capabilities = mavlink_msg_autopilot_version_get_capabilities(msg);
        uid = mavlink_msg_autopilot_version_get_uid(msg);
        flight_sw_version = mavlink_msg_autopilot_version_get_flight_sw_version(msg);
        middleware_sw_version = mavlink_msg_autopilot_version_get_middleware_sw_version(msg);
        os_sw_version = mavlink_msg_autopilot_version_get_os_sw_version(msg);
        board_version = mavlink_msg_autopilot_version_get_board_version(msg);
        vendor_id = mavlink_msg_autopilot_version_get_vendor_id(msg);
        product_id = mavlink_msg_autopilot_version_get_product_id(msg);
        flight_custom_version = mavlink_msg_autopilot_version_get_flight_custom_version(msg, autopilot_version->flight_custom_version);
        middleware_custom_version = mavlink_msg_autopilot_version_get_middleware_custom_version(msg, autopilot_version->middleware_custom_version);
        os_custom_version = mavlink_msg_autopilot_version_get_os_custom_version(msg, autopilot_version->os_custom_version);
        uid2 = mavlink_msg_autopilot_version_get_uid2(msg, autopilot_version->uid2);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_AUTOPILOT_VERSION_LEN? msg.len : MAVLINK_MSG_ID_AUTOPILOT_VERSION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_AUTOPILOT_VERSION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

