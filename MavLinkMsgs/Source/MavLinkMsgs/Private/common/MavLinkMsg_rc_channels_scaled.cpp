 
#include "MavLinkMsg_rc_channels_scaled.h"
#include "common/mavlink.h"

void FMavlinkMsg_rc_channels_scaled::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_rc_channels_scaled_pack(systemId, componentId, &msg,  time_boot_ms, port, chan1_scaled, chan2_scaled, chan3_scaled, chan4_scaled, chan5_scaled, chan6_scaled, chan7_scaled, chan8_scaled, rssi);
}

void FMavlinkMsg_rc_channels_scaled::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_rc_channels_scaled::Deserialize(const mavlink_message_t& msg)
{

}

