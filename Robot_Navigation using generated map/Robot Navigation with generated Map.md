

Continuation of  
[[ROS2 NAV2]]

Start the turtlebot3 navigation in an arbitrary world :

```bash
ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py 
```


Run the navigation launch file :

```bash 
ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=True maps:=<location/name.yaml>
```

```
ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=True map:=/home/rafi/Documents/ROS2_NAV2/maps/new_map.yaml

```

We need to give a 2D estimate of the position of the robot w.r.t the environment

If we give the wrong 2D pose estimate then the orientation of the robot will change 

![[local_and_global_planner.png]]

Global planner :

![[Global_planner.png]]

Local Planner : 

![[local_planner.png]]


If we give a Navigation goal out of the map then the robot may abort the path and carry on with some recovery behaviour to understand the trajectory :

```bash 
[planner_server-5] [WARN] [1676969850.418318196] [planner_server]: GridBased: failed to create plan with tolerance 0.50.
[planner_server-5] [WARN] [1676969850.418366484] [planner_server]: Planning algorithm GridBased failed to generate a valid path to (-4.12, 4.78)
[planner_server-5] [WARN] [1676969850.418373779] [planner_server_rclcpp_node]: [compute_path_to_pose] [ActionServer] Aborting handle.
[planner_server-5] [INFO] [1676969850.437460178] [global_costmap.global_costmap]: Received request to clear entirely the global_costmap
[controller_server-4] [INFO] [1676969850.458291974] [controller_server]: Received a goal, begin computing control effort.
[controller_server-4] [INFO] [1676969850.458722875] [controller_server]: Passing new path to controller.
[controller_server-4] [ERROR] [1676969850.461201959] [DWBLocalPlanner]: No valid trajectories out of 419! 
[controller_server-4] [ERROR] [1676969850.461225850] [DWBLocalPlanner]: 1.00: BaseObstacle/Trajectory Hits Obstacle.
[controller_server-4] [ERROR] [1676969850.461419782] [controller_server]: No valid trajectories out of 419! 
[controller_server-4] [WARN] [1676969850.461450516] [controller_server_rclcpp_node]: [follow_path] [ActionServer] Aborting handle.
[bt_navigator-7] [ERROR] [1676969850.497322854] [bt_navigator]: Navigation failed
[bt_navigator-7] [WARN] [1676969850.497389406] [bt_navigator]: [navigate_to_pose] [ActionServer] Aborting handle.


```

### Waypoint Follower - Go through multiple NAV2 goals 

![[waypoint_follower.png]]

The green arrows indicate the path and direction in which the robot should manuever. 

### Dynamic Obstacle Avoidance 

