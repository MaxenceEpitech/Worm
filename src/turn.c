/*
** turn.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct 19 11:32:48 2017 maxence.fourrier
** Last update Sun Oct 22 14:51:59 2017 maxence.fourrier
*/

#include "worm.h"

int		turn_time(t_worm *worm)
{
  if (worm->game->time + 1000 < get_time())
    {
      worm->game->time = get_time();
      worm->game->time_left--;
    }
  if (worm->game->time_left <= 0)
    return (SUCCESS);
  if (sfKeyboard_isKeyPressed(sfKeyReturn)
      && !wait_key(worm->graph->window, sfKeyReturn))
    return (SUCCESS);
  return (1);
}

void		change_turn(t_worm *worm)
{
  if (worm->game->turn == GREEN)
    worm->game->turn = RED;
  else if (worm->game->turn == RED)
    worm->game->turn = GREEN;
}

void		init_turn(t_worm *worm, t_player ***player)
{
  sfVector2i	cpt;

  cpt.y = -1;
  while (player[++cpt.y] && (cpt.x = -1))
    while (player[cpt.y][++cpt.x])
      {
	player[cpt.y][cpt.x]->type = my_rand(0, 5);
	player[cpt.y][cpt.x]->fire = NB_MISSILE;
	player[cpt.y][cpt.x]->walk = INITIAL_WALK;
	draw_framebuffer_walk_turn(player[worm->game->turn]);
      }
  worm->game->time_left = TIME_TURN;
  worm->game->time = get_time();
  worm->game->select = 0;
}

int		next_turn(t_worm *worm)
{
  sfVector2f	time;

  init_turn(worm, worm->player);
  time = vector2f(10, 10);
  while (!sfKeyboard_isKeyPressed(sfKeyEscape) && turn_time(worm)
	 && player_alive(worm->player[RED]) > 0
	 && player_alive(worm->player[GREEN]) > 0)
    {
      draw(worm);
      draw_time(worm, time);
      event(worm);
      sfRenderWindow_display(worm->graph->window);
    }
  change_turn(worm);
  return (SUCCESS);
}
