#pragma config(Sensor, dgtl11,  sonarSensor,         sensorSONAR_cm)
#pragma config(Sensor, dgtl9,  touchSensor,         sensorTouch)
#pragma config(Motor,  port3,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port2,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Sensor, in4,    lightSensor,         sensorReflection)
bool killswitch = false;//Bool sem er notud fyrir hvort thad se buid ad yta a Btn7U
task main()
{
	while(killswitch == false && SensorValue(touchSensor) == 0){ //While loop that runs while the boolean is false or while the button hasn't been pressed
		if(vexRT[Btn7U] == 1)	//Ef ytt er a Btn7U
			{
				killswitch = true;	//Tha er killswitch sett yfir i true, sem fer ur while loopunni
			}
		while(killswitch == false && SensorValue(touchSensor) == 0 && SensorValue(lightSensor) < 300){   //While loop sem er keyrd a medan boolid er false and the button is pressed and while lights are turned on
				if(vexRT[Btn7U] == 1)	//Ef ytt er a Btn7U
						{
							killswitch = true;	//Tha er killswitch sett yfir i true, sem fer ur while loopunni
						}
				else if(SensorValue(sonarSensor) > 40  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 40 inches away from an object
				{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
					motor[rightMotor] = 40;			// Motor on port2 is run at (40) power forward
					motor[leftMotor]  = 40;			// Motor on port3 is run at (40) power forward
				}
				else
				{
				  motor[rightMotor] = -20; //Motor on port2 is run at 20 power backwards
					motor[leftMotor]  = -20; //Motor on port2 is run at 20 power backwards
					wait1Msec(500); // let the motors run backwards for half a second
					motor[rightMotor] = -40; //let the motors run in opposite direction to make the robot turn right on itself
					motor[leftMotor] = 40;
					wait1Msec(250); // the robot turns for 250 milliseconds

				}
			}
		while(killswitch == false && SensorValue(touchSensor) == 0 && SensorValue(lightSensor) > 300){ //While loop that runs while the boolean is false and while the button hasn't been pressed and while lights are turned off
			if(vexRT[Btn7U] == 1)	//Ef ytt er a Btn7U
			{
				killswitch = true;	//Tha er killswitch sett yfir i true, sem fer ur while loopunni
			}
			else
			{
				motor[rightMotor] = 0;			// Motor on port2 is stopped
				motor[leftMotor]  = 0;			// Motor on port3 is stopped
			}
		}
}
}
