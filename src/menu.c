/*
** menu.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Oct 18 14:29:46 2017 maxence.fourrier
** Last update Wed Oct 18 17:27:44 2017 maxence.fourrier
*/

#include "worm.h"

void		check_select(t_worm *worm)
{
  if (worm->game->current >= 6)
    {
      worm->game->current = 1;
      if (worm->game->current == worm->game->p1)
	worm->game->current++;
    }
  if (worm->game->current <= 0)
    {
      worm->game->current = 5;
      if (worm->game->current == worm->game->p1)
	worm->game->current--;
    }
}

void		select_charac(t_worm *worm)
{
  if (sfKeyboard_isKeyPressed(sfKeyRight)
      && !wait_key(worm->graph->window, sfKeyRight))
    {
      worm->game->current++;
      if (worm->game->current == worm->game->p1)
	worm->game->current++;
    }
  if (sfKeyboard_isKeyPressed(sfKeyLeft)
      && !wait_key(worm->graph->window, sfKeyLeft))
    {
      worm->game->current--;
      if (worm->game->current == worm->game->p1)
	worm->game->current--;
    }
  check_select(worm);
}

void		validate_selection(t_worm *worm)
{
  if (sfKeyboard_isKeyPressed(sfKeySpace)
      && (worm->game->p1 == 0 || worm->game->p2 == 0)
      && !wait_key(worm->graph->window, sfKeySpace))
    {
      if (worm->game->p1 == 0)
	{
	  worm->game->p1 = worm->game->current;
	  worm->game->current = 1;
	}
      else if (worm->game->p1 != 0 && worm->game->p2 == 0)
	worm->game->p2 = worm->game->current;
    }
  if (worm->game->current == worm->game->p1)
    worm->game->current++;
}

void		reset_charac(t_worm *worm)
{
  if (sfKeyboard_isKeyPressed(sfKeyReturn))
    {
      worm->game->time_left = 6;
      worm->game->p1 = 0;
      worm->game->p2 = 0;
      worm->game->current = 1;
      if (worm->game->current == worm->game->p1)
	worm->game->current++;
    }
}

int		menu(t_worm *worm)
{
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      select_charac(worm);
      reset_charac(worm);
      validate_selection(worm);
      draw_menu(worm);
      if (starting_menu(worm))
	return (SUCCESS);
    }
  return (1);
}
