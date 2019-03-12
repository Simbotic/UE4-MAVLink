 
#include "MavLinkMsg_terrain_report.h"
#include "common/mavlink.h"



void FMavlinkMsg_terrain_report::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_terrain_report_pack(systemId, componentId, &msg,  lat, lon, spacing, terrain_height, current_height, pending, loaded);
}

void FMavlinkMsg_terrain_report::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_terrain_report::Deserialize(const mavlink_message_t& msg)
{

}

