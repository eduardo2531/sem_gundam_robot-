

"""
Reading Trajectory Data from CSV and Send To Robot via Action Client
"""

import rospy

import actionlib

import argparse
import sys
import time
import csv

from control_msgs.msg import (
    FollowJointTrajectoryAction,
    FollowJointTrajectoryGoal,
)
from trajectory_msgs.msg import (
    JointTrajectoryPoint,
)


def main(filename):
    print("Initializing node... ")
    rospy.init_node("joint_trajectory_client_csv_example")
    rospy.sleep(1)
    print("Running. Ctrl-c to quit")

    # init goal
    goal = FollowJointTrajectoryGoal()
    goal.goal_time_tolerance = rospy.Time(1)

    with open(filename) as f:
        reader = csv.reader(f, skipinitialspace=True)
        first_row = True
        for row in reader:
            if first_row:
                goal.trajectory.joint_names = row[1:]
                first_row = False
            else:
                point = JointTrajectoryPoint()
                point.positions = [float(n) for n in row[1:]]
                point.time_from_start = rospy.Duration(float(row[0]))
                goal.trajectory.points.append(point)
    client = actionlib.SimpleActionClient(
        '/fullbody_controller/follow_joint_trajectory',
        FollowJointTrajectoryAction,
    )

    if not client.wait_for_server(timeout=rospy.Duration(10)):
        rospy.logerr("Timed out waiting for Action Server")
        rospy.signal_shutdown("Timed out waiting for Action Server")
        sys.exit(1)

    # send goal
    goal.trajectory.header.stamp = rospy.Time.now()
    client.send_goal(goal)
    print("waiting...")
    if not client.wait_for_result(timeout=rospy.Duration(60)):
        rospy.logerr("Timed out waiting for JTA")
    rospy.loginfo("Exitting...")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Reading CSV trajectory data and send to the robot.')
    parser.add_argument('filename', type=str, nargs=1,
                        help='CSV trajectory data file name')
    args = parser.parse_args(rospy.myargv()[1:])
    main(args.filename[0])
