#pragma once

#include "CoreMinimal.h"
#include "MavLink.h"
#include "MavLinkDelegates.h"
#include "MavLinkDispatch.generated.h"

struct __mavlink_message;

UCLASS(BlueprintType)
class MAVLINKMSGS_API UMavlinkDispatch : public UObject
{
    GENERATED_BODY()


public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_heartbeat, FMavlinkMsg_heartbeat, heartbeat );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_heartbeat FOnMavlinkMsg_heartbeat;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_sys_status, FMavlinkMsg_sys_status, sys_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_sys_status FOnMavlinkMsg_sys_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_system_time, FMavlinkMsg_system_time, system_time );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_system_time FOnMavlinkMsg_system_time;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_ping, FMavlinkMsg_ping, ping );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_ping FOnMavlinkMsg_ping;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_change_operator_control, FMavlinkMsg_change_operator_control, change_operator_control );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_change_operator_control FOnMavlinkMsg_change_operator_control;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_change_operator_control_ack, FMavlinkMsg_change_operator_control_ack, change_operator_control_ack );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_change_operator_control_ack FOnMavlinkMsg_change_operator_control_ack;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_auth_key, FMavlinkMsg_auth_key, auth_key );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_auth_key FOnMavlinkMsg_auth_key;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_set_mode, FMavlinkMsg_set_mode, set_mode );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_set_mode FOnMavlinkMsg_set_mode;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_param_request_read, FMavlinkMsg_param_request_read, param_request_read );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_param_request_read FOnMavlinkMsg_param_request_read;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_param_request_list, FMavlinkMsg_param_request_list, param_request_list );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_param_request_list FOnMavlinkMsg_param_request_list;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_param_value, FMavlinkMsg_param_value, param_value );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_param_value FOnMavlinkMsg_param_value;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_param_set, FMavlinkMsg_param_set, param_set );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_param_set FOnMavlinkMsg_param_set;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_gps_raw_int, FMavlinkMsg_gps_raw_int, gps_raw_int );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_gps_raw_int FOnMavlinkMsg_gps_raw_int;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_gps_status, FMavlinkMsg_gps_status, gps_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_gps_status FOnMavlinkMsg_gps_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_scaled_imu, FMavlinkMsg_scaled_imu, scaled_imu );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_scaled_imu FOnMavlinkMsg_scaled_imu;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_raw_imu, FMavlinkMsg_raw_imu, raw_imu );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_raw_imu FOnMavlinkMsg_raw_imu;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_raw_pressure, FMavlinkMsg_raw_pressure, raw_pressure );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_raw_pressure FOnMavlinkMsg_raw_pressure;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_scaled_pressure, FMavlinkMsg_scaled_pressure, scaled_pressure );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_scaled_pressure FOnMavlinkMsg_scaled_pressure;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_attitude, FMavlinkMsg_attitude, attitude );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_attitude FOnMavlinkMsg_attitude;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_attitude_quaternion, FMavlinkMsg_attitude_quaternion, attitude_quaternion );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_attitude_quaternion FOnMavlinkMsg_attitude_quaternion;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_local_position_ned, FMavlinkMsg_local_position_ned, local_position_ned );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_local_position_ned FOnMavlinkMsg_local_position_ned;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_global_position_int, FMavlinkMsg_global_position_int, global_position_int );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_global_position_int FOnMavlinkMsg_global_position_int;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_rc_channels_scaled, FMavlinkMsg_rc_channels_scaled, rc_channels_scaled );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_rc_channels_scaled FOnMavlinkMsg_rc_channels_scaled;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_rc_channels_raw, FMavlinkMsg_rc_channels_raw, rc_channels_raw );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_rc_channels_raw FOnMavlinkMsg_rc_channels_raw;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_servo_output_raw, FMavlinkMsg_servo_output_raw, servo_output_raw );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_servo_output_raw FOnMavlinkMsg_servo_output_raw;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_request_partial_list, FMavlinkMsg_mission_request_partial_list, mission_request_partial_list );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_request_partial_list FOnMavlinkMsg_mission_request_partial_list;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_write_partial_list, FMavlinkMsg_mission_write_partial_list, mission_write_partial_list );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_write_partial_list FOnMavlinkMsg_mission_write_partial_list;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_item, FMavlinkMsg_mission_item, mission_item );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_item FOnMavlinkMsg_mission_item;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_request, FMavlinkMsg_mission_request, mission_request );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_request FOnMavlinkMsg_mission_request;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_set_current, FMavlinkMsg_mission_set_current, mission_set_current );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_set_current FOnMavlinkMsg_mission_set_current;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_current, FMavlinkMsg_mission_current, mission_current );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_current FOnMavlinkMsg_mission_current;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_request_list, FMavlinkMsg_mission_request_list, mission_request_list );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_request_list FOnMavlinkMsg_mission_request_list;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_count, FMavlinkMsg_mission_count, mission_count );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_count FOnMavlinkMsg_mission_count;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_clear_all, FMavlinkMsg_mission_clear_all, mission_clear_all );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_clear_all FOnMavlinkMsg_mission_clear_all;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_item_reached, FMavlinkMsg_mission_item_reached, mission_item_reached );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_item_reached FOnMavlinkMsg_mission_item_reached;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_ack, FMavlinkMsg_mission_ack, mission_ack );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_ack FOnMavlinkMsg_mission_ack;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_set_gps_global_origin, FMavlinkMsg_set_gps_global_origin, set_gps_global_origin );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_set_gps_global_origin FOnMavlinkMsg_set_gps_global_origin;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_gps_global_origin, FMavlinkMsg_gps_global_origin, gps_global_origin );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_gps_global_origin FOnMavlinkMsg_gps_global_origin;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_param_map_rc, FMavlinkMsg_param_map_rc, param_map_rc );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_param_map_rc FOnMavlinkMsg_param_map_rc;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_request_int, FMavlinkMsg_mission_request_int, mission_request_int );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_request_int FOnMavlinkMsg_mission_request_int;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_safety_set_allowed_area, FMavlinkMsg_safety_set_allowed_area, safety_set_allowed_area );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_safety_set_allowed_area FOnMavlinkMsg_safety_set_allowed_area;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_safety_allowed_area, FMavlinkMsg_safety_allowed_area, safety_allowed_area );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_safety_allowed_area FOnMavlinkMsg_safety_allowed_area;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_attitude_quaternion_cov, FMavlinkMsg_attitude_quaternion_cov, attitude_quaternion_cov );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_attitude_quaternion_cov FOnMavlinkMsg_attitude_quaternion_cov;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_nav_controller_output, FMavlinkMsg_nav_controller_output, nav_controller_output );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_nav_controller_output FOnMavlinkMsg_nav_controller_output;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_global_position_int_cov, FMavlinkMsg_global_position_int_cov, global_position_int_cov );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_global_position_int_cov FOnMavlinkMsg_global_position_int_cov;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_local_position_ned_cov, FMavlinkMsg_local_position_ned_cov, local_position_ned_cov );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_local_position_ned_cov FOnMavlinkMsg_local_position_ned_cov;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_rc_channels, FMavlinkMsg_rc_channels, rc_channels );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_rc_channels FOnMavlinkMsg_rc_channels;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_request_data_stream, FMavlinkMsg_request_data_stream, request_data_stream );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_request_data_stream FOnMavlinkMsg_request_data_stream;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_data_stream, FMavlinkMsg_data_stream, data_stream );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_data_stream FOnMavlinkMsg_data_stream;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_manual_control, FMavlinkMsg_manual_control, manual_control );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_manual_control FOnMavlinkMsg_manual_control;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_rc_channels_override, FMavlinkMsg_rc_channels_override, rc_channels_override );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_rc_channels_override FOnMavlinkMsg_rc_channels_override;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mission_item_int, FMavlinkMsg_mission_item_int, mission_item_int );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mission_item_int FOnMavlinkMsg_mission_item_int;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_vfr_hud, FMavlinkMsg_vfr_hud, vfr_hud );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_vfr_hud FOnMavlinkMsg_vfr_hud;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_command_int, FMavlinkMsg_command_int, command_int );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_command_int FOnMavlinkMsg_command_int;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_command_long, FMavlinkMsg_command_long, command_long );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_command_long FOnMavlinkMsg_command_long;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_command_ack, FMavlinkMsg_command_ack, command_ack );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_command_ack FOnMavlinkMsg_command_ack;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_manual_setpoint, FMavlinkMsg_manual_setpoint, manual_setpoint );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_manual_setpoint FOnMavlinkMsg_manual_setpoint;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_set_attitude_target, FMavlinkMsg_set_attitude_target, set_attitude_target );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_set_attitude_target FOnMavlinkMsg_set_attitude_target;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_attitude_target, FMavlinkMsg_attitude_target, attitude_target );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_attitude_target FOnMavlinkMsg_attitude_target;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_set_position_target_local_ned, FMavlinkMsg_set_position_target_local_ned, set_position_target_local_ned );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_set_position_target_local_ned FOnMavlinkMsg_set_position_target_local_ned;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_position_target_local_ned, FMavlinkMsg_position_target_local_ned, position_target_local_ned );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_position_target_local_ned FOnMavlinkMsg_position_target_local_ned;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_set_position_target_global_int, FMavlinkMsg_set_position_target_global_int, set_position_target_global_int );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_set_position_target_global_int FOnMavlinkMsg_set_position_target_global_int;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_position_target_global_int, FMavlinkMsg_position_target_global_int, position_target_global_int );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_position_target_global_int FOnMavlinkMsg_position_target_global_int;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_local_position_ned_system_global_offset, FMavlinkMsg_local_position_ned_system_global_offset, local_position_ned_system_global_offset );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_local_position_ned_system_global_offset FOnMavlinkMsg_local_position_ned_system_global_offset;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_hil_state, FMavlinkMsg_hil_state, hil_state );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_hil_state FOnMavlinkMsg_hil_state;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_hil_controls, FMavlinkMsg_hil_controls, hil_controls );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_hil_controls FOnMavlinkMsg_hil_controls;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_hil_rc_inputs_raw, FMavlinkMsg_hil_rc_inputs_raw, hil_rc_inputs_raw );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_hil_rc_inputs_raw FOnMavlinkMsg_hil_rc_inputs_raw;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_hil_actuator_controls, FMavlinkMsg_hil_actuator_controls, hil_actuator_controls );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_hil_actuator_controls FOnMavlinkMsg_hil_actuator_controls;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_optical_flow, FMavlinkMsg_optical_flow, optical_flow );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_optical_flow FOnMavlinkMsg_optical_flow;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_global_vision_position_estimate, FMavlinkMsg_global_vision_position_estimate, global_vision_position_estimate );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_global_vision_position_estimate FOnMavlinkMsg_global_vision_position_estimate;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_vision_position_estimate, FMavlinkMsg_vision_position_estimate, vision_position_estimate );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_vision_position_estimate FOnMavlinkMsg_vision_position_estimate;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_vision_speed_estimate, FMavlinkMsg_vision_speed_estimate, vision_speed_estimate );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_vision_speed_estimate FOnMavlinkMsg_vision_speed_estimate;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_vicon_position_estimate, FMavlinkMsg_vicon_position_estimate, vicon_position_estimate );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_vicon_position_estimate FOnMavlinkMsg_vicon_position_estimate;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_highres_imu, FMavlinkMsg_highres_imu, highres_imu );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_highres_imu FOnMavlinkMsg_highres_imu;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_optical_flow_rad, FMavlinkMsg_optical_flow_rad, optical_flow_rad );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_optical_flow_rad FOnMavlinkMsg_optical_flow_rad;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_hil_sensor, FMavlinkMsg_hil_sensor, hil_sensor );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_hil_sensor FOnMavlinkMsg_hil_sensor;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_sim_state, FMavlinkMsg_sim_state, sim_state );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_sim_state FOnMavlinkMsg_sim_state;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_radio_status, FMavlinkMsg_radio_status, radio_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_radio_status FOnMavlinkMsg_radio_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_file_transfer_protocol, FMavlinkMsg_file_transfer_protocol, file_transfer_protocol );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_file_transfer_protocol FOnMavlinkMsg_file_transfer_protocol;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_timesync, FMavlinkMsg_timesync, timesync );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_timesync FOnMavlinkMsg_timesync;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_camera_trigger, FMavlinkMsg_camera_trigger, camera_trigger );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_camera_trigger FOnMavlinkMsg_camera_trigger;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_hil_gps, FMavlinkMsg_hil_gps, hil_gps );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_hil_gps FOnMavlinkMsg_hil_gps;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_hil_optical_flow, FMavlinkMsg_hil_optical_flow, hil_optical_flow );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_hil_optical_flow FOnMavlinkMsg_hil_optical_flow;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_hil_state_quaternion, FMavlinkMsg_hil_state_quaternion, hil_state_quaternion );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_hil_state_quaternion FOnMavlinkMsg_hil_state_quaternion;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_scaled_imu2, FMavlinkMsg_scaled_imu2, scaled_imu2 );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_scaled_imu2 FOnMavlinkMsg_scaled_imu2;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_log_request_list, FMavlinkMsg_log_request_list, log_request_list );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_log_request_list FOnMavlinkMsg_log_request_list;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_log_entry, FMavlinkMsg_log_entry, log_entry );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_log_entry FOnMavlinkMsg_log_entry;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_log_request_data, FMavlinkMsg_log_request_data, log_request_data );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_log_request_data FOnMavlinkMsg_log_request_data;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_log_data, FMavlinkMsg_log_data, log_data );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_log_data FOnMavlinkMsg_log_data;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_log_erase, FMavlinkMsg_log_erase, log_erase );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_log_erase FOnMavlinkMsg_log_erase;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_log_request_end, FMavlinkMsg_log_request_end, log_request_end );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_log_request_end FOnMavlinkMsg_log_request_end;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_gps_inject_data, FMavlinkMsg_gps_inject_data, gps_inject_data );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_gps_inject_data FOnMavlinkMsg_gps_inject_data;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_gps2_raw, FMavlinkMsg_gps2_raw, gps2_raw );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_gps2_raw FOnMavlinkMsg_gps2_raw;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_power_status, FMavlinkMsg_power_status, power_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_power_status FOnMavlinkMsg_power_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_serial_control, FMavlinkMsg_serial_control, serial_control );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_serial_control FOnMavlinkMsg_serial_control;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_gps_rtk, FMavlinkMsg_gps_rtk, gps_rtk );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_gps_rtk FOnMavlinkMsg_gps_rtk;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_gps2_rtk, FMavlinkMsg_gps2_rtk, gps2_rtk );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_gps2_rtk FOnMavlinkMsg_gps2_rtk;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_scaled_imu3, FMavlinkMsg_scaled_imu3, scaled_imu3 );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_scaled_imu3 FOnMavlinkMsg_scaled_imu3;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_data_transmission_handshake, FMavlinkMsg_data_transmission_handshake, data_transmission_handshake );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_data_transmission_handshake FOnMavlinkMsg_data_transmission_handshake;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_encapsulated_data, FMavlinkMsg_encapsulated_data, encapsulated_data );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_encapsulated_data FOnMavlinkMsg_encapsulated_data;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_distance_sensor, FMavlinkMsg_distance_sensor, distance_sensor );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_distance_sensor FOnMavlinkMsg_distance_sensor;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_terrain_request, FMavlinkMsg_terrain_request, terrain_request );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_terrain_request FOnMavlinkMsg_terrain_request;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_terrain_data, FMavlinkMsg_terrain_data, terrain_data );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_terrain_data FOnMavlinkMsg_terrain_data;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_terrain_check, FMavlinkMsg_terrain_check, terrain_check );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_terrain_check FOnMavlinkMsg_terrain_check;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_terrain_report, FMavlinkMsg_terrain_report, terrain_report );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_terrain_report FOnMavlinkMsg_terrain_report;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_scaled_pressure2, FMavlinkMsg_scaled_pressure2, scaled_pressure2 );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_scaled_pressure2 FOnMavlinkMsg_scaled_pressure2;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_att_pos_mocap, FMavlinkMsg_att_pos_mocap, att_pos_mocap );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_att_pos_mocap FOnMavlinkMsg_att_pos_mocap;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_set_actuator_control_target, FMavlinkMsg_set_actuator_control_target, set_actuator_control_target );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_set_actuator_control_target FOnMavlinkMsg_set_actuator_control_target;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_actuator_control_target, FMavlinkMsg_actuator_control_target, actuator_control_target );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_actuator_control_target FOnMavlinkMsg_actuator_control_target;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_altitude, FMavlinkMsg_altitude, altitude );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_altitude FOnMavlinkMsg_altitude;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_resource_request, FMavlinkMsg_resource_request, resource_request );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_resource_request FOnMavlinkMsg_resource_request;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_scaled_pressure3, FMavlinkMsg_scaled_pressure3, scaled_pressure3 );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_scaled_pressure3 FOnMavlinkMsg_scaled_pressure3;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_follow_target, FMavlinkMsg_follow_target, follow_target );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_follow_target FOnMavlinkMsg_follow_target;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_control_system_state, FMavlinkMsg_control_system_state, control_system_state );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_control_system_state FOnMavlinkMsg_control_system_state;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_battery_status, FMavlinkMsg_battery_status, battery_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_battery_status FOnMavlinkMsg_battery_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_autopilot_version, FMavlinkMsg_autopilot_version, autopilot_version );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_autopilot_version FOnMavlinkMsg_autopilot_version;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_landing_target, FMavlinkMsg_landing_target, landing_target );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_landing_target FOnMavlinkMsg_landing_target;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_estimator_status, FMavlinkMsg_estimator_status, estimator_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_estimator_status FOnMavlinkMsg_estimator_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_wind_cov, FMavlinkMsg_wind_cov, wind_cov );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_wind_cov FOnMavlinkMsg_wind_cov;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_gps_input, FMavlinkMsg_gps_input, gps_input );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_gps_input FOnMavlinkMsg_gps_input;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_gps_rtcm_data, FMavlinkMsg_gps_rtcm_data, gps_rtcm_data );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_gps_rtcm_data FOnMavlinkMsg_gps_rtcm_data;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_high_latency, FMavlinkMsg_high_latency, high_latency );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_high_latency FOnMavlinkMsg_high_latency;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_high_latency2, FMavlinkMsg_high_latency2, high_latency2 );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_high_latency2 FOnMavlinkMsg_high_latency2;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_vibration, FMavlinkMsg_vibration, vibration );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_vibration FOnMavlinkMsg_vibration;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_home_position, FMavlinkMsg_home_position, home_position );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_home_position FOnMavlinkMsg_home_position;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_set_home_position, FMavlinkMsg_set_home_position, set_home_position );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_set_home_position FOnMavlinkMsg_set_home_position;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_message_interval, FMavlinkMsg_message_interval, message_interval );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_message_interval FOnMavlinkMsg_message_interval;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_extended_sys_state, FMavlinkMsg_extended_sys_state, extended_sys_state );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_extended_sys_state FOnMavlinkMsg_extended_sys_state;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_adsb_vehicle, FMavlinkMsg_adsb_vehicle, adsb_vehicle );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_adsb_vehicle FOnMavlinkMsg_adsb_vehicle;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_collision, FMavlinkMsg_collision, collision );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_collision FOnMavlinkMsg_collision;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_v2_extension, FMavlinkMsg_v2_extension, v2_extension );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_v2_extension FOnMavlinkMsg_v2_extension;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_memory_vect, FMavlinkMsg_memory_vect, memory_vect );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_memory_vect FOnMavlinkMsg_memory_vect;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_debug_vect, FMavlinkMsg_debug_vect, debug_vect );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_debug_vect FOnMavlinkMsg_debug_vect;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_named_value_float, FMavlinkMsg_named_value_float, named_value_float );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_named_value_float FOnMavlinkMsg_named_value_float;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_named_value_int, FMavlinkMsg_named_value_int, named_value_int );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_named_value_int FOnMavlinkMsg_named_value_int;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_statustext, FMavlinkMsg_statustext, statustext );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_statustext FOnMavlinkMsg_statustext;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_debug, FMavlinkMsg_debug, debug );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_debug FOnMavlinkMsg_debug;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_setup_signing, FMavlinkMsg_setup_signing, setup_signing );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_setup_signing FOnMavlinkMsg_setup_signing;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_button_change, FMavlinkMsg_button_change, button_change );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_button_change FOnMavlinkMsg_button_change;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_play_tune, FMavlinkMsg_play_tune, play_tune );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_play_tune FOnMavlinkMsg_play_tune;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_camera_information, FMavlinkMsg_camera_information, camera_information );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_camera_information FOnMavlinkMsg_camera_information;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_camera_settings, FMavlinkMsg_camera_settings, camera_settings );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_camera_settings FOnMavlinkMsg_camera_settings;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_storage_information, FMavlinkMsg_storage_information, storage_information );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_storage_information FOnMavlinkMsg_storage_information;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_camera_capture_status, FMavlinkMsg_camera_capture_status, camera_capture_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_camera_capture_status FOnMavlinkMsg_camera_capture_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_camera_image_captured, FMavlinkMsg_camera_image_captured, camera_image_captured );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_camera_image_captured FOnMavlinkMsg_camera_image_captured;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_flight_information, FMavlinkMsg_flight_information, flight_information );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_flight_information FOnMavlinkMsg_flight_information;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_mount_orientation, FMavlinkMsg_mount_orientation, mount_orientation );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_mount_orientation FOnMavlinkMsg_mount_orientation;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_logging_data, FMavlinkMsg_logging_data, logging_data );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_logging_data FOnMavlinkMsg_logging_data;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_logging_data_acked, FMavlinkMsg_logging_data_acked, logging_data_acked );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_logging_data_acked FOnMavlinkMsg_logging_data_acked;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_logging_ack, FMavlinkMsg_logging_ack, logging_ack );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_logging_ack FOnMavlinkMsg_logging_ack;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_video_stream_information, FMavlinkMsg_video_stream_information, video_stream_information );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_video_stream_information FOnMavlinkMsg_video_stream_information;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_video_stream_status, FMavlinkMsg_video_stream_status, video_stream_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_video_stream_status FOnMavlinkMsg_video_stream_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_wifi_config_ap, FMavlinkMsg_wifi_config_ap, wifi_config_ap );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_wifi_config_ap FOnMavlinkMsg_wifi_config_ap;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_protocol_version, FMavlinkMsg_protocol_version, protocol_version );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_protocol_version FOnMavlinkMsg_protocol_version;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_uavcan_node_status, FMavlinkMsg_uavcan_node_status, uavcan_node_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_uavcan_node_status FOnMavlinkMsg_uavcan_node_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_uavcan_node_info, FMavlinkMsg_uavcan_node_info, uavcan_node_info );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_uavcan_node_info FOnMavlinkMsg_uavcan_node_info;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_param_ext_request_read, FMavlinkMsg_param_ext_request_read, param_ext_request_read );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_param_ext_request_read FOnMavlinkMsg_param_ext_request_read;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_param_ext_request_list, FMavlinkMsg_param_ext_request_list, param_ext_request_list );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_param_ext_request_list FOnMavlinkMsg_param_ext_request_list;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_param_ext_value, FMavlinkMsg_param_ext_value, param_ext_value );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_param_ext_value FOnMavlinkMsg_param_ext_value;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_param_ext_set, FMavlinkMsg_param_ext_set, param_ext_set );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_param_ext_set FOnMavlinkMsg_param_ext_set;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_param_ext_ack, FMavlinkMsg_param_ext_ack, param_ext_ack );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_param_ext_ack FOnMavlinkMsg_param_ext_ack;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_obstacle_distance, FMavlinkMsg_obstacle_distance, obstacle_distance );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_obstacle_distance FOnMavlinkMsg_obstacle_distance;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_odometry, FMavlinkMsg_odometry, odometry );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_odometry FOnMavlinkMsg_odometry;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_trajectory_representation_waypoints, FMavlinkMsg_trajectory_representation_waypoints, trajectory_representation_waypoints );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_trajectory_representation_waypoints FOnMavlinkMsg_trajectory_representation_waypoints;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_trajectory_representation_bezier, FMavlinkMsg_trajectory_representation_bezier, trajectory_representation_bezier );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_trajectory_representation_bezier FOnMavlinkMsg_trajectory_representation_bezier;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_cellular_status, FMavlinkMsg_cellular_status, cellular_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_cellular_status FOnMavlinkMsg_cellular_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_utm_global_position, FMavlinkMsg_utm_global_position, utm_global_position );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_utm_global_position FOnMavlinkMsg_utm_global_position;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_debug_float_array, FMavlinkMsg_debug_float_array, debug_float_array );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_debug_float_array FOnMavlinkMsg_debug_float_array;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_orbit_execution_status, FMavlinkMsg_orbit_execution_status, orbit_execution_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_orbit_execution_status FOnMavlinkMsg_orbit_execution_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_statustext_long, FMavlinkMsg_statustext_long, statustext_long );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_statustext_long FOnMavlinkMsg_statustext_long;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_smart_battery_info, FMavlinkMsg_smart_battery_info, smart_battery_info );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_smart_battery_info FOnMavlinkMsg_smart_battery_info;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_smart_battery_status, FMavlinkMsg_smart_battery_status, smart_battery_status );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_smart_battery_status FOnMavlinkMsg_smart_battery_status;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMsgDelegate_wheel_distance, FMavlinkMsg_wheel_distance, wheel_distance );
    UPROPERTY(BlueprintAssignable, Category="MavLink|Messages", meta = (AllowPrivateAccess = true))
    FOnMsgDelegate_wheel_distance FOnMavlinkMsg_wheel_distance;

    

    UMavlinkDispatch(){}
    ~UMavlinkDispatch(){}
    void DispatchMessage(const __mavlink_message& msg);


};
