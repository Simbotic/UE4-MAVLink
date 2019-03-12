 
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

}

