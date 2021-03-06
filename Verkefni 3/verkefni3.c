#pragma config(Motor,  port3,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port2,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorNormal, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269, openLoop, reversed)
bool killswitch = false;//Bool sem er notud fyrir hvort thad se buid ad yta a Btn7U
/*----------------------------------------------------------------------------------------------------*\
|*                                  - Keyra velmennid med fjarstyringu -                              *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  I thessu forriti er verid ad vinna med fjastyringu sem haegt er ad nota arminn og kloina asamt    *|
|*    thvi ad vinstri joystickinn stjornar vinstri motor og haegri joystick stjornar haegri motor     *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Digital 11              sonarSensor         VEX Sonar Sensor    Front mounted, front facing     *|
|*    Motor - Port 2          leftMotor           VEX Motor           Left motor                      *|
|*    Motor - Port 3          rightMotor          VEX Motor           Right motor                     *|
\*-----------------------------------------------------------------------------------------------4246-*/
task main()
{
  while(killswitch == false) {   //While loop sem er keyrd a medan boolid er false
    motor[rightMotor]  = vexRT[Ch2];	//HaegriMotor stjornadur med haegri styripinna
    motor[leftMotor] = vexRT[Ch3];	//VinstriMotor stjornadur med vinstri styripinna

    if(vexRT[Btn6D] == 1) //Ef that er ytt a Btn6D
    {
      motor[armMotor] = 40;	//Fer armurinn nidur
    }
    else if(vexRT[Btn6U] == 1)	//Ef that er ytt a Btn6U
    {
      motor[armMotor] = -40;	//Fer armurinn upp
    }
    else //Annars
    {
      motor[armMotor] = 0;	//Motorinn fyrir arminn er settur i null
    }

    if(vexRT[Btn5U] == 1)	//Ef ytt er a Btn5U
		{
			motor[clawMotor] = 127;	//Tha opnar kloin
		}
		else if(vexRT[Btn5D] == 1)	//Ef ytt er a Btn5D
		{
			motor[clawMotor] = -127;	//Tha lokar kloin
		}
		else	//Annars
		{
			motor[clawMotor] = 0;	//Motorinn fyrir kloina er settur i null
		}
		if(vexRT[Btn7U] == 1)	//Ef ytt er a Btn7U
		{
			killswitch = true;	//Tha er killswitch sett yfir i true, sem fer ur while loopunni
		}

  }
}
