#pragma config(Sensor, dgtl7,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop, reversed)

//Make the robot go, forward for half a meter, turn left, forward half a meter, turn right, forward half a meter, turn right, than go forward half a meter
int distance = 573; // half a meter distance calculated with chaft encoders
float someDegree = 113.097/31.41; // How far the wheels have to go for 1 degree
float degree;
float oneDegree = someDegree - 0.9; // fix the distance for one degree
void drive_forward() // function for driving forward using distance
{
	while(abs(SensorValue[rightEncoder]) < distance)
  {
    if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder]))
		{
			//if both wheels have gone equally far, drive both motors at same speed
			motor[rightMotor] = 63;
			motor[leftMotor]  = 63;
		}
		else if (abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))	// If rightEncoder has counted more encoder counts
		{
			//Different motor powers to even out the drive
			motor[rightMotor] = 63;
			motor[leftMotor]  = 33;
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[rightMotor] = 33;   // Right Motor is run at power level 80
			motor[leftMotor]  = 63;   // Left Motor is run at power level 60
		}

  }
}
void drive_backward() //Fucntion for driving backward
{
	while(SensorValue[rightEncoder] < distance) // While the right encoder is less than distance:
  {
    if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder])) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move backward if both wheels have gone equally far
			motor[rightMotor] = -63;		    // Right Motor is run at power level -63
			motor[leftMotor]  = -63;		    // Left Motor is run at power level -63
		}
		else if (abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right, different motor powers to even out the drive
			motor[rightMotor] = -43;		    // Right Motor is run at power level -43
			motor[leftMotor]  = -63;		    // Left Motor is run at power level -63
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[rightMotor] = -43;		    // Right Motor is run at power level -43
			motor[leftMotor]  = -63;		    // Left Motor is run at power level -63
		}

  }
}
void stop_motor()
{
	motor[leftMotor] = 0;												//her er vinstri motorinn gerdur ovirkur
	motor[rightMotor] = 0;											//her er haegri motorinn gerdur ovirkur
	wait1Msec(500);																//timinn sem thetta fall er latid keyra i
}
void nullEncoder() //reset the encoders
{
	SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  SensorValue[leftEncoder]  = 0;    /* consistancy and accuracy. */
}

void turnright(int degrees) //function for turning right
{
	degree = oneDegree * degrees; // calcualting how many degrees it needs to turn
	while(abs(SensorValue[rightEncoder]) < degree) // While the right encoder is less than distance:
  {
		// spins right around itself
		motor[rightMotor] = -63;		    // Right Motor is run at power level -63
		motor[leftMotor]  = 63;		    // Left Motor is run at power level 63
  }
}
void turnleft(int degrees) //function for turning right
{
	degree = oneDegree * degrees; // calcualting how many degrees it needs to turn
	while(abs(SensorValue[rightEncoder]) < degree) // While the right encoder is less than distance:
  {
		// spins right around itself
		motor[rightMotor] = 63;		    // Right Motor is run at power level 63
		motor[leftMotor]  = -63;		    // Left Motor is run at power level -63
  }
}
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	bool killswitch = false;
	while(killswitch == false)
	{
		if(vexRT[Btn7U] == 1 || SensorValue(touchSensor) == 1)
		{
			killswitch = true;
		}
		wait1Msec(2000);                  // Wait 2000 milliseconds before continuing.
		nullEncoder();  //reset the encoder inbetween every movement
  	while(abs(SensorValue[rightEncoder]) < distance) // drive forward for half a meter
  	{
  		drive_forward();
  	}
  	stop_motor(); 	//stop the motor for hald a second between every movement
		nullEncoder();
 	  turnleft(90);	//turn around itself for 90 degrees
  	stop_motor();
  	nullEncoder();
  	while(abs(SensorValue[rightEncoder]) < distance)
  	{
  		drive_forward();
  	}
  	stop_motor();
  	nullEncoder();
  	turnright(90); // turn right around itself than just rince and repeat
  	stop_motor();
  	nullEncoder();
  	while(abs(SensorValue[rightEncoder]) < distance)
		{
  		drive_forward();
  	}
  	stop_motor();
  	nullEncoder();
  	turnright(90);
  	stop_motor();
 		nullEncoder();
  	while(abs(SensorValue[rightEncoder]) < distance)
  	{
  		drive_forward();
  	}
  	motor[rightMotor] = 0;            /* Stop the motors once desired */
  	motor[leftMotor]  = 0;            /* distance has been reached.   */
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
