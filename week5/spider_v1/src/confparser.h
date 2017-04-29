#ifndef __CONFPARSER_H__
#define __CONFPARSER_H__

#include "spider.h"

#define MAX_CONF_LEN 1024
#define CONF_FILE_NAME "spider.conf"

typedef struct config
{
	int		max_job_num;
	char	*seeds;// malloc   // char sees[MAX_CONF_LEN];
	char	*include_prefixes;  // 
	char	*exclude_prefixes;
	char 	*logfile;	
	int		log_level;  // switch on /off  on mrico
	int		max_depth;
	int		make_hostdir;
	int  	start_interval;

	char 	*module_path;
	char 	**modules; // char [][]
	int		mcnt;

	char	**accept_types;
	int 	tcnt;
	
}Config;



extern Config *g_conf;

extern Config *init_config();
extern void    load_config(Config *gconfig);

#endif



