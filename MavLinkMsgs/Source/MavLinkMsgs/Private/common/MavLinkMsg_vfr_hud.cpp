 
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
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_vfr_hud::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        airspeed = mavlink_msg_vfr_hud_get_airspeed(msg);
        groundspeed = mavlink_msg_vfr_hud_get_groundspeed(msg);
        alt = mavlink_msg_vfr_hud_get_alt(msg);
        climb = mavlink_msg_vfr_hud_get_climb(msg);
        heading = mavlink_msg_vfr_hud_get_heading(msg);
        throttle = mavlink_msg_vfr_hud_get_throttle(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_VFR_HUD_LEN? msg.len : MAVLINK_MSG_ID_VFR_HUD_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_VFR_HUD_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

