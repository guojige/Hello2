#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char str[] = {"hello,guojige 234567890"};
	// strtok_r(str, delimeter, saveptr)
	char **vector=NULL;
	char *p;
	char *pos;
	int cnt=0;
	while(1)
	{
		if(vector==NULL)	
		{
			p = strtok_r(str, ", ", &pos);
			if(p==NULL)
				break;
			vector = (char**)realloc(vector, ((cnt+1) * sizeof(char *)));
			vector[cnt] = p; // strdup(p);
			cnt++;
		}
		else
		{
			p = strtok_r(NULL, ", ", &pos);
			if(p==NULL)
				break;
			vector = (char**)realloc(vector, ((cnt+1) * sizeof(char *)));
			vector[cnt] = p; // strdup(p);
			cnt++;
		}
	}
	int i;
	for(i=0; i<cnt; i++)
		puts(vector[i]);

	
#if 0
	char *pstr[3];
	char *pos=NULL;
	pstr[0] = strtok_r(str, ", ", &pos);
	puts(pstr[0]);
	
	pstr[1] = strtok_r(NULL, ", ", &pos); 
	puts(pstr[1]);

	pstr[2] = strtok_r(NULL, ", ", &pos); 
	if(pstr[2] == NULL)
		printf("null\n");
	else
		puts(pstr[2]);

#endif


	return 0;	
}
