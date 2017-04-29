#include "spider.h"
#include "confparser.h"

Config *g_conf;

int main()
{

	
	g_conf = init_config();
	//printf("hello,spider\n");	
	SPIDER_LOG(SPIDER_LEVEL_DEBUG, "init config %s:%d\n", __FILE__, __LINE__);
	load_config(g_conf);


	SPIDER_LOG(SPIDER_LEVEL_DEBUG ,"xxxxxxxxxxxxxxxxxxxxx");
	
	return 0;
}

