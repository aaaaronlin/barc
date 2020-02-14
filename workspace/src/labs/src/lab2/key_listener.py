#!/usr/bin/env python


# heavily inspired by and copied from https://github.com/ros-teleop/teleop_twist_keyboard/blob/master/teleop_twist_keyboard.py

import rospy
import time, sys, select, termios, tty 
from barc.msg import ECU

# initialize global
acc = 0
d_f = 0
settings = termios.tcgetattr(sys.stdin)

def getKey():
	global settings
	tty.setraw(sys.stdin.fileno())
	select.select([sys.stdin], [], [], 0)
	key = sys.stdin.read(1)
	termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
	return key

def controller():
	global acc, d_f


	settings = termios.tcgetattr(sys.stdin)

	# initialize node
	rospy.init_node('key_listener', anonymous=True)
	
	# topic subscriptions / publications
	state_pub = rospy.Publisher('ecu', ECU, queue_size = 10)
	
	# set node rate
	loop_rate = 50
	dt = 1.0 / loop_rate
	rate = rospy.Rate(loop_rate)
	t0 = time.time()
	
	# set initial conditions 
	d_f = 0
	acc = 0
	
	while not rospy.is_shutdown():
		# get keyboard inputs
		key = getKey()
		if key == 'w':
			acc = 0.1
		if key == 's':
			acc = -0.1
		if key == 'a':
			d_f += 0.01
		if key == 'd':
			d_f -= 0.01
		# publish information
	 	state_pub.publish( ECU(acc, d_f) )
		# wait
		rate.sleep()
	
if __name__ == '__main__':
	try:
		controller()
	except rospy.ROSInterruptException:
		pass
	finally:
		termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
