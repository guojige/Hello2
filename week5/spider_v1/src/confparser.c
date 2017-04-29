#include "confparser.h"



Config *init_config()
{
	Config *gconfig = (Config*)malloc(sizeof(Config));
	//if(NULL == config)
	memset(gconfig, 0, sizeof(Config));
	

	return gconfig;
}


static char *strim(char *str)
{
	char *end, *sp, *ep;
	int len;
	sp = str;
	end = str + strlen(str) - 1;	// the last charater '\0'
	ep = end;
	while(sp<=end)
	{
		//if(*sp == ' ')
		if(isspace(*sp))
			sp++;
		else
			break;
	}
	while(ep>=sp)
	{
		if(isspace(*ep))
			ep--;
		else
			break;
	}
	//  sp,xxxxx,ep
	*(ep+1) = '\0';
	return sp;
}

// abc,cde,ddd,ttt,dddd
char **strsplit(char *line, char delimeter, int *count)
{
	char *ptr = NULL, *str = line;
	char **vector=NULL;
	//char  ss[10][10];  ss  ==> char **

	*count = 0;
#if 0	
	while((ptr=strchr(str, delimeter)))
		
	while(1)
	{		//  key=value
		ptr = strchr(str, delimeter);
		if(ptr == NULL)
			break;
		
	}
#endif 	
	while((ptr=strchr(str, delimeter)))
	{
		*ptr = '\0';  // key\0value                            0+1
		vector = (char **)realloc(vector, ( (*count+1) * sizeof(char *)));
		vector[*count] = strim(str);
		(*count)++;
		str = ptr+1;   	// str == 'v'
		break;
	}
	if(*str!= '\0')
	{										// 1+1
		vector = (char **)realloc(vector, ( (*count+1) * sizeof(char *)));
		vector[*count] = strim(str);
		(*count)++;
	}
	return vector;
	
}



 void    load_config(Config *gconfig)
{
	FILE *fp = NULL;
	fp = fopen(CONF_FILE_NAME, "r");
	char *line;
	
	if(NULL == fp)
	{
		// FIXME:  before exit , free(gconfig)
		SPIDER_LOG(SPIDER_LEVEL_ERROR,"open file %s\n", CONF_FILE_NAME);
	}
	char buff[MAX_CONF_LEN];
	char **argv;
	int argc;
	while(1)
	{
		char *pret = fgets(buff, MAX_CONF_LEN-1, fp);	//  \n\0
		buff[strlen(buff)-1] = '\0';
		if(NULL == pret)
		{
			SPIDER_LOG(SPIDER_LEVEL_INFO, "END FILe\n");
			break;
		}
		SPIDER_LOG(SPIDER_LEVEL_DEBUG, "%s\n", buff);
		line = strim(buff); // skip space
		SPIDER_LOG(SPIDER_LEVEL_DEBUG, "%s\n", line);
		if(line[0] == '#' || line[0] == '\n')
			continue;

		argv = strsplit(line,'=', &argc);
		if(argc == 2)
		{
			SPIDER_LOG(SPIDER_LEVEL_DEBUG, "key:%s, value=%s\n", argv[0], argv[1]);
			//handler
			if(strcmp(argv[0], "max_job_num") == 0)
				gconfig->max_job_num = atoi(argv[1]);
			else if(strcmp(argv[0], "seeds") ==0)
				gconfig->seeds = strdup(argv[1]); // malloc + strcpy
			else if(strcmp(argv[0], "log_level") ==0)
				gconfig->log_level = atoi(argv[1]);
			
		}
		
		//int i;
		//for(i=0;i<argc;i++)
		//	free(argv[i]);
		free(argv);
		
		
	}
	

	fclose(fp);
}


