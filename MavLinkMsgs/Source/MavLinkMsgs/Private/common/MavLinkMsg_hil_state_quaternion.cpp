 
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
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_hil_state_quaternion::Deserialize(const mavlink_message_t& msg)
{

}

