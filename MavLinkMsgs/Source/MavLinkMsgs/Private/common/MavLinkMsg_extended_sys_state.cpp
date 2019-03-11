 
#include "MavLinkMsg_extended_sys_state.h"
#include "common/mavlink.h"

void FMavlinkMsg_extended_sys_state::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_extended_sys_state_pack(systemId, componentId, &msg,  vtol_state, landed_state);
}

void FMavlinkMsg_extended_sys_state::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_extended_sys_state::Deserialize(const mavlink_message_t& msg)
{

}

