 
#include "MavLinkMsg_hil_state_quaternion.h"
#include "common/mavlink.h"



void FMavlinkMsg_hil_state_quaternion::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_hil_state_quaternion_pack(systemId, componentId, &msg,  time_usec, attitude_quaternion, rollspeed, pitchspeed, yawspeed, lat, lon, alt, vx, vy, vz, ind_airspeed, true_airspeed, xacc, yacc, zacc);
}

void FMavlinkMsg_hil_state_quaternion::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_hil_state_quaternion::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_hil_state_quaternion_get_time_usec(msg);
        attitude_quaternion = mavlink_msg_hil_state_quaternion_get_attitude_quaternion(msg, hil_state_quaternion->attitude_quaternion);
        rollspeed = mavlink_msg_hil_state_quaternion_get_rollspeed(msg);
        pitchspeed = mavlink_msg_hil_state_quaternion_get_pitchspeed(msg);
        yawspeed = mavlink_msg_hil_state_quaternion_get_yawspeed(msg);
        lat = mavlink_msg_hil_state_quaternion_get_lat(msg);
        lon = mavlink_msg_hil_state_quaternion_get_lon(msg);
        alt = mavlink_msg_hil_state_quaternion_get_alt(msg);
        vx = mavlink_msg_hil_state_quaternion_get_vx(msg);
        vy = mavlink_msg_hil_state_quaternion_get_vy(msg);
        vz = mavlink_msg_hil_state_quaternion_get_vz(msg);
        ind_airspeed = mavlink_msg_hil_state_quaternion_get_ind_airspeed(msg);
        true_airspeed = mavlink_msg_hil_state_quaternion_get_true_airspeed(msg);
        xacc = mavlink_msg_hil_state_quaternion_get_xacc(msg);
        yacc = mavlink_msg_hil_state_quaternion_get_yacc(msg);
        zacc = mavlink_msg_hil_state_quaternion_get_zacc(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN? msg.len : MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

