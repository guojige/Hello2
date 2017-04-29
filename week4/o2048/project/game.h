#ifndef __GAME_H__
#define __GAME_H__

enum gamestatus
{
   PLAYING,
   FAILED,
   EXITED,
   DONE
};

struct game
{
   int box[16];
   enum gamestatus status;
   int step;
   int point;
};

void game_init(struct game *game);
int  check_fail(struct game *game);
int random_2or4(void);
int findpostion(struct game *game);
void  merge(struct game *game, enum command dir);
void update_box(struct game *game, enum command dir);

#endif
