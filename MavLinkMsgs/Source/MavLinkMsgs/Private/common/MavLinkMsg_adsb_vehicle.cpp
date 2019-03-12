 
#include "MavLinkMsg_adsb_vehicle.h"
#include "common/mavlink.h"



void FMavlinkMsg_adsb_vehicle::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_adsb_vehicle_pack(systemId, componentId, &msg,  ICAO_address, lat, lon, altitude_type, altitude, heading, hor_velocity, ver_velocity, (char*)callsign, emitter_type, tslc, flags, squawk);
}

void FMavlinkMsg_adsb_vehicle::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_adsb_vehicle::Deserialize(const mavlink_message_t& msg)
{

}

