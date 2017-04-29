#include "game.h"
#include <time.h>

int main()
{
	
	
	game_t game;
	srand(time(0));
	game_init(&game);  
	
	draw(&game);

#if 1	
	dir_t dir;
	int ret;
	while(1)
	{	
		//获得键值--代表某个方向--声明宏或者定义枚取类型
		dir = get_dir();	
		update_map(&game, dir); // 更新地图
		draw(&game);
		
		if(game.status == FAILED || game.status == SUCCESS || game.status == STOP)
			break;
	}
	
#endif 	
	return 0;
}
