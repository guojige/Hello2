#include "file.h"


void save_map(game_t *game)
{
	FILE *fp;
	fp = fopen(MAPNAME, "w");
		// sizeof(game)  == 4    sizeof(*game) == sizeof(game_t)
	fwrite( game , sizeof(game_t), 1,fp);

	fclose(fp);
		
}


// 0:success , 1 failed
int  load_map(game_t *game)
{
	FILE *fp;
	fp = fopen(MAPNAME, "r");
		// sizeof(game)  == 4    sizeof(*game) == sizeof(game_t)
	fread( game , sizeof(game_t), 1,fp);

	fclose(fp);
}
