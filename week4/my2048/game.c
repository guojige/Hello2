#include "game.h"
#include "termios_control.h"

static void random_value(game_t *game)
{
	int pos;
	int value;
	int cnt=0;
	int empty[16] = {0};
	int i, j;
	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
			if(game->map[i][j] == 0)
				empty[cnt++] = 4 * i + j;
	
	if(cnt==0)
	{	//game over
		game->status = FAILED;
		return ;
	}
	
	pos = empty[random()%cnt];
	i = pos / 4;
	j = pos % 4;
	value = ( random()%10 ) ? 2 : 4; 	
	
	game->map[i][j] = value;
	
}

#if 0
static void random_value(game_t *game)
{
	int ipos, jpos;
	int value;
	
	while(1)
	{
		ipos = random()%4;
		jpos = random()%4;
		value = ( random()%10 ) ? 2 : 4; 
		if(game->map[ipos][jpos] == 0)
		{
			game->map[ipos][jpos] = value;
			break;
		}
	}
	
}
#endif 


void game_init(game_t *game)
{
	game->score = 0;
	game->step = 0;
	game->status = PLAYING;
	//game->map[4][4] = {0}  error
	memset(game->map, 0, sizeof(int)*4*4);
	random_value(game);
	random_value(game);
}


dir_t get_dir()
{
	char ch;
	while(1)
	{
		//ch = getchar();  // scanf("%c", &ch);
		ch = my_getch();
		if(ch == '\n')
			continue;
		else if(ch == 'a')
			return LEFT;
		else if(ch == 'w')
			return UP;
		else if(ch == 's')
			return DOWN;
		else if(ch == 'd')
			return RIGHT;
		else if(ch == 'q')
			return EXIT;
	}	
}


void merge(game_t *game, dir_t dir)
{
   int box[4][4] = {0};
   int i, j;
   int deep;
   int moved=-1, mline = 0;
   
   for(i=0; i<4; i++)
      for(j=0; j<4; j++)
         box[i][j] = game->map[i][j];

   if(dir == RIGHT){
      for(i=0; i<4; i++){  // row
         deep = 3;
         mline = 0;
         for(j=3; j>=0; j--){
            if(box[i][j] != 0){
               box[i][deep] = box[i][j];  // move to right
               if(deep != j)
                  box[i][j] = 0;
               if(deep < 3 && mline == 0 && box[i][deep] == box[i][deep+1]){
                  game->score += box[i][deep+1];
                  box[i][deep+1] *= 2;
                  box[i][deep] = 0;
                  mline = 1;
               }
               else
                  deep--;
            }
         }

      }
   }

   if(dir == LEFT){
      for(i=0; i<4; i++){  // row
         deep = 0;
         mline = 0;
         for(j=0; j<4; j++){
            if(box[i][j] != 0){
               box[i][deep] = box[i][j];  // move to left
               if(deep != j)
                  box[i][j] = 0;
               if(deep > 0 && mline == 0 && box[i][deep] == box[i][deep-1]){
                  game->score += box[i][deep-1];
                  box[i][deep-1] *= 2;
                  box[i][deep] = 0;
                  mline = 1;
               }
               else
                  deep++;
            }
         }
      }
   }

   if(dir == UP){
      for(j=0; j<4; j++){  // col
         deep = 0;
         mline = 0;
         for(i=0; i<4; i++){
            if(box[i][j] != 0){
               box[deep][j] = box[i][j];  // move to up
               if(deep != i)
                  box[i][j] = 0;
               if(deep > 0 && mline == 0 && box[deep][j] == box[deep-1][j]){
                  game->score += box[deep-1][j];
                  box[deep-1][j] *= 2;
                  box[deep][j] = 0;
                  mline = 1;
               }
               else
                  deep++;
            }
         }
      }
   }
   if(dir == DOWN){
      for(j=0; j<4; j++){  // row
         deep = 3;
         mline = 0;
         for(i=3; i>=0; i--){
            if(box[i][j] != 0){
               box[deep][j] = box[i][j];  // move to down
               if(deep != i)
                  box[i][j] = 0;
               if(deep < 3 && mline == 0 && box[deep][j] == box[deep+1][j]){
                  game->score += box[deep+1][j];
                  box[deep+1][j] *= 2;
                  box[deep][j] = 0;
                  mline = 1;
               }
               else
                  deep--;
            }
         }
      }
   }
     
   for(i=0; i<4; i++)
   {
      for(j=0; j<4; j++)
         {
            game->map[i][j] = box[i][j];
            if(game->map[i][j] == 2048)
               game->status = SUCCESS;
         }
	}
}		
	


void update_map(game_t *game, dir_t dir)
{
	if(dir == EXIT)
	{
		game->status = STOP;
		return;
	}
	if(game->status == FAILED)
		return ;
		
	game->step++;
	
	merge(game, dir);
	
	random_value(game);	
}
