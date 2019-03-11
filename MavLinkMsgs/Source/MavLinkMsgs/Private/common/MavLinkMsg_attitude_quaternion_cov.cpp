 
#include "MavLinkMsg_attitude_quaternion_cov.h"
#include "common/mavlink.h"

void FMavlinkMsg_attitude_quaternion_cov::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_attitude_quaternion_cov_pack(systemId, componentId, &msg,  time_usec, q, rollspeed, pitchspeed, yawspeed, covariance);
}

void FMavlinkMsg_attitude_quaternion_cov::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_attitude_quaternion_cov::Deserialize(const mavlink_message_t& msg)
{

}

