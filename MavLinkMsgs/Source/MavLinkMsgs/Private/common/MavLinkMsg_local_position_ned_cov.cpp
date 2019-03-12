 
#include "MavLinkMsg_local_position_ned_cov.h"
#include "common/mavlink.h"



void FMavlinkMsg_local_position_ned_cov::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_local_position_ned_cov_pack(systemId, componentId, &msg,  time_usec, estimator_type, x, y, z, vx, vy, vz, ax, ay, az, covariance);
}

void FMavlinkMsg_local_position_ned_cov::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_local_position_ned_cov::Deserialize(const mavlink_message_t& msg)
{

}

