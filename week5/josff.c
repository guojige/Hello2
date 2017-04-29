#include <stdio.h>

int main()	
{	
	int array[] = {1,2,3,4,5,6,7,8,9};
	int  len  = sizeof(array) / sizeof(array[0]);
	int cnt=3;
	
	int step=1;
	int index=0;	//当前的下标（数组元素，从0开始）
	while(len>1)
	{
		step++;
		//index++;
		while(1)
		{
			//index++;
			//if(index==9)
			//	index=0;
			index = (index+1)%9;	//相当于一个环
			if(array[index]!=0)		//跳过0
				break;
		}
		if(step==cnt)
		{
			printf("%d\n", array[index]);
			step=1;
			array[index] = 0;
			len--;	//有人出列
			while(1)	//从上一次走的位置，往后一位开始计数
			{
				//index++;
				//if(index==9)
				//	index=0;
				index = (index+1)%9;	//相当于一个环
				if(array[index]!=0)		//跳过0
					break;
			} 
		}
	}
	int i;
	for(i=0; i<9; i++)	
	{
		if(array[i])		//最后一个元素
		{
			printf("%d\n", array[i]); 
			break;
		}
	}
	return 0;
}	