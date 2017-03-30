#ifndef __LOG_H__
#define __LOG_H__
 
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* macros */
#define MAX_MESG_LEN   1024

#define SPIDER_LEVEL_DEBUG 0
#define SPIDER_LEVEL_INFO  1
#define SPIDER_LEVEL_WARN  2
#define SPIDER_LEVEL_ERROR 3
#define SPIDER_LEVEL_CRIT  4 

static const char  LOG_STR[][10] = { 
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "CRIT"
};


#define SPIDER_LOG(level, format, ...) do{ \
    if (level >= log_level) {\
        time_t now = time(NULL); \
        char msg[MAX_MESG_LEN]; \
        char buf[32]; \
        sprintf(msg, format, ##__VA_ARGS__); \
        strftime(buf, sizeof(buf), "%Y%m%d %H:%M:%S", localtime(&now)); \
        fprintf(stdout, "[%s] [%s] [%d] [%s] [%s] %s\n",__FILE__, __FUNCTION__, __LINE__,  buf, LOG_STR[level], msg); \
        fflush(stdout); \
    } \
    if (level == SPIDER_LEVEL_ERROR) {\
        exit(-1); \
    } \
} while(0)



#endif
