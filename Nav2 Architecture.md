
![[nav2 architecture.png]]


The simplified version of the nav2 architecture is depicted below :


![[NAV2_Architecture.drawio.png]]


Pose goal means a position along with orientation for the robot. 

The Global planner/ Planner server will be responsible for finding a valid path using the global costmap. Once the path is found out the local planner/Controller will try to make the robot follow the path and reach the destination. The local planner will use the data from the local costmap and also the data from all the different sensors. Then the local planner will send a command to the robot controller itself .

The robot controller is a custom controller for the robot responsible to take a velocity command or translate it into a command that can be send to the model  so that the robot can move.

The robot controller is independent from the nav stack. For various reasons the robot might not be able to follow the path designated. Hence there are recovery behaviours to get back on track . 
for eg: it can try to clear the cost map or move a bit back, turn etc. 