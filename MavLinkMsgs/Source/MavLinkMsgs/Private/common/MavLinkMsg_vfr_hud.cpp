 
#include "MavLinkMsg_vfr_hud.h"
#include "common/mavlink.h"

void FMavlinkMsg_vfr_hud::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_vfr_hud_pack(systemId, componentId, &msg,  airspeed, groundspeed, heading, throttle, alt, climb);
}

void FMavlinkMsg_vfr_hud::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_vfr_hud::Deserialize(const mavlink_message_t& msg)
{

}

