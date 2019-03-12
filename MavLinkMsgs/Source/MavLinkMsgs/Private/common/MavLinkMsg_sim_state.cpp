 
#include "MavLinkMsg_sim_state.h"
#include "common/mavlink.h"



void FMavlinkMsg_sim_state::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_sim_state_pack(systemId, componentId, &msg,  q1, q2, q3, q4, roll, pitch, yaw, xacc, yacc, zacc, xgyro, ygyro, zgyro, lat, lon, alt, std_dev_horz, std_dev_vert, vn, ve, vd);
}

void FMavlinkMsg_sim_state::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_sim_state::Deserialize(const mavlink_message_t& msg)
{

}

