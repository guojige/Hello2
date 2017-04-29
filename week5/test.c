#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char str[3][10] = {"hello", "guojige", "234567890"};
	char *pstr[3] ;
	pstr[0] = str[0];
	pstr[1] = str[1];
	pstr[2] = str[2];
	puts(pstr[0]);
	puts(pstr[1]);
	puts(pstr[2]);

	char **vector = (char **)malloc(3 * sizeof(char *));
	//vector[0] = str[0];
	//vector[1] = str[1];
	//vector[2] = str[2];
	//puts(vector[0]);
	//puts(vector[1]);
	///puts(vector[2]);
	//*vector[0] = '9';
	//vector[0] = strdup(str[0]);   // free
	//vector[0] = (char *)malloc(sizeof(char) * (strlen(str[0])+1));
    //strcpy(vector[0], str[0]);	
	vector[0] = strdup(str[0]);   // free
	vector[1] = strdup(str[1]);   // free
	vector[2] = strdup(str[2]);   // free
	puts(vector[0]);
	puts(vector[1]);
	puts(vector[2]);
	
	printf("-----------\n");

	vector = (char **)realloc(vector, (4*sizeof(char *)));
	vector[3] = strdup("abc123");
	puts(vector[0]);
	puts(vector[1]);
	puts(vector[2]);
	puts(vector[3]);

	//vector=NULL;
	free(vector[0]);
	free(vector[1]);
	free(vector[2]);
	free(vector[3]);
	free(vector);






	return 0;	
}
