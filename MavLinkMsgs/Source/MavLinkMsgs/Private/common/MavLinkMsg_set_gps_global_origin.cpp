 
#include "MavLinkMsg_set_gps_global_origin.h"
#include "common/mavlink.h"

void FMavlinkMsg_set_gps_global_origin::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_set_gps_global_origin_pack(systemId, componentId, &msg,  target_system, latitude, longitude, altitude, time_usec);
}

void FMavlinkMsg_set_gps_global_origin::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_set_gps_global_origin::Deserialize(const mavlink_message_t& msg)
{

}

