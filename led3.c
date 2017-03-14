#include <stdio.h>  // printf scanf
#include <wiringPi.h>  

int main()
{
	wiringPiSetup();
	pinMode(8, OUTPUT);  //D0
	
	
	pinMode(9, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(0, OUTPUT);
	
	digitalWrite(9, HIGH);
	digitalWrite(7, HIGH);
	digitalWrite(0, HIGH);
	
	digitalWrite(9, LOW);
	int total = 20;
	int time = total;
	int step = 1;
	int i;
	while(1)
	{
		time -= step;   //time = time -10;
		for(i=0; i<10;i++)
		{
			
			digitalWrite(8, HIGH);
			delay(time);
			digitalWrite(8, LOW);
			delay(total-time);
			if(time<=0)
				time = total;
		}
	}
	return 0;
}// ctrl + s    save
