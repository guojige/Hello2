#include <stdio.h>


void f1()
{
	printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}
void f2()
{
	printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}
void f3()
{
	printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}
void f4()
{
	int z =30;
	printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}
void f5()
{
	int y = 20;
	f4();
	printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}
void f6()
{
	int x = 10;
	f5();
	printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}
void f7()
{
	static int cnt=0;
	cnt++;
	printf("start->%s:%s:%d, cnt=%d\n", __FILE__, __FUNCTION__, __LINE__, cnt);
	if(cnt==1024)
		return ;
	else
		f7();
	printf("end->%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}


int main()
{
#if 0
	f1();
	f2();
	f3();
#endif
	f7();

	return 0;
}


