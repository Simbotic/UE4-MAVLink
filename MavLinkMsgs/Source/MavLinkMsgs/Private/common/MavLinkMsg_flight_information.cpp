 
#include "MavLinkMsg_flight_information.h"
#include "common/mavlink.h"



void FMavlinkMsg_flight_information::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_flight_information_pack(systemId, componentId, &msg,  time_boot_ms, arming_time_utc, takeoff_time_utc, flight_uuid);
}

void FMavlinkMsg_flight_information::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_flight_information::Deserialize(const mavlink_message_t& msg)
{

}

