#include <stdio.h>

int main()
{

	char str[64];
	scanf("%s", str);
	int i=0;
	char ch;
	int cnt = 0;
#if 1
	while( str[i] != '\0')
	{
	//do{
		if(cnt==0)
		{
			ch = str[i];
			cnt++;
			i++;
		}
		else if(str[i] == ch)
		{
			cnt++;
			i++;
		}
		else
		{
			printf("ch=%c,times=%d\n", ch, cnt);
			cnt=0;
		} 
	}			
	//}while( str[i] != '\0');
	printf("ch=%c,times=%d\n", ch, cnt);

#endif 

#if 0
	char str2[64];
	int j=0;
	while( str[i] != '\0')
	{
		if(cnt == 0)
		{
			str2[j++] = str[i++];		
			cnt++;
		}
		else if(str[i] == str2[j-1])
		{	
			i++;
			cnt++;
		}
		else{
			cnt=0;	
		}

	}
	str2[j] = '\0';
	puts(str2);
#endif


#if 0
	int j=0;
	//int k=0;
	//char str3[k++] = str[i++];
    str[j++] = str[i++];
   for(i=1; str[i] != '\0'; i++)
   {		
		if(str[i] == str[i-1])
			continue;
		else
		{
			// str3[k++] = str[i];
			str[j++] = str[i];	
		}	
   }	   
	str[j] = '\0';
	puts(str);


#endif














	return 0;
}
