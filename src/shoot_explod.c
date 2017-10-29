/*
** shoot_explod.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct 20 15:27:58 2017 maxence.fourrier
** Last update Sun Oct 22 14:09:13 2017 maxence.fourrier
*/

#include "worm.h"

sfVector2i	get_shoot_start(sfVector2f pos)
{
  sfVector2i	ret;

  if (pos.y - EXPLOD_RADIUS < 0)
    ret.y = -1;
  else
    ret.y = pos.y - EXPLOD_RADIUS;
  if (pos.x - EXPLOD_RADIUS < 0)
    ret.x = -1;
  else
    ret.x = pos.x - EXPLOD_RADIUS;
  return (ret);
}

sfVector2i	get_shoot_end(sfVector2f pos)
{
  sfVector2i	ret;

  if (pos.y + EXPLOD_RADIUS >= SCREEN_HEIGHT)
    ret.y = SCREEN_HEIGHT;
  else
    ret.y = pos.y + EXPLOD_RADIUS;
  if (pos.x + EXPLOD_RADIUS >= SCREEN_WIDTH)
    ret.x = SCREEN_WIDTH;
  else
    ret.x = pos.x + EXPLOD_RADIUS;
  return (ret);
}

void		shoot_explode_player(t_worm *worm, t_shoot *shoot)
{
  sfVector2i	vec;
  sfVector2i	start;
  sfVector2i	end;
  sfVector2i    cpt;
  int		dist;

  start = get_shoot_start(shoot->pos);
  end = get_shoot_end(shoot->pos);
  cpt.y = start.y;
  while (++cpt.y < end.y && (cpt.x = start.x))
    while (++cpt.x < end.x && (vec.y = -1))
      while (worm->player[++vec.y] && (vec.x = -1))
	while (worm->player[vec.y][++vec.x])
	  if ((dist
	       = get_dist_btw(vector2f(shoot->pos.x, shoot->pos.y),
			      vector2f(worm->player[vec.y][vec.x]->pos.x,
				       worm->player[vec.y][vec.x]->pos.y)))
	      <= (1.5 * EXPLOD_RADIUS))
	    {
	      worm->player[vec.y][vec.x]->hp -= 0.015;
	      draw_player_framebuffer(worm->player[vec.y][vec.x]);	      
	    }
  update_all_framebuffer(worm->player);
}

void            shoot_explode(t_worm *worm, t_shoot *shoot,
			      int **map, int radius)
{
  sfVector2i	start;
  sfVector2i	end;
  sfVector2i    cpt;

  start = get_shoot_start(shoot->pos);
  end = get_shoot_end(shoot->pos);
  cpt.y = start.y;
  while (++cpt.y < end.y && (cpt.x = start.x))
    while (++cpt.x < end.x)
      if (get_dist_btw(vector2f(shoot->pos.x, shoot->pos.y),
                       vector2f(cpt.x, cpt.y)) <= EXPLOD_RADIUS * radius)
        map[cpt.y][cpt.x] = 0;
  draw_transparent(worm);
  shoot_explode_player(worm, shoot);
}

void		has_hit(t_worm *worm, int i, t_shoot **shoot, int **map)
{
  if (shoot[i]->pos.x > 0 && shoot[i]->pos.x < SCREEN_WIDTH
      && shoot[i]->pos.y > 0 && shoot[i]->pos.y < SCREEN_HEIGHT
      && (map[(int)shoot[i]->pos.y][(int)shoot[i]->pos.x] == 1
	  || shoot_player(worm, shoot[i]) == 1))
    {
      add_explod(worm, vector2i(shoot[i]->pos.x, shoot[i]->pos.y));
      shoot_explode(worm, shoot[i], map, 1);
      shoot[i]->alive = 0;
    }
}
