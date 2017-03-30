#include <stdio.h>

//#define Debug 10


int main()
{

#ifdef MYDEG

	if(5>6)
		printf("yes\n");
	else 
		printf("no\n");	
#else

	printf("hello\n");
	
#endif


}

#if 0

int main()
{

#if Debug

	if(5>6)
		printf("yes\n");
	else 
		printf("no\n");	
#else

	printf("hello\n");
	
#endif

	return 0;
}

#endif
