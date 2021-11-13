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
// frontarmpot          pot           A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include <iostream>
#include "vex.h"
#include "functions.h"
#include "auton.h"

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
bool isFrontRaised = false;
bool isBackRaised = true;

void autonomous(void) {
  // Comment one of these function calls out depending on which side we start on
  auton_left();
  // auton_right();
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
void APressed() {
    raiseFront(isFrontRaised);
}
void BPressed() {
    lowerFront(isFrontRaised);
} 
void XPressed() {
    raiseBack(isBackRaised);
} 
void YPressed() {
    lowerBack(isBackRaised);
}  

void usercontrol(void) {
  // configurations
  float clawAngle;
  claw.setPosition(0, degrees); // calibrate claw: starting pos = 0 deg
  frontarms.setPosition(0, degrees); // calibrate arms: starting pos = 0 deg;
  claw.setMaxTorque(100, percent);
  frontarms.setMaxTorque(100, percent);
  backarm.setMaxTorque(100, percent);
  isFrontRaised = false;
  isBackRaised = true;
  while(moveClawToAngle(frontarmpot.value(degrees), 240)){} // move the claw down to a starting position
  
  // claw.spinFor(forward, .8, turns); // lower claw (frontarms already start lowered)
  // backarm.spinFor(forward, .6, turns, false); // lower backarm
  
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // reading sensor values
    clawAngle = frontarmpot.value(degrees);
    //std::cout <<  clawAngle << std::endl; // log the angle

    // A and B to pick up and set down goals with the front
    if(Controller1.ButtonA.pressing()){
      APressed(); // pick up front
      while(Controller1.ButtonA.pressing()); // will stop the code here until button is released
    }
    if(Controller1.ButtonB.pressing()){
      BPressed(); // put down front
      while(Controller1.ButtonB.pressing()); // will stop the code here until button is released
    }
    // X and Y to pick up and set down goals with the back
    if(Controller1.ButtonX.pressing()){
      XPressed(); // pick up back
      while(Controller1.ButtonX.pressing()); // will stop the code here until button is released
    }
    if(Controller1.ButtonY.pressing()){
      YPressed(); // put down back
      while(Controller1.ButtonY.pressing()); // will stop the code here until button is released
    }
    
    // if the controls for backarm aren't being used or the backarm has been raised the position will hold
    if(isBackRaised && (!Controller1.ButtonUp.pressing() && !Controller1.ButtonDown.pressing())) {
      backarm.stop(hold);
    } else if(!Controller1.ButtonUp.pressing() && !Controller1.ButtonDown.pressing()) {
      backarm.stop(hold);
    }
    // if the controlls for the front arms and claws aren't being used or the frontarm has been raised the position will hold
    if(isFrontRaised) {
      frontarms.stop(hold);
      claw.stop(hold);
    } else {
      if(!Controller1.ButtonL1.pressing() && !Controller1.ButtonL2.pressing()) {
        claw.stop(hold);
      }
      if(!Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing()) {
        frontarms.stop(hold);
      }
    }

    // if claw is being controlled make sure it's not going past maximum range
    if((Controller1.ButtonUp.pressing() && clawAngle >= 240) || (Controller1.ButtonDown.pressing() && clawAngle <= 2)) {
      claw.stop(hold);
      while(Controller1.ButtonUp.pressing());
    }
    if(claw.isSpinning() && (clawAngle >= 240 || clawAngle <= 2)) {
      claw.stop(hold);
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
