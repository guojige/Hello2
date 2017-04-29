#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum game_status
{
	PLAYING,
	STOP,
	SUCCESS,
	FAILED
}status_t;

struct game_data
{
	int score;
	int step;
	status_t status;  // playing、stop、failed、success
	int map[4][4];		// int box[16];	
};
typedef struct game_data game_t;

enum dir{
	UP=1,
	DOWN,
	LEFT,
	RIGHT,
	EXIT
};
typedef enum dir dir_t;

extern void game_init(game_t *game);
extern dir_t get_dir();
extern void update_map(game_t *game, dir_t dir);







#endif
