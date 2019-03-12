 
#include "MavLinkMsg_rc_channels_override.h"
#include "common/mavlink.h"



void FMavlinkMsg_rc_channels_override::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_rc_channels_override_pack(systemId, componentId, &msg,  target_system, target_component, chan1_raw, chan2_raw, chan3_raw, chan4_raw, chan5_raw, chan6_raw, chan7_raw, chan8_raw, chan9_raw, chan10_raw, chan11_raw, chan12_raw, chan13_raw, chan14_raw, chan15_raw, chan16_raw, chan17_raw, chan18_raw);
}

void FMavlinkMsg_rc_channels_override::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_rc_channels_override::Deserialize(const mavlink_message_t& msg)
{

}

