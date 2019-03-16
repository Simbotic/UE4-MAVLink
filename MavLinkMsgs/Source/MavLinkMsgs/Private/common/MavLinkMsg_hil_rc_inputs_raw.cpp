 
#include "MavLinkMsg_hil_rc_inputs_raw.h"
#include "common/mavlink.h"



void FMavlinkMsg_hil_rc_inputs_raw::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_hil_rc_inputs_raw_pack(systemId, componentId, &msg,  time_usec, chan1_raw, chan2_raw, chan3_raw, chan4_raw, chan5_raw, chan6_raw, chan7_raw, chan8_raw, chan9_raw, chan10_raw, chan11_raw, chan12_raw, rssi);
}

void FMavlinkMsg_hil_rc_inputs_raw::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_hil_rc_inputs_raw::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_hil_rc_inputs_raw_get_time_usec(msg);
        chan1_raw = mavlink_msg_hil_rc_inputs_raw_get_chan1_raw(msg);
        chan2_raw = mavlink_msg_hil_rc_inputs_raw_get_chan2_raw(msg);
        chan3_raw = mavlink_msg_hil_rc_inputs_raw_get_chan3_raw(msg);
        chan4_raw = mavlink_msg_hil_rc_inputs_raw_get_chan4_raw(msg);
        chan5_raw = mavlink_msg_hil_rc_inputs_raw_get_chan5_raw(msg);
        chan6_raw = mavlink_msg_hil_rc_inputs_raw_get_chan6_raw(msg);
        chan7_raw = mavlink_msg_hil_rc_inputs_raw_get_chan7_raw(msg);
        chan8_raw = mavlink_msg_hil_rc_inputs_raw_get_chan8_raw(msg);
        chan9_raw = mavlink_msg_hil_rc_inputs_raw_get_chan9_raw(msg);
        chan10_raw = mavlink_msg_hil_rc_inputs_raw_get_chan10_raw(msg);
        chan11_raw = mavlink_msg_hil_rc_inputs_raw_get_chan11_raw(msg);
        chan12_raw = mavlink_msg_hil_rc_inputs_raw_get_chan12_raw(msg);
        rssi = mavlink_msg_hil_rc_inputs_raw_get_rssi(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_LEN? msg.len : MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

