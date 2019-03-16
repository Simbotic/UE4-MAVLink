 
#include "MavLinkMsg_gps2_rtk.h"
#include "common/mavlink.h"



void FMavlinkMsg_gps2_rtk::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_gps2_rtk_pack(systemId, componentId, &msg,  time_last_baseline_ms, rtk_receiver_id, wn, tow, rtk_health, rtk_rate, nsats, baseline_coords_type, baseline_a_mm, baseline_b_mm, baseline_c_mm, accuracy, iar_num_hypotheses);
}

void FMavlinkMsg_gps2_rtk::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_gps2_rtk::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_last_baseline_ms = mavlink_msg_gps2_rtk_get_time_last_baseline_ms(msg);
        tow = mavlink_msg_gps2_rtk_get_tow(msg);
        baseline_a_mm = mavlink_msg_gps2_rtk_get_baseline_a_mm(msg);
        baseline_b_mm = mavlink_msg_gps2_rtk_get_baseline_b_mm(msg);
        baseline_c_mm = mavlink_msg_gps2_rtk_get_baseline_c_mm(msg);
        accuracy = mavlink_msg_gps2_rtk_get_accuracy(msg);
        iar_num_hypotheses = mavlink_msg_gps2_rtk_get_iar_num_hypotheses(msg);
        wn = mavlink_msg_gps2_rtk_get_wn(msg);
        rtk_receiver_id = mavlink_msg_gps2_rtk_get_rtk_receiver_id(msg);
        rtk_health = mavlink_msg_gps2_rtk_get_rtk_health(msg);
        rtk_rate = mavlink_msg_gps2_rtk_get_rtk_rate(msg);
        nsats = mavlink_msg_gps2_rtk_get_nsats(msg);
        baseline_coords_type = mavlink_msg_gps2_rtk_get_baseline_coords_type(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_GPS2_RTK_LEN? msg.len : MAVLINK_MSG_ID_GPS2_RTK_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_GPS2_RTK_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

