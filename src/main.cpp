/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    2, 9, 16, 12    
// claw                 motor         8               
// backarm              motor         14              
// Controller1          controller                    
// frontarms            motor_group   7, 17           
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  claw.setPosition(0, degrees); // calibrate claw: starting pos = 0 deg
  frontarms.setPosition(0, degrees); // calibrate arms: starting pos = 0 deg;

  // claw.spinToPosition(360, degrees);
  claw.spinFor(forward, .7, turns); // lower claw (frontarms already start lowered)

  Drivetrain.driveFor(forward, 45, inches); // drive forward
  Drivetrain.setStopping(brake); 
  Drivetrain.stop(); // stop with arms under goal

  // claw.spinToPosition(200, degrees);
  claw.spinFor(reverse, .25, turns); // raise claw slightly to pick up goal
  // frontarms.spinToPosition(70, degrees);
  frontarms.spinFor(reverse, .5, turns); // raise arms to support claw in picking up goal

  /* THIS WOULD BE A GOOD PLACE TO ROTATE AND PICK UP THE NEXT ONE WITH THE BACKARMS */
  
  // Drivetrain.turnFor(right, .5, turns); // turn the robot to face the position from which it came

  Drivetrain.driveFor(reverse, 36, inches); // drive directly backwards to starting position
  Drivetrain.stop(); // stop with goal in front arms

  // set down goal in home field
  // frontarms.spinToPosition();

  // go for the next goal

}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    if(!Controller1.ButtonB.pressing() || !Controller1.ButtonX.pressing()) {
      backarm.setStopping(hold);
    }
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
