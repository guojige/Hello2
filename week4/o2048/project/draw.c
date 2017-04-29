#include <stdio.h>
#include "draw.h"
#include "color.h"

void draw_form(int box[])
{
        int i, j;
        static int step = 0;
        static int point = 0;
        printf("\033[2J");
        printf("\033[?25l");
        //printf("\033[?25h");
        printf("steps: %4d \tpoints: %10lu \n", step++, point++);

        for(i=0; i<4;i++){
                printf("\033[30;1m---------------------------------\n");
                printf("\033[30;1m|       |       |       |       |\n");
                for(j=0; j<4; j++){
                        printf("\033[30;1m|");
                        print_number(box[4*i+j]);
                }
                printf("\033[30;1m|\n");
                printf("\033[30;1m|       |       |       |       |\n");
        }
        printf("\033[30;1m---------------------------------\n");
}
/*
int main(int argc, char **argv)
{
        int box[16] = {2,0,4,8};
        draw_form(box);
        return 0;
}*/
