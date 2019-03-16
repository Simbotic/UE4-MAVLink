 
#include "MavLinkMsg_radio_status.h"
#include "common/mavlink.h"



void FMavlinkMsg_radio_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_radio_status_pack(systemId, componentId, &msg,  rssi, remrssi, txbuf, noise, remnoise, rxerrors, fixed);
}

void FMavlinkMsg_radio_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_radio_status::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        rxerrors = mavlink_msg_radio_status_get_rxerrors(msg);
        fixed = mavlink_msg_radio_status_get_fixed(msg);
        rssi = mavlink_msg_radio_status_get_rssi(msg);
        remrssi = mavlink_msg_radio_status_get_remrssi(msg);
        txbuf = mavlink_msg_radio_status_get_txbuf(msg);
        noise = mavlink_msg_radio_status_get_noise(msg);
        remnoise = mavlink_msg_radio_status_get_remnoise(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_RADIO_STATUS_LEN? msg.len : MAVLINK_MSG_ID_RADIO_STATUS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_RADIO_STATUS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

