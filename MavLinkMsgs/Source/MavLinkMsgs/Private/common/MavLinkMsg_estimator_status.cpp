 
#include "MavLinkMsg_estimator_status.h"
#include "common/mavlink.h"



void FMavlinkMsg_estimator_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_estimator_status_pack(systemId, componentId, &msg,  time_usec, flags, vel_ratio, pos_horiz_ratio, pos_vert_ratio, mag_ratio, hagl_ratio, tas_ratio, pos_horiz_accuracy, pos_vert_accuracy);
}

void FMavlinkMsg_estimator_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_estimator_status::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_estimator_status_get_time_usec(msg);
        vel_ratio = mavlink_msg_estimator_status_get_vel_ratio(msg);
        pos_horiz_ratio = mavlink_msg_estimator_status_get_pos_horiz_ratio(msg);
        pos_vert_ratio = mavlink_msg_estimator_status_get_pos_vert_ratio(msg);
        mag_ratio = mavlink_msg_estimator_status_get_mag_ratio(msg);
        hagl_ratio = mavlink_msg_estimator_status_get_hagl_ratio(msg);
        tas_ratio = mavlink_msg_estimator_status_get_tas_ratio(msg);
        pos_horiz_accuracy = mavlink_msg_estimator_status_get_pos_horiz_accuracy(msg);
        pos_vert_accuracy = mavlink_msg_estimator_status_get_pos_vert_accuracy(msg);
        flags = mavlink_msg_estimator_status_get_flags(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_ESTIMATOR_STATUS_LEN? msg.len : MAVLINK_MSG_ID_ESTIMATOR_STATUS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_ESTIMATOR_STATUS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

