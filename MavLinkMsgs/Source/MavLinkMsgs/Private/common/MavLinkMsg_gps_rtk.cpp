 
#include "MavLinkMsg_gps_rtk.h"
#include "common/mavlink.h"



void FMavlinkMsg_gps_rtk::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_gps_rtk_pack(systemId, componentId, &msg,  time_last_baseline_ms, rtk_receiver_id, wn, tow, rtk_health, rtk_rate, nsats, baseline_coords_type, baseline_a_mm, baseline_b_mm, baseline_c_mm, accuracy, iar_num_hypotheses);
}

void FMavlinkMsg_gps_rtk::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_gps_rtk::Deserialize(const mavlink_message_t& msg)
{

}

