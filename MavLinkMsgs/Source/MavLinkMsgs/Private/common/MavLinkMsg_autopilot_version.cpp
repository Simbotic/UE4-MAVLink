 
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

}

