/*
** event.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct 19 12:20:37 2017 maxence.fourrier
** Last update Sun Oct 29 18:04:24 2017 maxence.fourrier
*/

#include "worm.h"

sfVector2f	get_dir_fire(sfVector2i worm, sfVector2i click)
{
  sfVector2f	dir;
  int		dist;

  dist = get_dist_btw(vector2f(click.x, click.y),
                      vector2f(worm.x, worm.y));
  if (dist == 0)
    return (vector2f(0, 0));
  dir.x = ((float)click.x - (float)worm.x) / dist;
  dir.y = ((float)click.y - (float)worm.y) / dist;
  return (dir);
}

void		event_fire(t_worm *worm, sfVector2f pos, int type)
{
  int		i;
  sfVector2i	mouse;

  i = 0;
  while (worm->game->shoot[++i])
    if (worm->game->shoot[i]->alive == 0)
      {
	mouse = sfMouse_getPositionRenderWindow(worm->graph->window);
	worm->game->shoot[i]->dir = get_dir_fire(vector2i(pos.x, pos.y),
						 mouse);
	worm->game->shoot[i]->alive = 1;
	worm->game->shoot[i]->type = type;
	worm->game->shoot[i]->id = vector2i(worm->game->turn,
					    worm->game->select);
	worm->game->shoot[i]->pos = vector2f(pos.x - 8, pos.y - 28);
	worm->player[worm->game->turn][worm->game->select]->fire--;
	break;
      }
}

void		event(t_worm *worm)
{
  player_fall(worm);
  event_move(worm);
  event_select(worm);
  check_select_worm(worm);
  if (sfMouse_isButtonPressed(sfMouseLeft)
      && !wait_mouse(worm->graph->window)
      && worm->player[worm->game->turn][worm->game->select]->fire)
    event_fire(worm, worm->player[worm->game->turn][worm->game->select]->pos,
	       worm->player[worm->game->turn][worm->game->select]->type);
  event_shoot(worm, worm->game->shoot, worm->map);
  draw_shoot(worm, worm->game->shoot);
  draw_explod(worm);
}
