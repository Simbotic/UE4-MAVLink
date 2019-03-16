 
#include "MavLinkMsg_cellular_status.h"
#include "common/mavlink.h"



void FMavlinkMsg_cellular_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_cellular_status_pack(systemId, componentId, &msg,  status, type, quality, mcc, mnc, lac, cid);
}

void FMavlinkMsg_cellular_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_cellular_status::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        cid = mavlink_msg_cellular_status_get_cid(msg);
        status = mavlink_msg_cellular_status_get_status(msg);
        mcc = mavlink_msg_cellular_status_get_mcc(msg);
        mnc = mavlink_msg_cellular_status_get_mnc(msg);
        lac = mavlink_msg_cellular_status_get_lac(msg);
        type = mavlink_msg_cellular_status_get_type(msg);
        quality = mavlink_msg_cellular_status_get_quality(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_CELLULAR_STATUS_LEN? msg.len : MAVLINK_MSG_ID_CELLULAR_STATUS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

