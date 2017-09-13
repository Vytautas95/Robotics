#pragma config(Sensor, dgtl7,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop, reversed)

int counter = 4;
int distanceorg = 3000;
int distance = 3000;
void drive_forward()
{
	while(abs(SensorValue[rightEncoder]) < distance)
  {
    if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder]))
		{
			motor[rightMotor] = 63;
			motor[leftMotor]  = 63;
		}
		else if (abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))	// If rightEncoder has counted more encoder counts
		{

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
void drive_backward()
{
	while(SensorValue[rightEncoder] < distance) // While the right encoder is less than distance:
  {
    if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder])) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[rightMotor] = -63;		    // Right Motor is run at power level 80
			motor[leftMotor]  = -63;		    // Left Motor is run at power level 80
		}
		else if (abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[rightMotor] = -43;		    // Right Motor is run at power level 60
			motor[leftMotor]  = -63;		    // Left Motor is run at power level 80
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[rightMotor] = -43;		    // Right Motor is run at power level 80
			motor[leftMotor]  = -63;		    // Left Motor is run at power level 60
		}

  }
}
void stop_motor()
{
	motor[leftMotor] = 0;												//her er vinstri motorinn gerdur ovirkur
	motor[rightMotor] = 0;											//her er haegri motorinn gerdur ovirkur
	wait1Msec(500);																//timinn sem thetta fall er latid keyra i
}
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  wait1Msec(2000);                  // Wait 2000 milliseconds before continuing.

                    // 360 encoder counts is a full rotation of the axel.

  SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  SensorValue[leftEncoder]  = 0;    /* consistancy and accuracy. */


  while(abs(SensorValue[rightEncoder]) < distance)
  {
  		drive_forward();
  		SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  		SensorValue[leftEncoder]  = 0;
  		stop_motor();
  		SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  		SensorValue[leftEncoder]  = 0;
  		drive_backward();
  		SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  		SensorValue[leftEncoder]  = 0;
  		stop_motor();
  		SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  		SensorValue[leftEncoder]  = 0;
  		counter++;
  		distance = distanceorg * counter;

  }

  motor[rightMotor] = 0;            /* Stop the motors once desired */
  motor[leftMotor]  = 0;            /* distance has been reached.   */
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
