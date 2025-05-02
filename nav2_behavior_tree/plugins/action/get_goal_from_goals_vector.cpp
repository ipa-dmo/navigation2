// Copyright (c) 2021 Samsung Research America
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <memory>
#include <string>
#include <vector>

#include "nav2_behavior_tree/plugins/action/get_goal_from_goals_vector.hpp"

namespace nav2_behavior_tree
{

GetGoalFromGoalsVector::GetGoalFromGoalsVector(
  const std::string & name,
  const BT::NodeConfiguration & conf)
: BT::ActionNodeBase(name, conf)
{
}

inline BT::NodeStatus GetGoalFromGoalsVector::tick()
{
  std::vector<geometry_msgs::msg::PoseStamped> goals;
  int goal_index;
  getInput("goals", goals);
  getInput("goal_index", goal_index);
  if (goals.size() > static_cast<unsigned>(goal_index) && goal_index >= 0)
  {
    setOutput("goal", goals[goal_index]);
    return BT::NodeStatus::SUCCESS;
  }
  geometry_msgs::msg::PoseStamped empty_pose;
  setOutput("goal", empty_pose);
  return BT::NodeStatus::FAILURE;
}

}  // namespace nav2_behavior_tree

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<nav2_behavior_tree::GetGoalFromGoalsVector>(
    "GetGoalFromGoalsVector");
}
