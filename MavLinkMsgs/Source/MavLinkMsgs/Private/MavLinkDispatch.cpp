#pragma once

#include "MavLinkDispatch.h"
#include "mavlink_types.h"


void FMavlinkDispatch::DispatchMessage(const __mavlink_message& msg)
{

    switch(msg.msgid)
    {
        case FMavlinkMsg_heartbeat::MsgId:
            FMavlinkMsg_heartbeat msg_heartbeat;
            msg_heartbeat.Deserialize(msg);
            FOnMavlinkMsg_heartbeat.ExecuteIfBound(msg_heartbeat);
            break;
        case FMavlinkMsg_sys_status::MsgId:
            FMavlinkMsg_sys_status msg_sys_status;
            msg_sys_status.Deserialize(msg);
            FOnMavlinkMsg_sys_status.ExecuteIfBound(msg_sys_status);
            break;
        case FMavlinkMsg_system_time::MsgId:
            FMavlinkMsg_system_time msg_system_time;
            msg_system_time.Deserialize(msg);
            FOnMavlinkMsg_system_time.ExecuteIfBound(msg_system_time);
            break;
        case FMavlinkMsg_ping::MsgId:
            FMavlinkMsg_ping msg_ping;
            msg_ping.Deserialize(msg);
            FOnMavlinkMsg_ping.ExecuteIfBound(msg_ping);
            break;
        case FMavlinkMsg_change_operator_control::MsgId:
            FMavlinkMsg_change_operator_control msg_change_operator_control;
            msg_change_operator_control.Deserialize(msg);
            FOnMavlinkMsg_change_operator_control.ExecuteIfBound(msg_change_operator_control);
            break;
        case FMavlinkMsg_change_operator_control_ack::MsgId:
            FMavlinkMsg_change_operator_control_ack msg_change_operator_control_ack;
            msg_change_operator_control_ack.Deserialize(msg);
            FOnMavlinkMsg_change_operator_control_ack.ExecuteIfBound(msg_change_operator_control_ack);
            break;
        case FMavlinkMsg_auth_key::MsgId:
            FMavlinkMsg_auth_key msg_auth_key;
            msg_auth_key.Deserialize(msg);
            FOnMavlinkMsg_auth_key.ExecuteIfBound(msg_auth_key);
            break;
        case FMavlinkMsg_set_mode::MsgId:
            FMavlinkMsg_set_mode msg_set_mode;
            msg_set_mode.Deserialize(msg);
            FOnMavlinkMsg_set_mode.ExecuteIfBound(msg_set_mode);
            break;
        case FMavlinkMsg_param_request_read::MsgId:
            FMavlinkMsg_param_request_read msg_param_request_read;
            msg_param_request_read.Deserialize(msg);
            FOnMavlinkMsg_param_request_read.ExecuteIfBound(msg_param_request_read);
            break;
        case FMavlinkMsg_param_request_list::MsgId:
            FMavlinkMsg_param_request_list msg_param_request_list;
            msg_param_request_list.Deserialize(msg);
            FOnMavlinkMsg_param_request_list.ExecuteIfBound(msg_param_request_list);
            break;
        case FMavlinkMsg_param_value::MsgId:
            FMavlinkMsg_param_value msg_param_value;
            msg_param_value.Deserialize(msg);
            FOnMavlinkMsg_param_value.ExecuteIfBound(msg_param_value);
            break;
        case FMavlinkMsg_param_set::MsgId:
            FMavlinkMsg_param_set msg_param_set;
            msg_param_set.Deserialize(msg);
            FOnMavlinkMsg_param_set.ExecuteIfBound(msg_param_set);
            break;
        case FMavlinkMsg_gps_raw_int::MsgId:
            FMavlinkMsg_gps_raw_int msg_gps_raw_int;
            msg_gps_raw_int.Deserialize(msg);
            FOnMavlinkMsg_gps_raw_int.ExecuteIfBound(msg_gps_raw_int);
            break;
        case FMavlinkMsg_gps_status::MsgId:
            FMavlinkMsg_gps_status msg_gps_status;
            msg_gps_status.Deserialize(msg);
            FOnMavlinkMsg_gps_status.ExecuteIfBound(msg_gps_status);
            break;
        case FMavlinkMsg_scaled_imu::MsgId:
            FMavlinkMsg_scaled_imu msg_scaled_imu;
            msg_scaled_imu.Deserialize(msg);
            FOnMavlinkMsg_scaled_imu.ExecuteIfBound(msg_scaled_imu);
            break;
        case FMavlinkMsg_raw_imu::MsgId:
            FMavlinkMsg_raw_imu msg_raw_imu;
            msg_raw_imu.Deserialize(msg);
            FOnMavlinkMsg_raw_imu.ExecuteIfBound(msg_raw_imu);
            break;
        case FMavlinkMsg_raw_pressure::MsgId:
            FMavlinkMsg_raw_pressure msg_raw_pressure;
            msg_raw_pressure.Deserialize(msg);
            FOnMavlinkMsg_raw_pressure.ExecuteIfBound(msg_raw_pressure);
            break;
        case FMavlinkMsg_scaled_pressure::MsgId:
            FMavlinkMsg_scaled_pressure msg_scaled_pressure;
            msg_scaled_pressure.Deserialize(msg);
            FOnMavlinkMsg_scaled_pressure.ExecuteIfBound(msg_scaled_pressure);
            break;
        case FMavlinkMsg_attitude::MsgId:
            FMavlinkMsg_attitude msg_attitude;
            msg_attitude.Deserialize(msg);
            FOnMavlinkMsg_attitude.ExecuteIfBound(msg_attitude);
            break;
        case FMavlinkMsg_attitude_quaternion::MsgId:
            FMavlinkMsg_attitude_quaternion msg_attitude_quaternion;
            msg_attitude_quaternion.Deserialize(msg);
            FOnMavlinkMsg_attitude_quaternion.ExecuteIfBound(msg_attitude_quaternion);
            break;
        case FMavlinkMsg_local_position_ned::MsgId:
            FMavlinkMsg_local_position_ned msg_local_position_ned;
            msg_local_position_ned.Deserialize(msg);
            FOnMavlinkMsg_local_position_ned.ExecuteIfBound(msg_local_position_ned);
            break;
        case FMavlinkMsg_global_position_int::MsgId:
            FMavlinkMsg_global_position_int msg_global_position_int;
            msg_global_position_int.Deserialize(msg);
            FOnMavlinkMsg_global_position_int.ExecuteIfBound(msg_global_position_int);
            break;
        case FMavlinkMsg_rc_channels_scaled::MsgId:
            FMavlinkMsg_rc_channels_scaled msg_rc_channels_scaled;
            msg_rc_channels_scaled.Deserialize(msg);
            FOnMavlinkMsg_rc_channels_scaled.ExecuteIfBound(msg_rc_channels_scaled);
            break;
        case FMavlinkMsg_rc_channels_raw::MsgId:
            FMavlinkMsg_rc_channels_raw msg_rc_channels_raw;
            msg_rc_channels_raw.Deserialize(msg);
            FOnMavlinkMsg_rc_channels_raw.ExecuteIfBound(msg_rc_channels_raw);
            break;
        case FMavlinkMsg_servo_output_raw::MsgId:
            FMavlinkMsg_servo_output_raw msg_servo_output_raw;
            msg_servo_output_raw.Deserialize(msg);
            FOnMavlinkMsg_servo_output_raw.ExecuteIfBound(msg_servo_output_raw);
            break;
        case FMavlinkMsg_mission_request_partial_list::MsgId:
            FMavlinkMsg_mission_request_partial_list msg_mission_request_partial_list;
            msg_mission_request_partial_list.Deserialize(msg);
            FOnMavlinkMsg_mission_request_partial_list.ExecuteIfBound(msg_mission_request_partial_list);
            break;
        case FMavlinkMsg_mission_write_partial_list::MsgId:
            FMavlinkMsg_mission_write_partial_list msg_mission_write_partial_list;
            msg_mission_write_partial_list.Deserialize(msg);
            FOnMavlinkMsg_mission_write_partial_list.ExecuteIfBound(msg_mission_write_partial_list);
            break;
        case FMavlinkMsg_mission_item::MsgId:
            FMavlinkMsg_mission_item msg_mission_item;
            msg_mission_item.Deserialize(msg);
            FOnMavlinkMsg_mission_item.ExecuteIfBound(msg_mission_item);
            break;
        case FMavlinkMsg_mission_request::MsgId:
            FMavlinkMsg_mission_request msg_mission_request;
            msg_mission_request.Deserialize(msg);
            FOnMavlinkMsg_mission_request.ExecuteIfBound(msg_mission_request);
            break;
        case FMavlinkMsg_mission_set_current::MsgId:
            FMavlinkMsg_mission_set_current msg_mission_set_current;
            msg_mission_set_current.Deserialize(msg);
            FOnMavlinkMsg_mission_set_current.ExecuteIfBound(msg_mission_set_current);
            break;
        case FMavlinkMsg_mission_current::MsgId:
            FMavlinkMsg_mission_current msg_mission_current;
            msg_mission_current.Deserialize(msg);
            FOnMavlinkMsg_mission_current.ExecuteIfBound(msg_mission_current);
            break;
        case FMavlinkMsg_mission_request_list::MsgId:
            FMavlinkMsg_mission_request_list msg_mission_request_list;
            msg_mission_request_list.Deserialize(msg);
            FOnMavlinkMsg_mission_request_list.ExecuteIfBound(msg_mission_request_list);
            break;
        case FMavlinkMsg_mission_count::MsgId:
            FMavlinkMsg_mission_count msg_mission_count;
            msg_mission_count.Deserialize(msg);
            FOnMavlinkMsg_mission_count.ExecuteIfBound(msg_mission_count);
            break;
        case FMavlinkMsg_mission_clear_all::MsgId:
            FMavlinkMsg_mission_clear_all msg_mission_clear_all;
            msg_mission_clear_all.Deserialize(msg);
            FOnMavlinkMsg_mission_clear_all.ExecuteIfBound(msg_mission_clear_all);
            break;
        case FMavlinkMsg_mission_item_reached::MsgId:
            FMavlinkMsg_mission_item_reached msg_mission_item_reached;
            msg_mission_item_reached.Deserialize(msg);
            FOnMavlinkMsg_mission_item_reached.ExecuteIfBound(msg_mission_item_reached);
            break;
        case FMavlinkMsg_mission_ack::MsgId:
            FMavlinkMsg_mission_ack msg_mission_ack;
            msg_mission_ack.Deserialize(msg);
            FOnMavlinkMsg_mission_ack.ExecuteIfBound(msg_mission_ack);
            break;
        case FMavlinkMsg_set_gps_global_origin::MsgId:
            FMavlinkMsg_set_gps_global_origin msg_set_gps_global_origin;
            msg_set_gps_global_origin.Deserialize(msg);
            FOnMavlinkMsg_set_gps_global_origin.ExecuteIfBound(msg_set_gps_global_origin);
            break;
        case FMavlinkMsg_gps_global_origin::MsgId:
            FMavlinkMsg_gps_global_origin msg_gps_global_origin;
            msg_gps_global_origin.Deserialize(msg);
            FOnMavlinkMsg_gps_global_origin.ExecuteIfBound(msg_gps_global_origin);
            break;
        case FMavlinkMsg_param_map_rc::MsgId:
            FMavlinkMsg_param_map_rc msg_param_map_rc;
            msg_param_map_rc.Deserialize(msg);
            FOnMavlinkMsg_param_map_rc.ExecuteIfBound(msg_param_map_rc);
            break;
        case FMavlinkMsg_mission_request_int::MsgId:
            FMavlinkMsg_mission_request_int msg_mission_request_int;
            msg_mission_request_int.Deserialize(msg);
            FOnMavlinkMsg_mission_request_int.ExecuteIfBound(msg_mission_request_int);
            break;
        case FMavlinkMsg_safety_set_allowed_area::MsgId:
            FMavlinkMsg_safety_set_allowed_area msg_safety_set_allowed_area;
            msg_safety_set_allowed_area.Deserialize(msg);
            FOnMavlinkMsg_safety_set_allowed_area.ExecuteIfBound(msg_safety_set_allowed_area);
            break;
        case FMavlinkMsg_safety_allowed_area::MsgId:
            FMavlinkMsg_safety_allowed_area msg_safety_allowed_area;
            msg_safety_allowed_area.Deserialize(msg);
            FOnMavlinkMsg_safety_allowed_area.ExecuteIfBound(msg_safety_allowed_area);
            break;
        case FMavlinkMsg_attitude_quaternion_cov::MsgId:
            FMavlinkMsg_attitude_quaternion_cov msg_attitude_quaternion_cov;
            msg_attitude_quaternion_cov.Deserialize(msg);
            FOnMavlinkMsg_attitude_quaternion_cov.ExecuteIfBound(msg_attitude_quaternion_cov);
            break;
        case FMavlinkMsg_nav_controller_output::MsgId:
            FMavlinkMsg_nav_controller_output msg_nav_controller_output;
            msg_nav_controller_output.Deserialize(msg);
            FOnMavlinkMsg_nav_controller_output.ExecuteIfBound(msg_nav_controller_output);
            break;
        case FMavlinkMsg_global_position_int_cov::MsgId:
            FMavlinkMsg_global_position_int_cov msg_global_position_int_cov;
            msg_global_position_int_cov.Deserialize(msg);
            FOnMavlinkMsg_global_position_int_cov.ExecuteIfBound(msg_global_position_int_cov);
            break;
        case FMavlinkMsg_local_position_ned_cov::MsgId:
            FMavlinkMsg_local_position_ned_cov msg_local_position_ned_cov;
            msg_local_position_ned_cov.Deserialize(msg);
            FOnMavlinkMsg_local_position_ned_cov.ExecuteIfBound(msg_local_position_ned_cov);
            break;
        case FMavlinkMsg_rc_channels::MsgId:
            FMavlinkMsg_rc_channels msg_rc_channels;
            msg_rc_channels.Deserialize(msg);
            FOnMavlinkMsg_rc_channels.ExecuteIfBound(msg_rc_channels);
            break;
        case FMavlinkMsg_request_data_stream::MsgId:
            FMavlinkMsg_request_data_stream msg_request_data_stream;
            msg_request_data_stream.Deserialize(msg);
            FOnMavlinkMsg_request_data_stream.ExecuteIfBound(msg_request_data_stream);
            break;
        case FMavlinkMsg_data_stream::MsgId:
            FMavlinkMsg_data_stream msg_data_stream;
            msg_data_stream.Deserialize(msg);
            FOnMavlinkMsg_data_stream.ExecuteIfBound(msg_data_stream);
            break;
        case FMavlinkMsg_manual_control::MsgId:
            FMavlinkMsg_manual_control msg_manual_control;
            msg_manual_control.Deserialize(msg);
            FOnMavlinkMsg_manual_control.ExecuteIfBound(msg_manual_control);
            break;
        case FMavlinkMsg_rc_channels_override::MsgId:
            FMavlinkMsg_rc_channels_override msg_rc_channels_override;
            msg_rc_channels_override.Deserialize(msg);
            FOnMavlinkMsg_rc_channels_override.ExecuteIfBound(msg_rc_channels_override);
            break;
        case FMavlinkMsg_mission_item_int::MsgId:
            FMavlinkMsg_mission_item_int msg_mission_item_int;
            msg_mission_item_int.Deserialize(msg);
            FOnMavlinkMsg_mission_item_int.ExecuteIfBound(msg_mission_item_int);
            break;
        case FMavlinkMsg_vfr_hud::MsgId:
            FMavlinkMsg_vfr_hud msg_vfr_hud;
            msg_vfr_hud.Deserialize(msg);
            FOnMavlinkMsg_vfr_hud.ExecuteIfBound(msg_vfr_hud);
            break;
        case FMavlinkMsg_command_int::MsgId:
            FMavlinkMsg_command_int msg_command_int;
            msg_command_int.Deserialize(msg);
            FOnMavlinkMsg_command_int.ExecuteIfBound(msg_command_int);
            break;
        case FMavlinkMsg_command_long::MsgId:
            FMavlinkMsg_command_long msg_command_long;
            msg_command_long.Deserialize(msg);
            FOnMavlinkMsg_command_long.ExecuteIfBound(msg_command_long);
            break;
        case FMavlinkMsg_command_ack::MsgId:
            FMavlinkMsg_command_ack msg_command_ack;
            msg_command_ack.Deserialize(msg);
            FOnMavlinkMsg_command_ack.ExecuteIfBound(msg_command_ack);
            break;
        case FMavlinkMsg_manual_setpoint::MsgId:
            FMavlinkMsg_manual_setpoint msg_manual_setpoint;
            msg_manual_setpoint.Deserialize(msg);
            FOnMavlinkMsg_manual_setpoint.ExecuteIfBound(msg_manual_setpoint);
            break;
        case FMavlinkMsg_set_attitude_target::MsgId:
            FMavlinkMsg_set_attitude_target msg_set_attitude_target;
            msg_set_attitude_target.Deserialize(msg);
            FOnMavlinkMsg_set_attitude_target.ExecuteIfBound(msg_set_attitude_target);
            break;
        case FMavlinkMsg_attitude_target::MsgId:
            FMavlinkMsg_attitude_target msg_attitude_target;
            msg_attitude_target.Deserialize(msg);
            FOnMavlinkMsg_attitude_target.ExecuteIfBound(msg_attitude_target);
            break;
        case FMavlinkMsg_set_position_target_local_ned::MsgId:
            FMavlinkMsg_set_position_target_local_ned msg_set_position_target_local_ned;
            msg_set_position_target_local_ned.Deserialize(msg);
            FOnMavlinkMsg_set_position_target_local_ned.ExecuteIfBound(msg_set_position_target_local_ned);
            break;
        case FMavlinkMsg_position_target_local_ned::MsgId:
            FMavlinkMsg_position_target_local_ned msg_position_target_local_ned;
            msg_position_target_local_ned.Deserialize(msg);
            FOnMavlinkMsg_position_target_local_ned.ExecuteIfBound(msg_position_target_local_ned);
            break;
        case FMavlinkMsg_set_position_target_global_int::MsgId:
            FMavlinkMsg_set_position_target_global_int msg_set_position_target_global_int;
            msg_set_position_target_global_int.Deserialize(msg);
            FOnMavlinkMsg_set_position_target_global_int.ExecuteIfBound(msg_set_position_target_global_int);
            break;
        case FMavlinkMsg_position_target_global_int::MsgId:
            FMavlinkMsg_position_target_global_int msg_position_target_global_int;
            msg_position_target_global_int.Deserialize(msg);
            FOnMavlinkMsg_position_target_global_int.ExecuteIfBound(msg_position_target_global_int);
            break;
        case FMavlinkMsg_local_position_ned_system_global_offset::MsgId:
            FMavlinkMsg_local_position_ned_system_global_offset msg_local_position_ned_system_global_offset;
            msg_local_position_ned_system_global_offset.Deserialize(msg);
            FOnMavlinkMsg_local_position_ned_system_global_offset.ExecuteIfBound(msg_local_position_ned_system_global_offset);
            break;
        case FMavlinkMsg_hil_state::MsgId:
            FMavlinkMsg_hil_state msg_hil_state;
            msg_hil_state.Deserialize(msg);
            FOnMavlinkMsg_hil_state.ExecuteIfBound(msg_hil_state);
            break;
        case FMavlinkMsg_hil_controls::MsgId:
            FMavlinkMsg_hil_controls msg_hil_controls;
            msg_hil_controls.Deserialize(msg);
            FOnMavlinkMsg_hil_controls.ExecuteIfBound(msg_hil_controls);
            break;
        case FMavlinkMsg_hil_rc_inputs_raw::MsgId:
            FMavlinkMsg_hil_rc_inputs_raw msg_hil_rc_inputs_raw;
            msg_hil_rc_inputs_raw.Deserialize(msg);
            FOnMavlinkMsg_hil_rc_inputs_raw.ExecuteIfBound(msg_hil_rc_inputs_raw);
            break;
        case FMavlinkMsg_hil_actuator_controls::MsgId:
            FMavlinkMsg_hil_actuator_controls msg_hil_actuator_controls;
            msg_hil_actuator_controls.Deserialize(msg);
            FOnMavlinkMsg_hil_actuator_controls.ExecuteIfBound(msg_hil_actuator_controls);
            break;
        case FMavlinkMsg_optical_flow::MsgId:
            FMavlinkMsg_optical_flow msg_optical_flow;
            msg_optical_flow.Deserialize(msg);
            FOnMavlinkMsg_optical_flow.ExecuteIfBound(msg_optical_flow);
            break;
        case FMavlinkMsg_global_vision_position_estimate::MsgId:
            FMavlinkMsg_global_vision_position_estimate msg_global_vision_position_estimate;
            msg_global_vision_position_estimate.Deserialize(msg);
            FOnMavlinkMsg_global_vision_position_estimate.ExecuteIfBound(msg_global_vision_position_estimate);
            break;
        case FMavlinkMsg_vision_position_estimate::MsgId:
            FMavlinkMsg_vision_position_estimate msg_vision_position_estimate;
            msg_vision_position_estimate.Deserialize(msg);
            FOnMavlinkMsg_vision_position_estimate.ExecuteIfBound(msg_vision_position_estimate);
            break;
        case FMavlinkMsg_vision_speed_estimate::MsgId:
            FMavlinkMsg_vision_speed_estimate msg_vision_speed_estimate;
            msg_vision_speed_estimate.Deserialize(msg);
            FOnMavlinkMsg_vision_speed_estimate.ExecuteIfBound(msg_vision_speed_estimate);
            break;
        case FMavlinkMsg_vicon_position_estimate::MsgId:
            FMavlinkMsg_vicon_position_estimate msg_vicon_position_estimate;
            msg_vicon_position_estimate.Deserialize(msg);
            FOnMavlinkMsg_vicon_position_estimate.ExecuteIfBound(msg_vicon_position_estimate);
            break;
        case FMavlinkMsg_highres_imu::MsgId:
            FMavlinkMsg_highres_imu msg_highres_imu;
            msg_highres_imu.Deserialize(msg);
            FOnMavlinkMsg_highres_imu.ExecuteIfBound(msg_highres_imu);
            break;
        case FMavlinkMsg_optical_flow_rad::MsgId:
            FMavlinkMsg_optical_flow_rad msg_optical_flow_rad;
            msg_optical_flow_rad.Deserialize(msg);
            FOnMavlinkMsg_optical_flow_rad.ExecuteIfBound(msg_optical_flow_rad);
            break;
        case FMavlinkMsg_hil_sensor::MsgId:
            FMavlinkMsg_hil_sensor msg_hil_sensor;
            msg_hil_sensor.Deserialize(msg);
            FOnMavlinkMsg_hil_sensor.ExecuteIfBound(msg_hil_sensor);
            break;
        case FMavlinkMsg_sim_state::MsgId:
            FMavlinkMsg_sim_state msg_sim_state;
            msg_sim_state.Deserialize(msg);
            FOnMavlinkMsg_sim_state.ExecuteIfBound(msg_sim_state);
            break;
        case FMavlinkMsg_radio_status::MsgId:
            FMavlinkMsg_radio_status msg_radio_status;
            msg_radio_status.Deserialize(msg);
            FOnMavlinkMsg_radio_status.ExecuteIfBound(msg_radio_status);
            break;
        case FMavlinkMsg_file_transfer_protocol::MsgId:
            FMavlinkMsg_file_transfer_protocol msg_file_transfer_protocol;
            msg_file_transfer_protocol.Deserialize(msg);
            FOnMavlinkMsg_file_transfer_protocol.ExecuteIfBound(msg_file_transfer_protocol);
            break;
        case FMavlinkMsg_timesync::MsgId:
            FMavlinkMsg_timesync msg_timesync;
            msg_timesync.Deserialize(msg);
            FOnMavlinkMsg_timesync.ExecuteIfBound(msg_timesync);
            break;
        case FMavlinkMsg_camera_trigger::MsgId:
            FMavlinkMsg_camera_trigger msg_camera_trigger;
            msg_camera_trigger.Deserialize(msg);
            FOnMavlinkMsg_camera_trigger.ExecuteIfBound(msg_camera_trigger);
            break;
        case FMavlinkMsg_hil_gps::MsgId:
            FMavlinkMsg_hil_gps msg_hil_gps;
            msg_hil_gps.Deserialize(msg);
            FOnMavlinkMsg_hil_gps.ExecuteIfBound(msg_hil_gps);
            break;
        case FMavlinkMsg_hil_optical_flow::MsgId:
            FMavlinkMsg_hil_optical_flow msg_hil_optical_flow;
            msg_hil_optical_flow.Deserialize(msg);
            FOnMavlinkMsg_hil_optical_flow.ExecuteIfBound(msg_hil_optical_flow);
            break;
        case FMavlinkMsg_hil_state_quaternion::MsgId:
            FMavlinkMsg_hil_state_quaternion msg_hil_state_quaternion;
            msg_hil_state_quaternion.Deserialize(msg);
            FOnMavlinkMsg_hil_state_quaternion.ExecuteIfBound(msg_hil_state_quaternion);
            break;
        case FMavlinkMsg_scaled_imu2::MsgId:
            FMavlinkMsg_scaled_imu2 msg_scaled_imu2;
            msg_scaled_imu2.Deserialize(msg);
            FOnMavlinkMsg_scaled_imu2.ExecuteIfBound(msg_scaled_imu2);
            break;
        case FMavlinkMsg_log_request_list::MsgId:
            FMavlinkMsg_log_request_list msg_log_request_list;
            msg_log_request_list.Deserialize(msg);
            FOnMavlinkMsg_log_request_list.ExecuteIfBound(msg_log_request_list);
            break;
        case FMavlinkMsg_log_entry::MsgId:
            FMavlinkMsg_log_entry msg_log_entry;
            msg_log_entry.Deserialize(msg);
            FOnMavlinkMsg_log_entry.ExecuteIfBound(msg_log_entry);
            break;
        case FMavlinkMsg_log_request_data::MsgId:
            FMavlinkMsg_log_request_data msg_log_request_data;
            msg_log_request_data.Deserialize(msg);
            FOnMavlinkMsg_log_request_data.ExecuteIfBound(msg_log_request_data);
            break;
        case FMavlinkMsg_log_data::MsgId:
            FMavlinkMsg_log_data msg_log_data;
            msg_log_data.Deserialize(msg);
            FOnMavlinkMsg_log_data.ExecuteIfBound(msg_log_data);
            break;
        case FMavlinkMsg_log_erase::MsgId:
            FMavlinkMsg_log_erase msg_log_erase;
            msg_log_erase.Deserialize(msg);
            FOnMavlinkMsg_log_erase.ExecuteIfBound(msg_log_erase);
            break;
        case FMavlinkMsg_log_request_end::MsgId:
            FMavlinkMsg_log_request_end msg_log_request_end;
            msg_log_request_end.Deserialize(msg);
            FOnMavlinkMsg_log_request_end.ExecuteIfBound(msg_log_request_end);
            break;
        case FMavlinkMsg_gps_inject_data::MsgId:
            FMavlinkMsg_gps_inject_data msg_gps_inject_data;
            msg_gps_inject_data.Deserialize(msg);
            FOnMavlinkMsg_gps_inject_data.ExecuteIfBound(msg_gps_inject_data);
            break;
        case FMavlinkMsg_gps2_raw::MsgId:
            FMavlinkMsg_gps2_raw msg_gps2_raw;
            msg_gps2_raw.Deserialize(msg);
            FOnMavlinkMsg_gps2_raw.ExecuteIfBound(msg_gps2_raw);
            break;
        case FMavlinkMsg_power_status::MsgId:
            FMavlinkMsg_power_status msg_power_status;
            msg_power_status.Deserialize(msg);
            FOnMavlinkMsg_power_status.ExecuteIfBound(msg_power_status);
            break;
        case FMavlinkMsg_serial_control::MsgId:
            FMavlinkMsg_serial_control msg_serial_control;
            msg_serial_control.Deserialize(msg);
            FOnMavlinkMsg_serial_control.ExecuteIfBound(msg_serial_control);
            break;
        case FMavlinkMsg_gps_rtk::MsgId:
            FMavlinkMsg_gps_rtk msg_gps_rtk;
            msg_gps_rtk.Deserialize(msg);
            FOnMavlinkMsg_gps_rtk.ExecuteIfBound(msg_gps_rtk);
            break;
        case FMavlinkMsg_gps2_rtk::MsgId:
            FMavlinkMsg_gps2_rtk msg_gps2_rtk;
            msg_gps2_rtk.Deserialize(msg);
            FOnMavlinkMsg_gps2_rtk.ExecuteIfBound(msg_gps2_rtk);
            break;
        case FMavlinkMsg_scaled_imu3::MsgId:
            FMavlinkMsg_scaled_imu3 msg_scaled_imu3;
            msg_scaled_imu3.Deserialize(msg);
            FOnMavlinkMsg_scaled_imu3.ExecuteIfBound(msg_scaled_imu3);
            break;
        case FMavlinkMsg_data_transmission_handshake::MsgId:
            FMavlinkMsg_data_transmission_handshake msg_data_transmission_handshake;
            msg_data_transmission_handshake.Deserialize(msg);
            FOnMavlinkMsg_data_transmission_handshake.ExecuteIfBound(msg_data_transmission_handshake);
            break;
        case FMavlinkMsg_encapsulated_data::MsgId:
            FMavlinkMsg_encapsulated_data msg_encapsulated_data;
            msg_encapsulated_data.Deserialize(msg);
            FOnMavlinkMsg_encapsulated_data.ExecuteIfBound(msg_encapsulated_data);
            break;
        case FMavlinkMsg_distance_sensor::MsgId:
            FMavlinkMsg_distance_sensor msg_distance_sensor;
            msg_distance_sensor.Deserialize(msg);
            FOnMavlinkMsg_distance_sensor.ExecuteIfBound(msg_distance_sensor);
            break;
        case FMavlinkMsg_terrain_request::MsgId:
            FMavlinkMsg_terrain_request msg_terrain_request;
            msg_terrain_request.Deserialize(msg);
            FOnMavlinkMsg_terrain_request.ExecuteIfBound(msg_terrain_request);
            break;
        case FMavlinkMsg_terrain_data::MsgId:
            FMavlinkMsg_terrain_data msg_terrain_data;
            msg_terrain_data.Deserialize(msg);
            FOnMavlinkMsg_terrain_data.ExecuteIfBound(msg_terrain_data);
            break;
        case FMavlinkMsg_terrain_check::MsgId:
            FMavlinkMsg_terrain_check msg_terrain_check;
            msg_terrain_check.Deserialize(msg);
            FOnMavlinkMsg_terrain_check.ExecuteIfBound(msg_terrain_check);
            break;
        case FMavlinkMsg_terrain_report::MsgId:
            FMavlinkMsg_terrain_report msg_terrain_report;
            msg_terrain_report.Deserialize(msg);
            FOnMavlinkMsg_terrain_report.ExecuteIfBound(msg_terrain_report);
            break;
        case FMavlinkMsg_scaled_pressure2::MsgId:
            FMavlinkMsg_scaled_pressure2 msg_scaled_pressure2;
            msg_scaled_pressure2.Deserialize(msg);
            FOnMavlinkMsg_scaled_pressure2.ExecuteIfBound(msg_scaled_pressure2);
            break;
        case FMavlinkMsg_att_pos_mocap::MsgId:
            FMavlinkMsg_att_pos_mocap msg_att_pos_mocap;
            msg_att_pos_mocap.Deserialize(msg);
            FOnMavlinkMsg_att_pos_mocap.ExecuteIfBound(msg_att_pos_mocap);
            break;
        case FMavlinkMsg_set_actuator_control_target::MsgId:
            FMavlinkMsg_set_actuator_control_target msg_set_actuator_control_target;
            msg_set_actuator_control_target.Deserialize(msg);
            FOnMavlinkMsg_set_actuator_control_target.ExecuteIfBound(msg_set_actuator_control_target);
            break;
        case FMavlinkMsg_actuator_control_target::MsgId:
            FMavlinkMsg_actuator_control_target msg_actuator_control_target;
            msg_actuator_control_target.Deserialize(msg);
            FOnMavlinkMsg_actuator_control_target.ExecuteIfBound(msg_actuator_control_target);
            break;
        case FMavlinkMsg_altitude::MsgId:
            FMavlinkMsg_altitude msg_altitude;
            msg_altitude.Deserialize(msg);
            FOnMavlinkMsg_altitude.ExecuteIfBound(msg_altitude);
            break;
        case FMavlinkMsg_resource_request::MsgId:
            FMavlinkMsg_resource_request msg_resource_request;
            msg_resource_request.Deserialize(msg);
            FOnMavlinkMsg_resource_request.ExecuteIfBound(msg_resource_request);
            break;
        case FMavlinkMsg_scaled_pressure3::MsgId:
            FMavlinkMsg_scaled_pressure3 msg_scaled_pressure3;
            msg_scaled_pressure3.Deserialize(msg);
            FOnMavlinkMsg_scaled_pressure3.ExecuteIfBound(msg_scaled_pressure3);
            break;
        case FMavlinkMsg_follow_target::MsgId:
            FMavlinkMsg_follow_target msg_follow_target;
            msg_follow_target.Deserialize(msg);
            FOnMavlinkMsg_follow_target.ExecuteIfBound(msg_follow_target);
            break;
        case FMavlinkMsg_control_system_state::MsgId:
            FMavlinkMsg_control_system_state msg_control_system_state;
            msg_control_system_state.Deserialize(msg);
            FOnMavlinkMsg_control_system_state.ExecuteIfBound(msg_control_system_state);
            break;
        case FMavlinkMsg_battery_status::MsgId:
            FMavlinkMsg_battery_status msg_battery_status;
            msg_battery_status.Deserialize(msg);
            FOnMavlinkMsg_battery_status.ExecuteIfBound(msg_battery_status);
            break;
        case FMavlinkMsg_autopilot_version::MsgId:
            FMavlinkMsg_autopilot_version msg_autopilot_version;
            msg_autopilot_version.Deserialize(msg);
            FOnMavlinkMsg_autopilot_version.ExecuteIfBound(msg_autopilot_version);
            break;
        case FMavlinkMsg_landing_target::MsgId:
            FMavlinkMsg_landing_target msg_landing_target;
            msg_landing_target.Deserialize(msg);
            FOnMavlinkMsg_landing_target.ExecuteIfBound(msg_landing_target);
            break;
        case FMavlinkMsg_estimator_status::MsgId:
            FMavlinkMsg_estimator_status msg_estimator_status;
            msg_estimator_status.Deserialize(msg);
            FOnMavlinkMsg_estimator_status.ExecuteIfBound(msg_estimator_status);
            break;
        case FMavlinkMsg_wind_cov::MsgId:
            FMavlinkMsg_wind_cov msg_wind_cov;
            msg_wind_cov.Deserialize(msg);
            FOnMavlinkMsg_wind_cov.ExecuteIfBound(msg_wind_cov);
            break;
        case FMavlinkMsg_gps_input::MsgId:
            FMavlinkMsg_gps_input msg_gps_input;
            msg_gps_input.Deserialize(msg);
            FOnMavlinkMsg_gps_input.ExecuteIfBound(msg_gps_input);
            break;
        case FMavlinkMsg_gps_rtcm_data::MsgId:
            FMavlinkMsg_gps_rtcm_data msg_gps_rtcm_data;
            msg_gps_rtcm_data.Deserialize(msg);
            FOnMavlinkMsg_gps_rtcm_data.ExecuteIfBound(msg_gps_rtcm_data);
            break;
        case FMavlinkMsg_high_latency::MsgId:
            FMavlinkMsg_high_latency msg_high_latency;
            msg_high_latency.Deserialize(msg);
            FOnMavlinkMsg_high_latency.ExecuteIfBound(msg_high_latency);
            break;
        case FMavlinkMsg_high_latency2::MsgId:
            FMavlinkMsg_high_latency2 msg_high_latency2;
            msg_high_latency2.Deserialize(msg);
            FOnMavlinkMsg_high_latency2.ExecuteIfBound(msg_high_latency2);
            break;
        case FMavlinkMsg_vibration::MsgId:
            FMavlinkMsg_vibration msg_vibration;
            msg_vibration.Deserialize(msg);
            FOnMavlinkMsg_vibration.ExecuteIfBound(msg_vibration);
            break;
        case FMavlinkMsg_home_position::MsgId:
            FMavlinkMsg_home_position msg_home_position;
            msg_home_position.Deserialize(msg);
            FOnMavlinkMsg_home_position.ExecuteIfBound(msg_home_position);
            break;
        case FMavlinkMsg_set_home_position::MsgId:
            FMavlinkMsg_set_home_position msg_set_home_position;
            msg_set_home_position.Deserialize(msg);
            FOnMavlinkMsg_set_home_position.ExecuteIfBound(msg_set_home_position);
            break;
        case FMavlinkMsg_message_interval::MsgId:
            FMavlinkMsg_message_interval msg_message_interval;
            msg_message_interval.Deserialize(msg);
            FOnMavlinkMsg_message_interval.ExecuteIfBound(msg_message_interval);
            break;
        case FMavlinkMsg_extended_sys_state::MsgId:
            FMavlinkMsg_extended_sys_state msg_extended_sys_state;
            msg_extended_sys_state.Deserialize(msg);
            FOnMavlinkMsg_extended_sys_state.ExecuteIfBound(msg_extended_sys_state);
            break;
        case FMavlinkMsg_adsb_vehicle::MsgId:
            FMavlinkMsg_adsb_vehicle msg_adsb_vehicle;
            msg_adsb_vehicle.Deserialize(msg);
            FOnMavlinkMsg_adsb_vehicle.ExecuteIfBound(msg_adsb_vehicle);
            break;
        case FMavlinkMsg_collision::MsgId:
            FMavlinkMsg_collision msg_collision;
            msg_collision.Deserialize(msg);
            FOnMavlinkMsg_collision.ExecuteIfBound(msg_collision);
            break;
        case FMavlinkMsg_v2_extension::MsgId:
            FMavlinkMsg_v2_extension msg_v2_extension;
            msg_v2_extension.Deserialize(msg);
            FOnMavlinkMsg_v2_extension.ExecuteIfBound(msg_v2_extension);
            break;
        case FMavlinkMsg_memory_vect::MsgId:
            FMavlinkMsg_memory_vect msg_memory_vect;
            msg_memory_vect.Deserialize(msg);
            FOnMavlinkMsg_memory_vect.ExecuteIfBound(msg_memory_vect);
            break;
        case FMavlinkMsg_debug_vect::MsgId:
            FMavlinkMsg_debug_vect msg_debug_vect;
            msg_debug_vect.Deserialize(msg);
            FOnMavlinkMsg_debug_vect.ExecuteIfBound(msg_debug_vect);
            break;
        case FMavlinkMsg_named_value_float::MsgId:
            FMavlinkMsg_named_value_float msg_named_value_float;
            msg_named_value_float.Deserialize(msg);
            FOnMavlinkMsg_named_value_float.ExecuteIfBound(msg_named_value_float);
            break;
        case FMavlinkMsg_named_value_int::MsgId:
            FMavlinkMsg_named_value_int msg_named_value_int;
            msg_named_value_int.Deserialize(msg);
            FOnMavlinkMsg_named_value_int.ExecuteIfBound(msg_named_value_int);
            break;
        case FMavlinkMsg_statustext::MsgId:
            FMavlinkMsg_statustext msg_statustext;
            msg_statustext.Deserialize(msg);
            FOnMavlinkMsg_statustext.ExecuteIfBound(msg_statustext);
            break;
        case FMavlinkMsg_debug::MsgId:
            FMavlinkMsg_debug msg_debug;
            msg_debug.Deserialize(msg);
            FOnMavlinkMsg_debug.ExecuteIfBound(msg_debug);
            break;
        case FMavlinkMsg_setup_signing::MsgId:
            FMavlinkMsg_setup_signing msg_setup_signing;
            msg_setup_signing.Deserialize(msg);
            FOnMavlinkMsg_setup_signing.ExecuteIfBound(msg_setup_signing);
            break;
        case FMavlinkMsg_button_change::MsgId:
            FMavlinkMsg_button_change msg_button_change;
            msg_button_change.Deserialize(msg);
            FOnMavlinkMsg_button_change.ExecuteIfBound(msg_button_change);
            break;
        case FMavlinkMsg_play_tune::MsgId:
            FMavlinkMsg_play_tune msg_play_tune;
            msg_play_tune.Deserialize(msg);
            FOnMavlinkMsg_play_tune.ExecuteIfBound(msg_play_tune);
            break;
        case FMavlinkMsg_camera_information::MsgId:
            FMavlinkMsg_camera_information msg_camera_information;
            msg_camera_information.Deserialize(msg);
            FOnMavlinkMsg_camera_information.ExecuteIfBound(msg_camera_information);
            break;
        case FMavlinkMsg_camera_settings::MsgId:
            FMavlinkMsg_camera_settings msg_camera_settings;
            msg_camera_settings.Deserialize(msg);
            FOnMavlinkMsg_camera_settings.ExecuteIfBound(msg_camera_settings);
            break;
        case FMavlinkMsg_storage_information::MsgId:
            FMavlinkMsg_storage_information msg_storage_information;
            msg_storage_information.Deserialize(msg);
            FOnMavlinkMsg_storage_information.ExecuteIfBound(msg_storage_information);
            break;
        case FMavlinkMsg_camera_capture_status::MsgId:
            FMavlinkMsg_camera_capture_status msg_camera_capture_status;
            msg_camera_capture_status.Deserialize(msg);
            FOnMavlinkMsg_camera_capture_status.ExecuteIfBound(msg_camera_capture_status);
            break;
        case FMavlinkMsg_camera_image_captured::MsgId:
            FMavlinkMsg_camera_image_captured msg_camera_image_captured;
            msg_camera_image_captured.Deserialize(msg);
            FOnMavlinkMsg_camera_image_captured.ExecuteIfBound(msg_camera_image_captured);
            break;
        case FMavlinkMsg_flight_information::MsgId:
            FMavlinkMsg_flight_information msg_flight_information;
            msg_flight_information.Deserialize(msg);
            FOnMavlinkMsg_flight_information.ExecuteIfBound(msg_flight_information);
            break;
        case FMavlinkMsg_mount_orientation::MsgId:
            FMavlinkMsg_mount_orientation msg_mount_orientation;
            msg_mount_orientation.Deserialize(msg);
            FOnMavlinkMsg_mount_orientation.ExecuteIfBound(msg_mount_orientation);
            break;
        case FMavlinkMsg_logging_data::MsgId:
            FMavlinkMsg_logging_data msg_logging_data;
            msg_logging_data.Deserialize(msg);
            FOnMavlinkMsg_logging_data.ExecuteIfBound(msg_logging_data);
            break;
        case FMavlinkMsg_logging_data_acked::MsgId:
            FMavlinkMsg_logging_data_acked msg_logging_data_acked;
            msg_logging_data_acked.Deserialize(msg);
            FOnMavlinkMsg_logging_data_acked.ExecuteIfBound(msg_logging_data_acked);
            break;
        case FMavlinkMsg_logging_ack::MsgId:
            FMavlinkMsg_logging_ack msg_logging_ack;
            msg_logging_ack.Deserialize(msg);
            FOnMavlinkMsg_logging_ack.ExecuteIfBound(msg_logging_ack);
            break;
        case FMavlinkMsg_video_stream_information::MsgId:
            FMavlinkMsg_video_stream_information msg_video_stream_information;
            msg_video_stream_information.Deserialize(msg);
            FOnMavlinkMsg_video_stream_information.ExecuteIfBound(msg_video_stream_information);
            break;
        case FMavlinkMsg_video_stream_status::MsgId:
            FMavlinkMsg_video_stream_status msg_video_stream_status;
            msg_video_stream_status.Deserialize(msg);
            FOnMavlinkMsg_video_stream_status.ExecuteIfBound(msg_video_stream_status);
            break;
        case FMavlinkMsg_wifi_config_ap::MsgId:
            FMavlinkMsg_wifi_config_ap msg_wifi_config_ap;
            msg_wifi_config_ap.Deserialize(msg);
            FOnMavlinkMsg_wifi_config_ap.ExecuteIfBound(msg_wifi_config_ap);
            break;
        case FMavlinkMsg_protocol_version::MsgId:
            FMavlinkMsg_protocol_version msg_protocol_version;
            msg_protocol_version.Deserialize(msg);
            FOnMavlinkMsg_protocol_version.ExecuteIfBound(msg_protocol_version);
            break;
        case FMavlinkMsg_uavcan_node_status::MsgId:
            FMavlinkMsg_uavcan_node_status msg_uavcan_node_status;
            msg_uavcan_node_status.Deserialize(msg);
            FOnMavlinkMsg_uavcan_node_status.ExecuteIfBound(msg_uavcan_node_status);
            break;
        case FMavlinkMsg_uavcan_node_info::MsgId:
            FMavlinkMsg_uavcan_node_info msg_uavcan_node_info;
            msg_uavcan_node_info.Deserialize(msg);
            FOnMavlinkMsg_uavcan_node_info.ExecuteIfBound(msg_uavcan_node_info);
            break;
        case FMavlinkMsg_param_ext_request_read::MsgId:
            FMavlinkMsg_param_ext_request_read msg_param_ext_request_read;
            msg_param_ext_request_read.Deserialize(msg);
            FOnMavlinkMsg_param_ext_request_read.ExecuteIfBound(msg_param_ext_request_read);
            break;
        case FMavlinkMsg_param_ext_request_list::MsgId:
            FMavlinkMsg_param_ext_request_list msg_param_ext_request_list;
            msg_param_ext_request_list.Deserialize(msg);
            FOnMavlinkMsg_param_ext_request_list.ExecuteIfBound(msg_param_ext_request_list);
            break;
        case FMavlinkMsg_param_ext_value::MsgId:
            FMavlinkMsg_param_ext_value msg_param_ext_value;
            msg_param_ext_value.Deserialize(msg);
            FOnMavlinkMsg_param_ext_value.ExecuteIfBound(msg_param_ext_value);
            break;
        case FMavlinkMsg_param_ext_set::MsgId:
            FMavlinkMsg_param_ext_set msg_param_ext_set;
            msg_param_ext_set.Deserialize(msg);
            FOnMavlinkMsg_param_ext_set.ExecuteIfBound(msg_param_ext_set);
            break;
        case FMavlinkMsg_param_ext_ack::MsgId:
            FMavlinkMsg_param_ext_ack msg_param_ext_ack;
            msg_param_ext_ack.Deserialize(msg);
            FOnMavlinkMsg_param_ext_ack.ExecuteIfBound(msg_param_ext_ack);
            break;
        case FMavlinkMsg_obstacle_distance::MsgId:
            FMavlinkMsg_obstacle_distance msg_obstacle_distance;
            msg_obstacle_distance.Deserialize(msg);
            FOnMavlinkMsg_obstacle_distance.ExecuteIfBound(msg_obstacle_distance);
            break;
        case FMavlinkMsg_odometry::MsgId:
            FMavlinkMsg_odometry msg_odometry;
            msg_odometry.Deserialize(msg);
            FOnMavlinkMsg_odometry.ExecuteIfBound(msg_odometry);
            break;
        case FMavlinkMsg_trajectory_representation_waypoints::MsgId:
            FMavlinkMsg_trajectory_representation_waypoints msg_trajectory_representation_waypoints;
            msg_trajectory_representation_waypoints.Deserialize(msg);
            FOnMavlinkMsg_trajectory_representation_waypoints.ExecuteIfBound(msg_trajectory_representation_waypoints);
            break;
        case FMavlinkMsg_trajectory_representation_bezier::MsgId:
            FMavlinkMsg_trajectory_representation_bezier msg_trajectory_representation_bezier;
            msg_trajectory_representation_bezier.Deserialize(msg);
            FOnMavlinkMsg_trajectory_representation_bezier.ExecuteIfBound(msg_trajectory_representation_bezier);
            break;
        case FMavlinkMsg_cellular_status::MsgId:
            FMavlinkMsg_cellular_status msg_cellular_status;
            msg_cellular_status.Deserialize(msg);
            FOnMavlinkMsg_cellular_status.ExecuteIfBound(msg_cellular_status);
            break;
        case FMavlinkMsg_utm_global_position::MsgId:
            FMavlinkMsg_utm_global_position msg_utm_global_position;
            msg_utm_global_position.Deserialize(msg);
            FOnMavlinkMsg_utm_global_position.ExecuteIfBound(msg_utm_global_position);
            break;
        case FMavlinkMsg_debug_float_array::MsgId:
            FMavlinkMsg_debug_float_array msg_debug_float_array;
            msg_debug_float_array.Deserialize(msg);
            FOnMavlinkMsg_debug_float_array.ExecuteIfBound(msg_debug_float_array);
            break;
        case FMavlinkMsg_orbit_execution_status::MsgId:
            FMavlinkMsg_orbit_execution_status msg_orbit_execution_status;
            msg_orbit_execution_status.Deserialize(msg);
            FOnMavlinkMsg_orbit_execution_status.ExecuteIfBound(msg_orbit_execution_status);
            break;
        case FMavlinkMsg_statustext_long::MsgId:
            FMavlinkMsg_statustext_long msg_statustext_long;
            msg_statustext_long.Deserialize(msg);
            FOnMavlinkMsg_statustext_long.ExecuteIfBound(msg_statustext_long);
            break;
        case FMavlinkMsg_smart_battery_info::MsgId:
            FMavlinkMsg_smart_battery_info msg_smart_battery_info;
            msg_smart_battery_info.Deserialize(msg);
            FOnMavlinkMsg_smart_battery_info.ExecuteIfBound(msg_smart_battery_info);
            break;
        case FMavlinkMsg_smart_battery_status::MsgId:
            FMavlinkMsg_smart_battery_status msg_smart_battery_status;
            msg_smart_battery_status.Deserialize(msg);
            FOnMavlinkMsg_smart_battery_status.ExecuteIfBound(msg_smart_battery_status);
            break;
        case FMavlinkMsg_wheel_distance::MsgId:
            FMavlinkMsg_wheel_distance msg_wheel_distance;
            msg_wheel_distance.Deserialize(msg);
            FOnMavlinkMsg_wheel_distance.ExecuteIfBound(msg_wheel_distance);
            break;
        
    }
}
    

