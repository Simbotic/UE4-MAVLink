 
#include "MavLinkMsg_rc_channels_raw.h"
#include "common/mavlink.h"



void FMavlinkMsg_rc_channels_raw::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_rc_channels_raw_pack(systemId, componentId, &msg,  time_boot_ms, port, chan1_raw, chan2_raw, chan3_raw, chan4_raw, chan5_raw, chan6_raw, chan7_raw, chan8_raw, rssi);
}

void FMavlinkMsg_rc_channels_raw::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_rc_channels_raw::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_rc_channels_raw_get_time_boot_ms(msg);
        chan1_raw = mavlink_msg_rc_channels_raw_get_chan1_raw(msg);
        chan2_raw = mavlink_msg_rc_channels_raw_get_chan2_raw(msg);
        chan3_raw = mavlink_msg_rc_channels_raw_get_chan3_raw(msg);
        chan4_raw = mavlink_msg_rc_channels_raw_get_chan4_raw(msg);
        chan5_raw = mavlink_msg_rc_channels_raw_get_chan5_raw(msg);
        chan6_raw = mavlink_msg_rc_channels_raw_get_chan6_raw(msg);
        chan7_raw = mavlink_msg_rc_channels_raw_get_chan7_raw(msg);
        chan8_raw = mavlink_msg_rc_channels_raw_get_chan8_raw(msg);
        port = mavlink_msg_rc_channels_raw_get_port(msg);
        rssi = mavlink_msg_rc_channels_raw_get_rssi(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_RC_CHANNELS_RAW_LEN? msg.len : MAVLINK_MSG_ID_RC_CHANNELS_RAW_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_RC_CHANNELS_RAW_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

