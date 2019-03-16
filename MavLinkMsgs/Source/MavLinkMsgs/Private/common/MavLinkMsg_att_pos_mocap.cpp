 
#include "MavLinkMsg_att_pos_mocap.h"
#include "common/mavlink.h"



void FMavlinkMsg_att_pos_mocap::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_att_pos_mocap_pack(systemId, componentId, &msg,  time_usec, q, x, y, z, covariance);
}

void FMavlinkMsg_att_pos_mocap::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_att_pos_mocap::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_att_pos_mocap_get_time_usec(msg);
        q = mavlink_msg_att_pos_mocap_get_q(msg, att_pos_mocap->q);
        x = mavlink_msg_att_pos_mocap_get_x(msg);
        y = mavlink_msg_att_pos_mocap_get_y(msg);
        z = mavlink_msg_att_pos_mocap_get_z(msg);
        covariance = mavlink_msg_att_pos_mocap_get_covariance(msg, att_pos_mocap->covariance);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN? msg.len : MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_ATT_POS_MOCAP_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

