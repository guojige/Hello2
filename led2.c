#include <stdio.h>  // printf scanf
#include <wiringPi.h>  

int main()
{
	wiringPiSetup();
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(0, OUTPUT);
	
	digitalWrite(9, HIGH);
	digitalWrite(7, HIGH);
	digitalWrite(0, HIGH);
	
	digitalWrite(9, LOW);
	
	int time = 100;
	int i=0;
	while(1)
	{
		time -= 10;
		for(i=0; i<3; i++)
		{
			digitalWrite(8, HIGH);
			delay(time);
			digitalWrite(8, LOW);
			delay(100-time);
		}
		if(time<=0)
			time = 100;
	}
	return 0;
}// ctrl + s    save
  //  ctrl + c   stop
	// ctrl + l   clean screan


