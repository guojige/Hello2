#include "color.h"
#include "termios_control.h"
#include "draw.h"
#include "game.h"

void game_init(struct game *game)
{
   memset(game, 0, sizeof(struct game));
   game->status = PLAYING;
   game->step = 0;
   game->point = 0;
}
int  check_fail(struct game *game)
{
   if(game->status == FAILED){
      return -1;
   }
   else if(game->status == DONE)
      return 1;
   else
      return 0;
}

int random_2or4(void)
{
   int val = rand() % 4;
   return val > 3 ? 4 : 2;
}

int findpostion(struct game *game)
{
   int i, pos = -1;
   int count = 0;
   int empty[16]={0};
   for(i=0; i<16; i++)
      if(game->box[i] == 0) // count empty position 
         empty[count++] = i;

   if(count == 0)
      return -1; // game over
   
   pos = empty[rand()%count];
   return pos;
}
void merge(struct game *game, enum command dir)
{
   int box[4][4] = {0};
   int i, j;
   int deep;
   int moved=-1, mline = 0;
   
   for(i=0; i<4; i++)
      for(j=0; j<4; j++)
         box[i][j] = game->box[i*4+j];

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
                  game->point += box[i][deep+1];
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
                  game->point += box[i][deep-1];
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
                  game->point += box[deep-1][j];
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
                  game->point += box[deep+1][j];
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
      for(j=0; j<4; j++)
         if(game->box[i*4+j] != box[i][j]){
            game->box[i*4+j] = box[i][j];
            game->status = PLAYING;
            game->step++;
            if(game->box[i*4+j] == 2048)
               game->status = DONE;
         }
}

void update_box(struct game *game, enum command dir)
{
   int newpos;  
   int randval;
   merge(game, dir);
   newpos = findpostion(game);
   if(newpos<0){
      game->status = FAILED;
      return ;
   }
   randval = random_2or4();
   game->box[newpos] = randval;

}

