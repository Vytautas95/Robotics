#pragma config(Sensor, dgtl7,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,  rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,  leftMotor,     tmotorNormal, openLoop, reversed)

int counter = 1;	//Teljari buinn til og gildid 1 sett
int distanceorg = 573;	//Breyta buin til fyrir reikninga
int distance = 573;	//Vegalengd sem er margfoldud vid teljara
void drive_forward()	//Fall sem laetur robotinn keyra afram
{
	while(abs(SensorValue[rightEncoder]) < distance)	//A medan vegalengd er lengri en hringir sem hjolid hefur farid
  {
    if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder]))	//Ef ad haegriEncoder og vinstriEncoder eru jafn hair, tha keyrir kodin fyrir nedan
		{
			motor[rightMotor] = 63;	//Haegri motor keyrdur a 63
			motor[leftMotor]  = 63;	//Vinstri motor keyrdur a 63
		}
		else if (abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))	//Ef ad haegriEncoder er haerri en vinstriEncoder
		{

			motor[rightMotor] = 63;  //Haegri motor i 63
			motor[leftMotor]  = 43;	 //Vinstri motor i 33
		}
		else	//Ef ad vinstriEncoder er haerri en haegriEncoder
		{

			motor[rightMotor] = 43;	 //Haegri motor i 33
			motor[leftMotor]  = 63;  //Vinstri motor i 63
		}

  }
}
void drive_backward()	//Fall sem laetur robotinn keyra afturabak
{
	while(SensorValue[rightEncoder] < distance)	//A medan vegalengd er lengri en hringir sem hjolid hefur farid
  {
    if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder])) //Ef ad haegriEncoder og vinstriEncoder eru jafn hair, tha keyrir kodin fyrir nedan
		{
			motor[rightMotor] = -63;	//Motor er settur a -63 svo hann fari afturabak
			motor[leftMotor]  = -63;	//Motor er settur a -63 svo hann fari afturabak
		}
		else if (abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))	//Ef ad haegriEncoder og vinstriEncoder eru jafn hair, tha keyrir kodin fyrir nedan
		{
			motor[rightMotor] = -63;	//Motor er settur a -63
			motor[leftMotor]  = -43;	//Motor er settur a -43
		}
		else	//Ef ad vinstriEncoder er haerri en haegriEncoder
		{
			motor[rightMotor] = -43;	//Motor er settur a -43
			motor[leftMotor]  = -63;	//Motor er settur a -63
		}

  }
}
void stop_motor()
{
	motor[leftMotor] = 0;	//her er vinstri motorinn gerdur ovirkur
	motor[rightMotor] = 0;	//her er haegri motorinn gerdur ovirkur
	wait1Msec(500);	//timinn sem thetta fall er latid keyra i
}
task main()
{
  wait1Msec(2000);	//Bidur i 2 sekundur



  SensorValue[rightEncoder] = 0;	//haegriEncoder er nullstilltur
  SensorValue[leftEncoder]  = 0;	//vinstriEncoder er nullstilltur


  while(abs(SensorValue[rightEncoder]) < distance)	//A medan haegriEncoder hefur minna en vegalengd
  {
  		drive_forward();	//Kallar a fallid drive_forward()
  		SensorValue[rightEncoder] = 0;	//Nullstillir haegriEncoder
  		SensorValue[leftEncoder]  = 0;	//Nullstillir vinstriEncoder
  		stop_motor();	//Kallar a fallid stop_motor() sem stoppar alla virkni i badum motorunum
  		drive_backward();	//Kallar a fallid drive_backward()
  		SensorValue[rightEncoder] = 0;	//Nullstillir haegriEncoder
  		SensorValue[leftEncoder]  = 0;	//Nullstillir vinstriEncoder
  		stop_motor();	//Kallar a fallid stop_motor() sem stoppar alla virkni i badum motorunum
  		distance = distanceorg * counter;	//Vegalengdin haekkud eftir hvern hring
  		counter++; //Teljari haekkar um einn

  }

 stop_motor(); //Kallar a fallid stop_motor() sem stoppar alla virkni i badum motorunum
}
