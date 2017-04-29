#include <stdio.h>
#include "draw.h"
#include "color.h"
#include "termios_control.h"

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

int main(int argc, char **argv)
{
        int box[16] = {2};
        pos = 0;
        enum command dir;
        draw_form(box);
        while(1){
                dir = user_command();
                if(dir == QUIT)
                   return 0;
                update_box(box, dir);
                draw_form(box);
        }
        return 0;
}
