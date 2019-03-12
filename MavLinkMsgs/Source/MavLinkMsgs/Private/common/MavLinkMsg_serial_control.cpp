 
#include "MavLinkMsg_serial_control.h"
#include "common/mavlink.h"



void FMavlinkMsg_serial_control::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_serial_control_pack(systemId, componentId, &msg,  device, flags, timeout, baudrate, count, (uint8_t*)data);
}

void FMavlinkMsg_serial_control::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_serial_control::Deserialize(const mavlink_message_t& msg)
{

}

