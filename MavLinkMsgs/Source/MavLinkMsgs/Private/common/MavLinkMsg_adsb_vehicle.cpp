 
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
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        ICAO_address = mavlink_msg_adsb_vehicle_get_ICAO_address(msg);
        lat = mavlink_msg_adsb_vehicle_get_lat(msg);
        lon = mavlink_msg_adsb_vehicle_get_lon(msg);
        altitude = mavlink_msg_adsb_vehicle_get_altitude(msg);
        heading = mavlink_msg_adsb_vehicle_get_heading(msg);
        hor_velocity = mavlink_msg_adsb_vehicle_get_hor_velocity(msg);
        ver_velocity = mavlink_msg_adsb_vehicle_get_ver_velocity(msg);
        flags = mavlink_msg_adsb_vehicle_get_flags(msg);
        squawk = mavlink_msg_adsb_vehicle_get_squawk(msg);
        altitude_type = mavlink_msg_adsb_vehicle_get_altitude_type(msg);
        callsign = mavlink_msg_adsb_vehicle_get_callsign(msg, adsb_vehicle->callsign);
        emitter_type = mavlink_msg_adsb_vehicle_get_emitter_type(msg);
        tslc = mavlink_msg_adsb_vehicle_get_tslc(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_ADSB_VEHICLE_LEN? msg.len : MAVLINK_MSG_ID_ADSB_VEHICLE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_ADSB_VEHICLE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

