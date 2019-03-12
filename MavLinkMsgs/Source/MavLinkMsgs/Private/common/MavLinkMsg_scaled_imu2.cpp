 
#include "MavLinkMsg_scaled_imu2.h"
#include "common/mavlink.h"



void FMavlinkMsg_scaled_imu2::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_scaled_imu2_pack(systemId, componentId, &msg,  time_boot_ms, xacc, yacc, zacc, xgyro, ygyro, zgyro, xmag, ymag, zmag);
}

void FMavlinkMsg_scaled_imu2::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_scaled_imu2::Deserialize(const mavlink_message_t& msg)
{

}

