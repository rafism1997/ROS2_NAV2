
- Installation of  Nav2 Packages :

```bash
sudo apt install ros-humble-navigation2 ros-humble-nav2-bringup ros-humble-turtlebot3
```

- Colcon build tool installation for compiling ros2 packages

```bash
sudo apt install python3-colcon-common-extensions
```

### Navigation Process :

2 Step Process :

- Step 1 : Create a map(with SLAM)
- Step 2 : Make the robot navigate from point A to point B 

#### Turtlbeot 3 Example :

- Specify the turtlebot3 model you are going to use(by exporting the environment variable) :

```bash
export TURTLEBOT3_MODEL=waffle
```
  
In order to check the version of ros or turtlebot used : 

```bash 
printenv | grep ROS #For checking ROS version 
printenv | grep TURTLE #For checking turtlebot version 
```

Launch a simulated world environment with turtlebot3 :

```bash 
ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py
```


**====Issue running turtlebot3 simulation in  gazebo 11 since all the binary packages were stopped for Ubuntu 22**

When we are running slam with Gazebo using Turtlebot3 robot then the following package can be used: 

```bash
ros2 launch turtlebot3_cartographer cartographer.launch.py use_sim_time:=True #use_sim_time - simulation time 
```

To save the map from the map topic: 

```bash 
ros2 run nav2_map_server map_saver_cli -f maps/my_map
```

### Map.yaml 

![[ilabs_map1.pgm]]
The YAML format is best explained with a simple, complete example:

```yaml
image: testmap.png
resolution: 0.1
origin: [0.0, 0.0, 0.0]
occupied_thresh: 0.65
free_thresh: 0.196
negate: 0
```

Required fields:

-   **image** : Path to the image file containing the occupancy data; can be absolute, or relative to the location of the YAML file
    
-   **resolution** : Resolution of the map, meters / pixel
    
-   **origin** : The 2-D pose of the lower-left pixel in the map, as (x, y, yaw), with yaw as counterclockwise rotation (yaw=0 means no rotation). Many parts of the system currently ignore yaw.
    
-   **occupied_thresh** : Pixels with occupancy probability greater than this threshold are considered completely occupied.
    
-   **free_thresh** : Pixels with occupancy probability less than this threshold are considered completely free.
    
-   **negate** : Whether the white/black free/occupied semantics should be reversed (interpretation of thresholds is unaffected)
    

Optional parameter:

-   **mode** : Can have one of three values: trinary, scale, or raw. Trinary is the default. More information on how this changes the value interpretation is in the next section.

If we multiply the number of pixels with the resolution we get the width of the pgm image in meters:

Number of pixel can be obtained from the .pgm file


To resolve the fixed frame issue while starting the ros2 nav2 , there are some fixes

```bash 
sudo apt install ros-humble-rmw-cyclonedds-cpp  
```

Add environment variable to start it in all terminals spawned afterwards :

```bash
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
```

If we want to get access to the parameters files for different ros pkgs , we need to go inside the share folder.