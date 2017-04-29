#ifndef CONFPARSER_H
#define CONFPARSER_H

 
#define MAX_CONF_LEN  1024
#define ITEMS	10
#define CONF_FILE     "spider.conf"

/* see the spiderq.conf to get meaning for each member variable below */
typedef struct Config {
    int              max_job_num;
    char            *seeds;
    char            *include_prefixes; 
    char            *exclude_prefixes; 
    char            *logfile; 
    int              log_level;
    int              max_depth;
    int              make_hostdir;
    int              stat_interval;

    char *           module_path;
	char **			 modules;
	int 			 mcnt;
	char **			 accept_types;
	int 			 tcnt;
} Config;

/* give default values to member variables in struct Config */
extern Config * initconfig();

/* load configuration in conf file to Config object */
extern void loadconfig(Config *conf);

extern void push_back(Config *conf, char *str);
extern void display_modules(Config *conf);

#endif
