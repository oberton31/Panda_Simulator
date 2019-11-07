/***************************************************************************
* Adapted from panda_velocity_controller.h (sawyer_simulator package)

*
* @package: panda_sim_controllers
* @metapackage: panda_simulator
* @author: Saif Sidhik <sxs1412@bham.ac.uk>
*

**************************************************************************/

/***************************************************************************
* Copyright (c) 2013-2018, Rethink Robotics Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**************************************************************************/

#ifndef PANDA_VELOCITY_CONTROLLER_H
#define PANDA_VELOCITY_CONTROLLER_H

#include <panda_sim_controllers/joint_array_controller.h>
#include <franka_core_msgs/JointCommand.h>
#include <panda_sim_controllers/panda_joint_velocity_controller.h>
#include <ros/node_handle.h>

#include <control_toolbox/pid.h>
#include <panda_hardware_interface/shared_joint_interface.h>

namespace panda_sim_controllers
{
  class PandaVelocityController : public panda_sim_controllers::JointArrayController<panda_effort_controllers::JointVelocityController>
  {
  public:
    virtual ~PandaVelocityController() {sub_joint_command_.shutdown();}
    virtual bool init(panda_hardware_interface::SharedJointInterface* hw, ros::NodeHandle &n);
    void setCommands();

  private:
    ros::Subscriber sub_joint_command_;

    void jointCommandCB(const franka_core_msgs::JointCommandConstPtr& msg);
  };
}

#endif