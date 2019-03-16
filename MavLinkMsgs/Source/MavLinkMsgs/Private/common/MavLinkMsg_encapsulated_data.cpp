 
#include "MavLinkMsg_encapsulated_data.h"
#include "common/mavlink.h"



void FMavlinkMsg_encapsulated_data::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_encapsulated_data_pack(systemId, componentId, &msg,  seqnr, (uint8_t*)data);
}

void FMavlinkMsg_encapsulated_data::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_encapsulated_data::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        seqnr = mavlink_msg_encapsulated_data_get_seqnr(msg);
        data = mavlink_msg_encapsulated_data_get_data(msg, encapsulated_data->data);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_ENCAPSULATED_DATA_LEN? msg.len : MAVLINK_MSG_ID_ENCAPSULATED_DATA_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_ENCAPSULATED_DATA_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

