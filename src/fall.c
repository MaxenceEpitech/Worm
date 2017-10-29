/*
** fall.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct 20 17:49:33 2017 maxence.fourrier
** Last update Sat Oct 21 19:23:12 2017 maxence.fourrier
*/

#include "worm.h"

int		check_down_player(int **map, int depth,
				  sfVector2f pos, t_player *player)
{
  sfVector2i	vec;
  int		cpt;

  vec = vector2i(pos.x, pos.y + depth);
  if (vec.x - 7 < 0)
    cpt = 0;
  else
    cpt = -7;
  if (vec.y + depth >= SCREEN_HEIGHT)
    {
      player->hp = -1;
      return (SUCCESS);
    }
  while (cpt < 10 && map[vec.y][vec.x + cpt] != -1)
    {
      if (map[vec.y][vec.x + cpt] == 1)
	return (SUCCESS);
      cpt++;
    }
  return (1);
}

int		check_up_player(int **map, int depth,
				sfVector2f pos, t_player *player)
{
  sfVector2i	vec;
  int		cpt;

  vec = vector2i(pos.x, pos.y - depth);
  if (vec.x - 7 < 0)
    cpt = 0;
  else
    cpt = -7;
  if (vec.y - depth >= SCREEN_HEIGHT)
    {
      player->hp = -1;
      return (SUCCESS);
    }
  while (cpt < 10 && map[vec.y][vec.x + cpt] != -1)
    {
      if (map[vec.y][vec.x + cpt] == 1)
	return (1);
      cpt++;
    }
  return (SUCCESS);
}

void		player_fall(t_worm *worm)
{
  sfVector2i	cpt;

  cpt.y = -1;
  while (worm->player[++cpt.y] && (cpt.x = -1))
    while (worm->player[cpt.y][++cpt.x])
      {
	if (worm->player[cpt.y][cpt.x]->hp > 0
	    && check_down_player(worm->map, 0.5, worm->player[cpt.y]
				 [cpt.x]->pos, worm->player[cpt.y][cpt.x])
	    && worm->player[cpt.y][cpt.x]->jump <= 0)
	  worm->player[cpt.y][cpt.x]->pos.y += 0.5;
	if (worm->player[cpt.y][cpt.x]->hp > 0
	    && check_up_player(worm->map, 1, worm->player[cpt.y]
			       [cpt.x]->pos, worm->player[cpt.y][cpt.x])
	    && can_jump(worm->player[cpt.y][cpt.x]->pos, worm->map))
	  worm->player[cpt.y][cpt.x]->pos.y -= 1;
      }
}
