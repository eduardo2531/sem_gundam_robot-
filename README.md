gundam_robot [![Build Status](https://travis-ci.com/gundam-global-challenge/gundam_robot.svg?branch=master)](https://travis-ci.com/gundam-global-challenge/gundam_robot)
========================================================================================================================================================================
ROS packages for GUNDAM robots

original: https://github.com/gundam-global-challenge/gundam_robot.git


![GUNDAM Gazebo Simulation](imgs/gundam_AKG.jpg)


Cómo configurar el espacio de trabajo
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
Para ejecutar una simulación de dinámica de glorieta, puede comenzar se agrega mapa para mejor visualizacion `gundam_rx78_world.launch`.

```
$ roslaunch gundam_rx78_gazebo gundam_rx78_world.launch
```

Para controlar los ángulos de las articulaciones, pruebe con un script de muestra.

```
Para hacer que el Gundam Camine, debe estar ejecutandose la simulación de gazebo del paso anterior y luego en una nueva consola ejecutar cualquiera de los siguientes comandos:

Solo ejecutar una vez:
----------------------

#cd al ambiente del proyecto
#Ejecutar una vez el siguiente comando
$ source devel/setup.bash
```
Experimental
------------

Puede ejecutar un patrón de caminata similar a un "robot" en la simulación
```
$ roslaunch gundam_rx78_gazebo gundam_rx78_walk.launch
```

# Paso
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/step.csv
# Caminar hacia adelante
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/walk-forward.csv
# caminar hacia atrás
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/walk-backward.csv
# caminar a la derecha
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/walk-to-right.csv
# caminar a la izquierda
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/walk-to-left.csv
# Gire a la derecha
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/turn-right.csv
# Gire a la izquierda
$ rosrun gundam_rx78_control joint_trajectory_client_csv.py `rospack find gundam_rx78_control`/sample/csv/turn-left.csv
```

Note that currently, we have several limitation on this simulation, we only have position controller etc.

You can also find sample motion control files in the `gundam_rx78_control/sample` directory.

For Developers Only
===================

