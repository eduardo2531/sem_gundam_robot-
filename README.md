gundam_robot [![Build Status](https://travis-ci.com/gundam-global-challenge/gundam_robot.svg?branch=master)](https://travis-ci.com/gundam-global-challenge/gundam_robot)
========================================================================================================================================================================
ROS packages for GUNDAM robots

original: https://github.com/gundam-global-challenge/gundam_robot.git


![GUNDAM Gazebo Simulation](imgs/gundam_AKG.jpg)



How to setup workspace
----------------------

```
$ mkdir -p catkin_ws/src
$ cd  catkin_ws
$ cd src/
$ git clone https://github.com//gundam_robot.git
$ cd ..
$ source /opt/ros/$ROS_DISTRO/setup.bash
$ rosdep install -y -r --from-paths src --ignore-src
$ catkin_make
$ source devel/setup.bash
```
To run a gazebo dynamics simulation, you can start `gundam_rx78_world.launch`.

```
$ roslaunch gundam_rx78_gazebo gundam_rx78_world.launch
```

To control joint angles, try a sample script.

```


Experimental
------------

You can run "Robot"-like walking pattern on simulation

```
$ roslaunch gundam_rx78_gazebo gundam_rx78_walk.launch
```

```
# step
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/step.csv
# walk forward
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/walk-forward.csv
# walk backward
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/walk-backward.csv
# walk to right
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/walk-to-right.csv
# walk to left
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/walk-to-left.csv
# turn right
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/turn-right.csv
# turn left
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/turn-left.csv
```

Note that currently, we have several limitation on this simulation, we only have position controller etc.

You can also find sample motion control files in the `gundam_rx78_control/sample` directory.

For Developers Only
===================

