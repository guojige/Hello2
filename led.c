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
	
	while(1)
	{
		digitalWrite(8, HIGH);
		delay(1000);
		digitalWrite(8, LOW);
		digitalWrite(9, LOW);
		delay(1000);
	}
	return 0;
}// ctrl + s    save
  //  ctrl + c   stop
	// ctrl + l   clean screan

