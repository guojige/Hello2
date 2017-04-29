#include <stdio.h>
#include <time.h>
#include "draw.h"
#include "color.h"
#include "termios_control.h"
#include "game.h"

/*
int pos = 0;

void update_box(int box[], enum command dir)
{
        printf("dir = %d\n", dir);
        switch(dir){
                case UP:
                   if(pos-4>=0){
                        box[pos-4] = box[pos];
                        box[pos] = 0;
                        pos -= 4;
                   }
                   break;
                case DOWN:
                   if(pos+4 <= 15){
                        box[pos+4] = box[pos];
                        box[pos] = 0;
                        pos += 4;
                   }
                   break;
                default:
                   break;
                      
        }
}
*/

int main(int argc, char **argv)
{
       struct game game;
       int ret = 0;

       srand(time(NULL));

       game_init(&game);

        enum command dir;
        draw_form(game.box);
        while(1){
                dir = user_command();
                if(dir == QUIT)
                   return 0;
                else if(dir == INVALID)
                   continue;
                update_box(&game, dir);
                ret = check_fail(&game);
                if(ret == -1){
                     printf("GAME OVER\n");
                     return -1;
                }
                else if(ret == 1){
                     printf("YOU WIN\n");
                     return 0;
                }
                else{
                  draw_form(game.box);
                }
        }
        return 0;
}
