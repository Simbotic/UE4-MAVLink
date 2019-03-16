 
#include "MavLinkMsg_data_transmission_handshake.h"
#include "common/mavlink.h"



void FMavlinkMsg_data_transmission_handshake::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_data_transmission_handshake_pack(systemId, componentId, &msg,  type, size, width, height, packets, payload, jpg_quality);
}

void FMavlinkMsg_data_transmission_handshake::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_data_transmission_handshake::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        size = mavlink_msg_data_transmission_handshake_get_size(msg);
        width = mavlink_msg_data_transmission_handshake_get_width(msg);
        height = mavlink_msg_data_transmission_handshake_get_height(msg);
        packets = mavlink_msg_data_transmission_handshake_get_packets(msg);
        type = mavlink_msg_data_transmission_handshake_get_type(msg);
        payload = mavlink_msg_data_transmission_handshake_get_payload(msg);
        jpg_quality = mavlink_msg_data_transmission_handshake_get_jpg_quality(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_LEN? msg.len : MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

