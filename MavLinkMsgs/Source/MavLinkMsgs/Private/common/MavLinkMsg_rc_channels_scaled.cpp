 
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
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_rc_channels_scaled::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_rc_channels_scaled_get_time_boot_ms(msg);
        chan1_scaled = mavlink_msg_rc_channels_scaled_get_chan1_scaled(msg);
        chan2_scaled = mavlink_msg_rc_channels_scaled_get_chan2_scaled(msg);
        chan3_scaled = mavlink_msg_rc_channels_scaled_get_chan3_scaled(msg);
        chan4_scaled = mavlink_msg_rc_channels_scaled_get_chan4_scaled(msg);
        chan5_scaled = mavlink_msg_rc_channels_scaled_get_chan5_scaled(msg);
        chan6_scaled = mavlink_msg_rc_channels_scaled_get_chan6_scaled(msg);
        chan7_scaled = mavlink_msg_rc_channels_scaled_get_chan7_scaled(msg);
        chan8_scaled = mavlink_msg_rc_channels_scaled_get_chan8_scaled(msg);
        port = mavlink_msg_rc_channels_scaled_get_port(msg);
        rssi = mavlink_msg_rc_channels_scaled_get_rssi(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_RC_CHANNELS_SCALED_LEN? msg.len : MAVLINK_MSG_ID_RC_CHANNELS_SCALED_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_RC_CHANNELS_SCALED_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

