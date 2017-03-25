#include <stdio.h>  // stdio  stdin  stdout


int main()
{
	int x;   //4
	int y; //2
	char c1,c2;
/*	
	scanf("%d%d", &x, &y);
	printf("x=%d,y=%d\n", x, y);
	scanf("%c%c", &c1, &c2);
	printf("c1=%c,c2=%c\n", c1, c2);
*/
	fscanf(stdin,"%d%d", &x, &y);
	fprintf(stdout,"x=%d,y=%d\n", x, y);
	fscanf(stdin, "%c%c", &c1, &c2);
	fprintf(stdout, "c1=%c,c2=%c\n", c1, c2);
	
	return 0;
}
