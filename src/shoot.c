/*
** shoot.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct 19 20:49:17 2017 maxence.fourrier
** Last update Sun Oct 22 14:54:27 2017 maxence.fourrier
*/

#include <math.h>
#include "worm.h"

void		draw_transparent(t_worm *worm)
{
  sfVector2i	vec;

  vec.y = -1;
  while (worm->map[++vec.y] && (vec.x = -1))
    while (worm->map[vec.y][++vec.x] != -1)
      if (worm->map[vec.y][vec.x] == 0)
        my_put_pixel(worm->graph->framebuffer, vec.x,
                     vec.y, sfTransparent);
  sfTexture_updateFromPixels(worm->graph->texture,
                             worm->graph->framebuffer->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(worm->graph->window, worm->graph->sprite, NULL);
}

int		shoot_player(t_worm *worm, t_shoot *shoot)
{
  sfVector2i	cpt;

  cpt.y = -1;
  while (worm->player[++cpt.y] && (cpt.x = -1))
    while (worm->player[cpt.y][++cpt.x])
      if (worm->player[cpt.y][cpt.x]->hp > 0
	  && (!(shoot->id.x == cpt.y && shoot->id.y == cpt.x))
	  && shoot->pos.x >= worm->player[cpt.y][cpt.x]->pos.x - 15
	  && shoot->pos.x <= worm->player[cpt.y][cpt.x]->pos.x + 15
	  && shoot->pos.y <= worm->player[cpt.y][cpt.x]->pos.y
	  && shoot->pos.y >= worm->player[cpt.y][cpt.x]->pos.y - 30)
	return (1);
  return (SUCCESS);
}

void		event_shoot(t_worm *worm, t_shoot **shoot, int **map)
{
  int		i;

  i = -1;
  while (shoot[++i])
    if (shoot[i]->alive == 1)
      {
	shoot_type(worm, shoot[i]);
	if (shoot[i]->pos.x < -50 || shoot[i]->pos.x > SCREEN_WIDTH + 50
	    || shoot[i]->pos.y < -500 || shoot[i]->pos.y > SCREEN_HEIGHT + 10)
	  shoot[i]->alive = 0;
	has_hit(worm, i, shoot, map);
      }
}

void		draw_shoot(t_worm *worm, t_shoot **shoot)
{
  int		i;
  int		angle;
  int		sprite;

  i = -1;
  sprite = SPR_MISSILE;
  while (shoot[++i])
    if (shoot[i]->alive == 1)
      {
	if (shoot[i]->type == 0)
	  sprite = SPR_SEARCH;
	angle = atan2(shoot[i]->dir.y, shoot[i]->dir.x) / M_PI * 180;
	sfSprite_setRotation(worm->sprite->gen[sprite], angle + 90);
	sfSprite_setPosition(worm->sprite->gen[sprite],
			     shoot[i]->pos);
	sfRenderWindow_drawSprite(worm->graph->window,
				  worm->sprite->gen[sprite], NULL);
      }
}
