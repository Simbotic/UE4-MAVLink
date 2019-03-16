 
#include "MavLinkMsg_hil_state.h"
#include "common/mavlink.h"



void FMavlinkMsg_hil_state::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_hil_state_pack(systemId, componentId, &msg,  time_usec, roll, pitch, yaw, rollspeed, pitchspeed, yawspeed, lat, lon, alt, vx, vy, vz, xacc, yacc, zacc);
}

void FMavlinkMsg_hil_state::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_hil_state::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_hil_state_get_time_usec(msg);
        roll = mavlink_msg_hil_state_get_roll(msg);
        pitch = mavlink_msg_hil_state_get_pitch(msg);
        yaw = mavlink_msg_hil_state_get_yaw(msg);
        rollspeed = mavlink_msg_hil_state_get_rollspeed(msg);
        pitchspeed = mavlink_msg_hil_state_get_pitchspeed(msg);
        yawspeed = mavlink_msg_hil_state_get_yawspeed(msg);
        lat = mavlink_msg_hil_state_get_lat(msg);
        lon = mavlink_msg_hil_state_get_lon(msg);
        alt = mavlink_msg_hil_state_get_alt(msg);
        vx = mavlink_msg_hil_state_get_vx(msg);
        vy = mavlink_msg_hil_state_get_vy(msg);
        vz = mavlink_msg_hil_state_get_vz(msg);
        xacc = mavlink_msg_hil_state_get_xacc(msg);
        yacc = mavlink_msg_hil_state_get_yacc(msg);
        zacc = mavlink_msg_hil_state_get_zacc(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_HIL_STATE_LEN? msg.len : MAVLINK_MSG_ID_HIL_STATE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_HIL_STATE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

