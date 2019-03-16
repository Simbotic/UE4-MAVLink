#pragma once

#include "MavLinkUtils.h"
 #include "MavLinkMsg_heartbeat.h"
 #include "MavLinkMsg_sys_status.h"
 #include "MavLinkMsg_system_time.h"
 #include "MavLinkMsg_ping.h"
 #include "MavLinkMsg_change_operator_control.h"
 #include "MavLinkMsg_change_operator_control_ack.h"
 #include "MavLinkMsg_auth_key.h"
 #include "MavLinkMsg_set_mode.h"
 #include "MavLinkMsg_param_request_read.h"
 #include "MavLinkMsg_param_request_list.h"
 #include "MavLinkMsg_param_value.h"
 #include "MavLinkMsg_param_set.h"
 #include "MavLinkMsg_gps_raw_int.h"
 #include "MavLinkMsg_gps_status.h"
 #include "MavLinkMsg_scaled_imu.h"
 #include "MavLinkMsg_raw_imu.h"
 #include "MavLinkMsg_raw_pressure.h"
 #include "MavLinkMsg_scaled_pressure.h"
 #include "MavLinkMsg_attitude.h"
 #include "MavLinkMsg_attitude_quaternion.h"
 #include "MavLinkMsg_local_position_ned.h"
 #include "MavLinkMsg_global_position_int.h"
 #include "MavLinkMsg_rc_channels_scaled.h"
 #include "MavLinkMsg_rc_channels_raw.h"
 #include "MavLinkMsg_servo_output_raw.h"
 #include "MavLinkMsg_mission_request_partial_list.h"
 #include "MavLinkMsg_mission_write_partial_list.h"
 #include "MavLinkMsg_mission_item.h"
 #include "MavLinkMsg_mission_request.h"
 #include "MavLinkMsg_mission_set_current.h"
 #include "MavLinkMsg_mission_current.h"
 #include "MavLinkMsg_mission_request_list.h"
 #include "MavLinkMsg_mission_count.h"
 #include "MavLinkMsg_mission_clear_all.h"
 #include "MavLinkMsg_mission_item_reached.h"
 #include "MavLinkMsg_mission_ack.h"
 #include "MavLinkMsg_set_gps_global_origin.h"
 #include "MavLinkMsg_gps_global_origin.h"
 #include "MavLinkMsg_param_map_rc.h"
 #include "MavLinkMsg_mission_request_int.h"
 #include "MavLinkMsg_safety_set_allowed_area.h"
 #include "MavLinkMsg_safety_allowed_area.h"
 #include "MavLinkMsg_attitude_quaternion_cov.h"
 #include "MavLinkMsg_nav_controller_output.h"
 #include "MavLinkMsg_global_position_int_cov.h"
 #include "MavLinkMsg_local_position_ned_cov.h"
 #include "MavLinkMsg_rc_channels.h"
 #include "MavLinkMsg_request_data_stream.h"
 #include "MavLinkMsg_data_stream.h"
 #include "MavLinkMsg_manual_control.h"
 #include "MavLinkMsg_rc_channels_override.h"
 #include "MavLinkMsg_mission_item_int.h"
 #include "MavLinkMsg_vfr_hud.h"
 #include "MavLinkMsg_command_int.h"
 #include "MavLinkMsg_command_long.h"
 #include "MavLinkMsg_command_ack.h"
 #include "MavLinkMsg_manual_setpoint.h"
 #include "MavLinkMsg_set_attitude_target.h"
 #include "MavLinkMsg_attitude_target.h"
 #include "MavLinkMsg_set_position_target_local_ned.h"
 #include "MavLinkMsg_position_target_local_ned.h"
 #include "MavLinkMsg_set_position_target_global_int.h"
 #include "MavLinkMsg_position_target_global_int.h"
 #include "MavLinkMsg_local_position_ned_system_global_offset.h"
 #include "MavLinkMsg_hil_state.h"
 #include "MavLinkMsg_hil_controls.h"
 #include "MavLinkMsg_hil_rc_inputs_raw.h"
 #include "MavLinkMsg_hil_actuator_controls.h"
 #include "MavLinkMsg_optical_flow.h"
 #include "MavLinkMsg_global_vision_position_estimate.h"
 #include "MavLinkMsg_vision_position_estimate.h"
 #include "MavLinkMsg_vision_speed_estimate.h"
 #include "MavLinkMsg_vicon_position_estimate.h"
 #include "MavLinkMsg_highres_imu.h"
 #include "MavLinkMsg_optical_flow_rad.h"
 #include "MavLinkMsg_hil_sensor.h"
 #include "MavLinkMsg_sim_state.h"
 #include "MavLinkMsg_radio_status.h"
 #include "MavLinkMsg_file_transfer_protocol.h"
 #include "MavLinkMsg_timesync.h"
 #include "MavLinkMsg_camera_trigger.h"
 #include "MavLinkMsg_hil_gps.h"
 #include "MavLinkMsg_hil_optical_flow.h"
 #include "MavLinkMsg_hil_state_quaternion.h"
 #include "MavLinkMsg_scaled_imu2.h"
 #include "MavLinkMsg_log_request_list.h"
 #include "MavLinkMsg_log_entry.h"
 #include "MavLinkMsg_log_request_data.h"
 #include "MavLinkMsg_log_data.h"
 #include "MavLinkMsg_log_erase.h"
 #include "MavLinkMsg_log_request_end.h"
 #include "MavLinkMsg_gps_inject_data.h"
 #include "MavLinkMsg_gps2_raw.h"
 #include "MavLinkMsg_power_status.h"
 #include "MavLinkMsg_serial_control.h"
 #include "MavLinkMsg_gps_rtk.h"
 #include "MavLinkMsg_gps2_rtk.h"
 #include "MavLinkMsg_scaled_imu3.h"
 #include "MavLinkMsg_data_transmission_handshake.h"
 #include "MavLinkMsg_encapsulated_data.h"
 #include "MavLinkMsg_distance_sensor.h"
 #include "MavLinkMsg_terrain_request.h"
 #include "MavLinkMsg_terrain_data.h"
 #include "MavLinkMsg_terrain_check.h"
 #include "MavLinkMsg_terrain_report.h"
 #include "MavLinkMsg_scaled_pressure2.h"
 #include "MavLinkMsg_att_pos_mocap.h"
 #include "MavLinkMsg_set_actuator_control_target.h"
 #include "MavLinkMsg_actuator_control_target.h"
 #include "MavLinkMsg_altitude.h"
 #include "MavLinkMsg_resource_request.h"
 #include "MavLinkMsg_scaled_pressure3.h"
 #include "MavLinkMsg_follow_target.h"
 #include "MavLinkMsg_control_system_state.h"
 #include "MavLinkMsg_battery_status.h"
 #include "MavLinkMsg_autopilot_version.h"
 #include "MavLinkMsg_landing_target.h"
 #include "MavLinkMsg_estimator_status.h"
 #include "MavLinkMsg_wind_cov.h"
 #include "MavLinkMsg_gps_input.h"
 #include "MavLinkMsg_gps_rtcm_data.h"
 #include "MavLinkMsg_high_latency.h"
 #include "MavLinkMsg_high_latency2.h"
 #include "MavLinkMsg_vibration.h"
 #include "MavLinkMsg_home_position.h"
 #include "MavLinkMsg_set_home_position.h"
 #include "MavLinkMsg_message_interval.h"
 #include "MavLinkMsg_extended_sys_state.h"
 #include "MavLinkMsg_adsb_vehicle.h"
 #include "MavLinkMsg_collision.h"
 #include "MavLinkMsg_v2_extension.h"
 #include "MavLinkMsg_memory_vect.h"
 #include "MavLinkMsg_debug_vect.h"
 #include "MavLinkMsg_named_value_float.h"
 #include "MavLinkMsg_named_value_int.h"
 #include "MavLinkMsg_statustext.h"
 #include "MavLinkMsg_debug.h"
 #include "MavLinkMsg_setup_signing.h"
 #include "MavLinkMsg_button_change.h"
 #include "MavLinkMsg_play_tune.h"
 #include "MavLinkMsg_camera_information.h"
 #include "MavLinkMsg_camera_settings.h"
 #include "MavLinkMsg_storage_information.h"
 #include "MavLinkMsg_camera_capture_status.h"
 #include "MavLinkMsg_camera_image_captured.h"
 #include "MavLinkMsg_flight_information.h"
 #include "MavLinkMsg_mount_orientation.h"
 #include "MavLinkMsg_logging_data.h"
 #include "MavLinkMsg_logging_data_acked.h"
 #include "MavLinkMsg_logging_ack.h"
 #include "MavLinkMsg_video_stream_information.h"
 #include "MavLinkMsg_video_stream_status.h"
 #include "MavLinkMsg_wifi_config_ap.h"
 #include "MavLinkMsg_protocol_version.h"
 #include "MavLinkMsg_uavcan_node_status.h"
 #include "MavLinkMsg_uavcan_node_info.h"
 #include "MavLinkMsg_param_ext_request_read.h"
 #include "MavLinkMsg_param_ext_request_list.h"
 #include "MavLinkMsg_param_ext_value.h"
 #include "MavLinkMsg_param_ext_set.h"
 #include "MavLinkMsg_param_ext_ack.h"
 #include "MavLinkMsg_obstacle_distance.h"
 #include "MavLinkMsg_odometry.h"
 #include "MavLinkMsg_trajectory_representation_waypoints.h"
 #include "MavLinkMsg_trajectory_representation_bezier.h"
 #include "MavLinkMsg_cellular_status.h"
 #include "MavLinkMsg_utm_global_position.h"
 #include "MavLinkMsg_debug_float_array.h"
 #include "MavLinkMsg_orbit_execution_status.h"
 #include "MavLinkMsg_statustext_long.h"
 #include "MavLinkMsg_smart_battery_info.h"
 #include "MavLinkMsg_smart_battery_status.h"
 #include "MavLinkMsg_wheel_distance.h"

