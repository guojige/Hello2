#include "ptr.h"


void pointer_test1()
{	
	char *pch;
	int *pi;
	float *pf;

	printf("size: %d,%d,%d\n", sizeof(pch), sizeof(pi), sizeof(pf));	
	printf("addr:%p,%p,%p\n", &pch, &pi, &pf);

	printf("value-addr:%p,%p,%p\n", pch, pi, pf);


	char ch = 'A';
	int i = 65;
	float f = 11.1;

	pch = &ch;
	pi = &i;
	pf = &f;

	printf("var addr:%p,%p,%p\n", &ch, &i, &f);
	printf("value-addr:%p,%p,%p\n", pch, pi, pf);

	printf("point value:%c,%d,%f\n", *pch, *pi, *pf);
}
void pointer_test2()
{
	int *px;
	px = NULL;  //  (void *)0	
	printf("%p\n", px);
	//printf("%d\n", *px);

	int *py;
	printf("%p\n", py);
	printf("%d\n", *py);

	char *pc;
	printf("%p\n", pc);
	printf("%c\n", *pc);
		

}

void pointer_test3()
{

#if 0
	int arr[] = {1,2,3,4,5};
	int i;
	printf("first:%p\n", arr);
	for(i=0;i<5;i++)
		printf("%p\n", &arr[i]);
	int *p = arr;
	printf("p point addr : %p\n", p);
	printf("p point val  : %d\n", *p);

	// next value
	printf("%d,%d,%d,%d,%d\n",
			*(p+0), *(p+1), *(p+2), *(p+3), *(p+4)
			);

	printf("p point addr : %p\n", p);
	
	p = arr;
	for(i=0; i<5; i++)
	{
		printf("%p,%d\n", p, *p);
		p++;
	}
	
#endif 

	int arr[] = {1,2,3,4,5};
	int *pa = arr;  // 1
	int *pb = arr+4;  // 5
	
	printf("pos=%d\n", pb-pa);

	for(pa=arr; pa<=pb; pa++)
		printf("%d\n", *pa);





}

int  mystrlen(char *str)  // char str[]
{
	char *p = str;
	int cnt=0;
	while(*p != '\0')
	{
		cnt++;
		p++;
	}
	return cnt;
}
int  mystrcmp(char *str1, char *str2)
{
	char *p1 = str1;
	char *p2 = str2;
	while(1)
	{
		if(*p1 > *p2)
			return 1;
		else if(*p1 < *p2)
			return -1;
		else if(*p1 == *p2)
		{
			if(*p1 == '\0')
				return 0;
			else 
			{
				p1++;
				p2++;
			}
		}
	}

}
void mystrcpy(char *dst, char *src)
{
	while(*src != '\0')
	{
		//  *dst++ = *src++;  // (*dst)++ = (*src)++
		*dst = *src;
		dst++;
		src++;
	}   
	*dst = '\0';
}
void mystrcat(char str1[], char str2[])
{
	char *p1 = str1;
	char *p2 = str2;
	while(*p1 != '\0')
		p1++;
	
	while(*p2 != '\0')
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';



}


void pointer_test4()
{
	char str[20];
	char *pstr = "hello";
	mystrcpy(str, pstr);
	puts(str);
	printf("%d\n", mystrcmp(str, pstr))	;
	mystrcat(str, pstr);
	//mystrcat(pstr, str);  error
	puts(str);
}


static void move_data(int arr[], int len, int num)
{
	printf("%s\n", __FUNCTION__);
	int t;
	int i;
	t = arr[0];  // t = *arr;
	for(i=0; i<len-1; i++)
		arr[i] = arr[i+1];
	arr[i] = t;
	
	num--;
	if(num)
		move_data(arr, LENGTH, num);


}


void pointer_test5()
{	
	int arr[LENGTH];
	//array_init(arr, LENGTH);	
	move_data(arr, LENGTH, 3);
	//array_display(arr, LENGTH);	
}
void pointer_test6()
{
	int a = 10;
	int *pa = &a;  // stack
	int *pb = (int *)malloc(4);  // heap
	*pb = -10;
	*pa += *pb;  // a += -10
	free(pb);
	pb = NULL;
	printf("*pa=%d\n", a);
	//pb = 10;	// error

	char *pch = (char *)malloc(6);
	*(pch+0) = 'h';
	*(pch+1) = 'e';
	*(pch+2) = 'l';
	*(pch+3) = 'l';
	*(pch+4) = 'o';
	*(pch+5) = '\0';
	puts(pch);
	free(pch);
	pch = NULL;

}

void pointer_test7()
{
	int array[10] = {1,2,3,4,5};
	int *pa;

	pa = array;

	printf("pa:%p,array:%p\n", pa, array);
	printf("*pa:%d,*array:%d\n", *pa, *array);
	printf("*(pa+2):%d,*(array+2):%d\n", *(pa+2), *(array+2));
	printf("pa[4]:%d,array[4]:%d\n", pa[4], array[4]);


	printf("szie,pa:%d,array:%d\n", sizeof(pa), sizeof(array));
	pa++;
	printf("*pa:%d\n", *pa);
	//array++;
	//printf("*pa:%d\n", *array);
	
	int y =10;
	y++;
	const int x=10;
	//x = 10;
	//x++;


}


void pointer_test8()
{
	int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

	printf("size:%d\n", sizeof(arr));
	printf("size:arr[0]:%d,arr[1]:%d,arr[2]:%d\n", sizeof(arr[0]), sizeof(arr[1]), sizeof(arr[2]));

	printf("addr:%p\n", arr);
	printf("addr:arr[0]:%p,arr[1]:%p,arr[2]:%p\n", arr[0], arr[1], arr[2]);

	printf("arr+0:%p, arr+1:%p, arr+2:%p\n", arr+0, arr+1, arr+2);

}

void swapptr(int *x, int *y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

void pointer_test9()
{
	int a=10,b=20;
	swapptr(&a, &b);
	printf("a:%d,b%d\n", a, b);	
}

char *retPointer()
{
	char str[10] = "hello";
	printf("re:%p,%s\n", str, str);
	//char *ps = str;
	return str;
}
char *retPointer1(char arr[])
{
	strcpy(arr, "hello");
	return arr;
}

char *retPointer2()
{
	char *arr = (char *)malloc(10);
	strcpy(arr, "hello");
	return arr;
}




void pointer_test11()
{

#if 0	
	char *p = retPointer();
	printf("p11:%p\n", p);
	puts(p);	
#endif 
	
#if 0
	char str[20];
	char *p = retPointer1(str);		//   arr = str  ,  p = arr
	puts(p);	
#endif 

	char *p = retPointer2();
	puts(p);
	free(p);
	



}

















