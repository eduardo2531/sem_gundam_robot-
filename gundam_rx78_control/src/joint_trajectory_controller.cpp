
// Pluginlib
#include <pluginlib/class_list_macros.hpp>

// Project
#include <trajectory_interface/quintic_spline_segment.h>
#include "gundam_rx78_control/joint_trajectory_controller.h"

namespace position_controllers
{
  /**
   * \brief Joint trajectory controller that represents trajectory segments as <b>quintic splines</b> and sends
   * commands to a \b position interface.
   */
  typedef joint_trajectory_controller::JointTrajectoryController<trajectory_interface::QuinticSplineSegment<double>,
                                                                 hardware_interface::PositionJointInterface>
          JointTrajectoryController;
}

namespace velocity_controllers
{
  /**
   * \brief Joint trajectory controller that represents trajectory segments as <b>quintic splines</b> and sends
   * commands to a \b velocity interface.
   */
  typedef joint_trajectory_controller::JointTrajectoryController<trajectory_interface::QuinticSplineSegment<double>,
                                                                 hardware_interface::VelocityJointInterface>
          JointTrajectoryController;
}

namespace effort_controllers
{
  /**
   * \brief Joint trajectory controller that represents trajectory segments as <b>quintic splines</b> and sends
   * commands to an \b effort interface.
   */
  typedef joint_trajectory_controller::JointTrajectoryController<trajectory_interface::QuinticSplineSegment<double>,
                                                                 hardware_interface::EffortJointInterface>
          JointTrajectoryController;
}

namespace pos_vel_controllers
{
  /**
   * \brief Joint trajectory controller that represents trajectory segments as <b>quintic splines</b> and sends
   * commands to an \b pos_vel interface.
   */
  typedef joint_trajectory_controller::JointTrajectoryController<trajectory_interface::QuinticSplineSegment<double>,
                                                                 hardware_interface::PosVelJointInterface>
          JointTrajectoryController;
}

namespace pos_vel_acc_controllers
{
  /**
   * \brief Joint trajectory controller that represents trajectory segments as <b>quintic splines</b> and sends
   * commands to a \b pos_vel_acc interface.
   */
  typedef joint_trajectory_controller::JointTrajectoryController<trajectory_interface::QuinticSplineSegment<double>,
                                                                 hardware_interface::PosVelAccJointInterface>
          JointTrajectoryController;
}

PLUGINLIB_EXPORT_CLASS(position_controllers::JointTrajectoryController, controller_interface::ControllerBase)
PLUGINLIB_EXPORT_CLASS(velocity_controllers::JointTrajectoryController, controller_interface::ControllerBase)
PLUGINLIB_EXPORT_CLASS(effort_controllers::JointTrajectoryController,   controller_interface::ControllerBase)
PLUGINLIB_EXPORT_CLASS(pos_vel_controllers::JointTrajectoryController,   controller_interface::ControllerBase)
PLUGINLIB_EXPORT_CLASS(pos_vel_acc_controllers::JointTrajectoryController,   controller_interface::ControllerBase)
