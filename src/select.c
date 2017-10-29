/*
** select.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct 20 17:37:37 2017 maxence.fourrier
** Last update Sat Oct 21 18:42:22 2017 maxence.fourrier
*/

#include "worm.h"

void		event_select(t_worm *worm)
{
  if (sfKeyboard_isKeyPressed(sfKeyTab)
      && !wait_key(worm->graph->window, sfKeyTab)
      && player_alive(worm->player[worm->game->turn]) > 0)
    {
      worm->game->select++;
      if (worm->game->select >= TOTAL_PLAYER / 2)
        worm->game->select = 0;
      while (worm->player[worm->game->turn][worm->game->select]->hp < 0)
        {
          worm->game->select++;
          if (worm->game->select >= TOTAL_PLAYER / 2)
            worm->game->select = 0;
        }
    }
}

void		check_select_worm(t_worm *worm)
{
  if (worm->player[worm->game->turn][worm->game->select]->hp < 0
      && player_alive(worm->player[worm->game->turn]) > 0)
    {
      worm->game->select++;
      if (worm->game->select >= TOTAL_PLAYER / 2)
	worm->game->select = 0;
      while (worm->player[worm->game->turn][worm->game->select]->hp < 0)
	{
          worm->game->select++;
          if (worm->game->select >= TOTAL_PLAYER / 2)
            worm->game->select = 0;
	}
    }
}
