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

#ifndef NAV2_BEHAVIOR_TREE__PLUGINS__ACTION__GET_GOAL_FROM_GOALS_VECTOR_HPP_
#define NAV2_BEHAVIOR_TREE__PLUGINS__ACTION__GET_GOAL_FROM_GOALS_VECTOR_HPP_

#include <string>
#include <vector>


#include "geometry_msgs/msg/pose_stamped.hpp"
#include "behaviortree_cpp/action_node.h"
#include "nav2_behavior_tree/bt_action_node.hpp"

namespace nav2_behavior_tree
{


/**
 * @brief A nav2_behavior_tree::BtActionNode class
 */
class GetGoalFromGoalsVector  : public BT::ActionNodeBase
{

public:
  /**
   * @brief A constructor for nav2_behavior_tree::GetGoalFromGoalsVectorAction
   * @param xml_tag_name Name for the XML tag for this node
   * @param conf BT node configuration
   */
  GetGoalFromGoalsVector(
    const std::string & name,
    const BT::NodeConfiguration & conf);


  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::vector<geometry_msgs::msg::PoseStamped>>(
        "goals",
        "Destinations to plan through"),
      BT::InputPort<int>(
        "goal_index", 0, "Index to export"),
      BT::OutputPort<geometry_msgs::msg::PoseStamped>("goal", "Selected goal"),
    };
  }

private:

  void halt() override {}
  /**
   * @brief Function to perform some user-defined operation on tick
   */
  BT::NodeStatus tick() override;

};

}  // namespace nav2_behavior_tree

#endif  // NAV2_BEHAVIOR_TREE__PLUGINS__ACTION__COMPUTE_PATH_THROUGH_POSES_ACTION_HPP_
