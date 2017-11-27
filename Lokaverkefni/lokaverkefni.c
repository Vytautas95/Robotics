#pragma config(Motor,  port2,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex269, openLoop, reversed)
#pragma config(Sensor, dgtl11,          sonarSensor,   sensorSONAR_cm)
#pragma config(Sensor, dgtl4,           potentioSensor,      sensorPotentiometer)

/*---------------------------------------------------------------------------------------------------*\
|*   This program makes the robot turn around itself until it the sonar sensor pickups up a signal   *|
|*                of an object. It drives toward the object tries to knock it down.                  *|
|*      After knocking down the object it tries to find other objects that are near the robot.       *|
|*            If the robot drives over the border it turns around back to the arena.                 *|
|*    MOTORS & SENSORS:                                                                              *|
|*    [I/O Port]           [Name]              [Type]                [Description]                   *|
|*    Motor   - Port 2     leftMotor           VEX 3-wire module     Right side motor                *|
|*    Motor   - Port 3     rightMotor          VEX 3-wire module     Left side motor                 *|
|*    Motor   - Port 7     armMotor            VEX 3-wire module     Arm motor                       *|
|*    Analog  - Port 1     lineFollowerRIGHT   VEX Light Sensor      Front-right, facing down        *|
|*    Analog  - Port 2     lineFollowerCENTER  VEX Light Sensor      Front-center, facing down       *|
|*    Analog  - Port 3     lineFollowerLEFT    VEX Light Sensor      Front-left, facing down         *|
|*    Analog  - Port 4     potentioSensor      VEX Quadrature enc.   Potentiometer on the side       *|
|*    Digital - Port 5     sonarSensor         VEX Sonar Sensor      Front mounted, front facing     *|
\*----------------------------------------------------------------------------------------------4246-*/


int highpower = 127;
int lowpower = 30;
int nopower = 0;
task main()
{



}
