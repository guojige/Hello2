#include <stdio.h>  // printf scanf
#include <wiringPi.h>  

int main()
{
	wiringPiSetup();
	pinMode(8, OUTPUT);
	//pinMode(8, LOW);  //D0 000
	digitalWrite(8, LOW);
	softPwmCreate(9, 0, 100);
	softPwmCreate(7, 0, 100);
	softPwmCreate(0, 0, 100);
	
	
	while(1)
	{
		softPwmWrite(9, 0);
		//softPwmWrite(7, 255);
		//softPwmWrite(0, 255);
		delay(1000);
		softPwmWrite(9, 100);
		//softPwmWrite(7, 255);
		//softPwmWrite(0, 100);
		delay(1000);
		
	}
	return 0;
}
