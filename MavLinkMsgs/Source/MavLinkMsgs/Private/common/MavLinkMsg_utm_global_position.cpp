 
#include "MavLinkMsg_utm_global_position.h"
#include "common/mavlink.h"



void FMavlinkMsg_utm_global_position::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_utm_global_position_pack(systemId, componentId, &msg,  time, (uint8_t*)uas_id, lat, lon, alt, relative_alt, vx, vy, vz, h_acc, v_acc, vel_acc, next_lat, next_lon, next_alt, update_rate, flight_state, flags);
}

void FMavlinkMsg_utm_global_position::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_utm_global_position::Deserialize(const mavlink_message_t& msg)
{

}

