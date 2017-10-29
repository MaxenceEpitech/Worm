/*
** move.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct 20 14:37:13 2017 maxence.fourrier
** Last update Sun Oct 22 12:26:55 2017 maxence.fourrier
*/

#include "worm.h"

void		move(t_worm *worm, int dir,
		     t_player *player, int **map)
{
  if (player->walk > 0 && player->pos.y > 0
      && check_wall(player, map, dir))
    {
      if (player->walk % 10 == 0)
	draw_player_framebuffer_walk(player);
      player->walk -= 2;
      player->dir = dir;
      if (player->pos.x + dir * MOVE_SPEED > 15
	  && player->pos.x + dir * MOVE_SPEED < SCREEN_WIDTH - 15)
	player->pos.x += dir * MOVE_SPEED;
    }
}

int		can_jump(sfVector2f pos, int **map)
{
  sfVector2i	cpt;

  if ((cpt.y = pos.y - 15) > SCREEN_HEIGHT - 1
      || cpt.y < 0)
    return (SUCCESS);
  while (--cpt.y > 0 && cpt.y > pos.y - 32)
    {
      cpt.x = pos.x - 6;
      if (cpt.x < 0)
	cpt.x = 0;
      if (cpt.x > SCREEN_WIDTH)
	cpt.x = SCREEN_WIDTH - 6;
      while (map[cpt.y][++cpt.x] && cpt.x < pos.x + 6)
	if (map[cpt.y][cpt.x] == 1)
	  return (SUCCESS);
    }
  return (1);
}

int		check_down_player_(sfVector2f pos, int **map)
{
  sfVector2i    cpt;

  if ((cpt.y = pos.y + 5) > SCREEN_HEIGHT - 1
      || cpt.y < 0)
    return (SUCCESS);
  while (cpt.y > pos.y)
    {
      if ((cpt.x = pos.x - 10) < 0)
	cpt.x = 0;
      while (map[cpt.y][++cpt.x] != -1
	     && cpt.x < pos.x + 10)
	if (map[cpt.y][cpt.x] == 1)
	  return (1);
      cpt.y--;
    }
  return (SUCCESS);
}

void		jump(t_worm *worm, t_player *player, int **map)
{
  if (player->jump <= 0
      && ((sfKeyboard_isKeyPressed(sfKeySpace)
	   && !wait_key(worm->graph->window, sfKeySpace))
	  || (sfKeyboard_isKeyPressed(sfKeyZ)
	      && !wait_key(worm->graph->window, sfKeyZ)))
      && check_down_player_(player->pos, map))
    player->jump = JUMP;
  if (player->jump > 0 && !can_jump(player->pos, map))
    player->jump = 0;
  else if (player->jump > 0)
    {
      player->jump--;
      player->pos.y -= 0.01 * player->jump;
    }
}

void		event_move(t_worm *worm)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft)
      || sfKeyboard_isKeyPressed(sfKeyQ))
    move(worm, -1, worm->player[worm->game->turn]
	 [worm->game->select], worm->map);
  if (sfKeyboard_isKeyPressed(sfKeyRight)
      || sfKeyboard_isKeyPressed(sfKeyD))
    move(worm, 1, worm->player[worm->game->turn]
	 [worm->game->select], worm->map);
  jump(worm, worm->player[worm->game->turn]
       [worm->game->select], worm->map);
}
