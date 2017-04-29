#ifndef __FILE_H__
#define __FILE_H__

#include "game.h"

#define MAPNAME "map.dat"
extern void save_map(game_t *game);
extern int  load_map(game_t *game);




#endif
