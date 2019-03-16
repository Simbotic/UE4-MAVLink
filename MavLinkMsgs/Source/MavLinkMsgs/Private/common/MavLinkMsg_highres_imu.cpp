 
#include "MavLinkMsg_highres_imu.h"
#include "common/mavlink.h"



void FMavlinkMsg_highres_imu::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_highres_imu_pack(systemId, componentId, &msg,  time_usec, xacc, yacc, zacc, xgyro, ygyro, zgyro, xmag, ymag, zmag, abs_pressure, diff_pressure, pressure_alt, temperature, fields_updated);
}

void FMavlinkMsg_highres_imu::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_highres_imu::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_highres_imu_get_time_usec(msg);
        xacc = mavlink_msg_highres_imu_get_xacc(msg);
        yacc = mavlink_msg_highres_imu_get_yacc(msg);
        zacc = mavlink_msg_highres_imu_get_zacc(msg);
        xgyro = mavlink_msg_highres_imu_get_xgyro(msg);
        ygyro = mavlink_msg_highres_imu_get_ygyro(msg);
        zgyro = mavlink_msg_highres_imu_get_zgyro(msg);
        xmag = mavlink_msg_highres_imu_get_xmag(msg);
        ymag = mavlink_msg_highres_imu_get_ymag(msg);
        zmag = mavlink_msg_highres_imu_get_zmag(msg);
        abs_pressure = mavlink_msg_highres_imu_get_abs_pressure(msg);
        diff_pressure = mavlink_msg_highres_imu_get_diff_pressure(msg);
        pressure_alt = mavlink_msg_highres_imu_get_pressure_alt(msg);
        temperature = mavlink_msg_highres_imu_get_temperature(msg);
        fields_updated = mavlink_msg_highres_imu_get_fields_updated(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_HIGHRES_IMU_LEN? msg.len : MAVLINK_MSG_ID_HIGHRES_IMU_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_HIGHRES_IMU_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

