
#include "draw.h"


void draw(game_t *game)
{
	printf("\033[2J");
	//打印分值、打印步数
	printf("score:%d	step:%d\n\n", game->score, game->step);
	int i, j;
	for(i=0; i<4; i++)
	{
		
		printf("-----------------------------\n");
		printf("|      |      |      |      |\n");
			//printf("");						输出数据
		
		for(j=0; j<4; j++)
		{
			printf("|");
			if(game->map[i][j] == 0)
				//printf("%6c", ' ');
				SPACE();
			else
				//printf("%3d   ", game->map[i][j]);
				RED(game->map[i][j]);
		}
		printf("|\n");
		
		printf("|      |      |      |      |\n");
	}
	
	printf("----------------------------------\n");
}
