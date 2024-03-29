 
#include "MavLinkMsg_scaled_imu3.h"
#include "common/mavlink.h"



void FMavlinkMsg_scaled_imu3::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_scaled_imu3_pack(systemId, componentId, &msg,  time_boot_ms, xacc, yacc, zacc, xgyro, ygyro, zgyro, xmag, ymag, zmag);
}

void FMavlinkMsg_scaled_imu3::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_scaled_imu3::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_scaled_imu3_get_time_boot_ms(msg);
        xacc = mavlink_msg_scaled_imu3_get_xacc(msg);
        yacc = mavlink_msg_scaled_imu3_get_yacc(msg);
        zacc = mavlink_msg_scaled_imu3_get_zacc(msg);
        xgyro = mavlink_msg_scaled_imu3_get_xgyro(msg);
        ygyro = mavlink_msg_scaled_imu3_get_ygyro(msg);
        zgyro = mavlink_msg_scaled_imu3_get_zgyro(msg);
        xmag = mavlink_msg_scaled_imu3_get_xmag(msg);
        ymag = mavlink_msg_scaled_imu3_get_ymag(msg);
        zmag = mavlink_msg_scaled_imu3_get_zmag(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SCALED_IMU3_LEN? msg.len : MAVLINK_MSG_ID_SCALED_IMU3_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SCALED_IMU3_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

