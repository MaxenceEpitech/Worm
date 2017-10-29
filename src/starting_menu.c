/*
** starting_menu.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Oct 18 17:12:04 2017 maxence.fourrier
** Last update Wed Oct 18 17:27:06 2017 maxence.fourrier
*/

#include "worm.h"

int		starting_menu(t_worm *worm)
{
  if (worm->game->p2 != 0 && worm->game->p2 != 0)
    while (!sfKeyboard_isKeyPressed(sfKeyEscape))
      {
	if (draw_play(worm))
	  return (1);
	if (sfKeyboard_isKeyPressed(sfKeyReturn))
	  return (SUCCESS);
      }
  return (SUCCESS);
}
