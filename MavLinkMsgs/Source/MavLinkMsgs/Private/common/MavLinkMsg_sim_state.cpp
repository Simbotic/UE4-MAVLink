 
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
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        q1 = mavlink_msg_sim_state_get_q1(msg);
        q2 = mavlink_msg_sim_state_get_q2(msg);
        q3 = mavlink_msg_sim_state_get_q3(msg);
        q4 = mavlink_msg_sim_state_get_q4(msg);
        roll = mavlink_msg_sim_state_get_roll(msg);
        pitch = mavlink_msg_sim_state_get_pitch(msg);
        yaw = mavlink_msg_sim_state_get_yaw(msg);
        xacc = mavlink_msg_sim_state_get_xacc(msg);
        yacc = mavlink_msg_sim_state_get_yacc(msg);
        zacc = mavlink_msg_sim_state_get_zacc(msg);
        xgyro = mavlink_msg_sim_state_get_xgyro(msg);
        ygyro = mavlink_msg_sim_state_get_ygyro(msg);
        zgyro = mavlink_msg_sim_state_get_zgyro(msg);
        lat = mavlink_msg_sim_state_get_lat(msg);
        lon = mavlink_msg_sim_state_get_lon(msg);
        alt = mavlink_msg_sim_state_get_alt(msg);
        std_dev_horz = mavlink_msg_sim_state_get_std_dev_horz(msg);
        std_dev_vert = mavlink_msg_sim_state_get_std_dev_vert(msg);
        vn = mavlink_msg_sim_state_get_vn(msg);
        ve = mavlink_msg_sim_state_get_ve(msg);
        vd = mavlink_msg_sim_state_get_vd(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SIM_STATE_LEN? msg.len : MAVLINK_MSG_ID_SIM_STATE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SIM_STATE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

