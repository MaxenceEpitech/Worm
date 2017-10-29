/*
** move_utils.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Oct 21 19:33:44 2017 maxence.fourrier
** Last update Sat Oct 21 19:39:47 2017 maxence.fourrier
*/

#include "worm.h"

int		check_wall(t_player *player, int **map,
			   int dir)
{
  sfVector2i	cpt;

  cpt.y = player->pos.y - 20;
  cpt.x = player->pos.x + (14 * dir);
  while (--cpt.y > player->pos.y - 32)
    if (map[cpt.y][cpt.x] == 1)
      return (SUCCESS);
  return (1);
}
