#include "main.h"
#include "headers/globals.hpp"

#include "headers/odometry.hpp"
#include "headers/opcontrol.hpp"
#include "headers/screensim.hpp"

/**
 * Master controls left and right drive
 * T value is 12.4
 * Using curvature drive. Left stick controls speed, right stick controls the radius of a turn. Speed does not affect radius.
 *
 */
void opcontrol()
{
	screen::set_eraser(COLOR_BLACK);
	screen::erase();
	// startup some display tasks
	pros::Task screenTask(position);
	pros::Task arrowTask(drawArrow);

	// loop forever
	int count = 0;
	while (true)
	{
		// get left y and right x positions
		int leftY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = -master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

		// move the robot
		chassis.curvature(leftY, rightX);

		if (master.get_digital(E_CONTROLLER_DIGITAL_A)) {
			// clear LVGL screen
			lv_obj_clean(lv_scr_act());
		}
		else {}

		// delay so we don't destroy the CPU
		pros::delay(10);
	}
}
