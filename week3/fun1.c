#include <stdio.h>

#if 1

//void swap(int a, int b);
void swap(int x, int y);
void swap2(int x, int y);
int  swap3(int x, int y);
void  swap4(int arr[]);

int global = 10;

void swap4(int arr[])
{
	int t;
	t = arr[0];
	arr[0] = arr[1];
	arr[1] = t;
}


void main()
{
	
	int x, y;
	int t;
	printf("g=%d\n", global);
	int array[2] =  {0};
	do{
		scanf("%d%d", &x, &y);
		printf("addr : %p,%p\n", &x, &y);
		//swap(x, y);
		//swap2(x, y);
		//x = swap3(x,y);
	    //y = swap3(x, y); 	
		array[0] = x;
		array[1] = y;
		swap4(array);
		printf("x=%d,y=%d\n", array[0], array[1]);
	}while(x!=0 && y!=0);

	return ;
}

//void swap( )
void swap(int x, int y)
{	
		printf("enter swap\n");
		int t ;
		t = x;
		x = y;
		y = t;		
		printf("addr : %p,%p\n", &x, &y);
		printf("x=%d,y=%d\n", x, y);
		printf("leave swap\n");
}
void swap2(int x, int y)
{	
		printf("enter swap\n");
		int t ;
		static int cnt=0;
		cnt++;
		printf("cnt=%d\n", cnt);
		t = x;
		x = y;
		y = t;		
		printf("leave swap\n");
}

int swap3(int x, int y)
{	
		printf("enter swap\n");
		int t ;
		static int cnt=0;
		cnt++;
		printf("cnt=%d\n", cnt);
		t = x;
		x = y;
		y = t;		
		printf("leave swap\n");
		return 0;
		//return x, y;
		//------------------
		//return x;
		//return y;
}


#endif

