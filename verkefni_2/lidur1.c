#pragma config(Motor,  port3,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port2,           leftMotor,     tmotorNormal, openLoop)
int counter = 1;
double timi = 0.735;													//timi sem tekur velmennid ad keyra 0,5m
int BASETIME = timi*1000;											//breytir sekundum yfir i millisekundur

//thetta fall faer velemennid til ad keyra afram
void drive_forward(int k)
{
	motor[leftMotor] = 127;											//vinstri motorinn keyrir a fullum krafti fram a vid
	motor[rightMotor] = 127;										//haegri motorinn keyrir a fullum krafti fram a vid
	wait1Msec(k);																//keyrir thetta fall i k millisekundur
}
//thetta fall laetur velmennid keyra afturabak
void drive_backward(int k)
{
	motor[leftMotor] = -127;										//vinstri motorinn keyrir a fullum krafti afturabak
	motor[rightMotor] = -127;										//haegri motorinn keyrir a fullum krafti afturabak
	wait1Msec(k);																//keyrir fallid i k margar millisekundur
}
//fallid sem stoppar alla virkni velmennisins i akvedid langan tima
void stop_motor(int k)
{
	motor[leftMotor] = 0;												//her er vinstri motorinn gerdur ovirkur
	motor[rightMotor] = 0;											//her er haegri motorinn gerdur ovirkur
	wait1Msec(k);																//timinn sem thetta fall er latid keyra i
}
task main()
{

	wait1Msec(2000);														// Velmennid er latid bida i 2000 millisekunudur i byrjun
	while(counter < 6)													//a medan teljari er minni en 6 tha er kodinn keyrdur
	{
		drive_forward(BASETIME*counter);					//drive_forward fallid keyrt i 735 millisekundur sinnum teljari
		stop_motor(500);													//motorinn er stoppadur i 500 millisekundur
		drive_backward(BASETIME*counter);					//drive_backward er keyrt i 735 millisekundur sinnum teljari
		stop_motor(500);													//motorinn stoppadur i 500 millisekundur
		counter++;																//teljari er haekkdur um einn eftir hvern hrings
	}
}
