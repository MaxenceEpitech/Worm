/*
** player_alive.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct 20 16:15:52 2017 maxence.fourrier
** Last update Fri Oct 20 16:16:55 2017 maxence.fourrier
*/

#include "worm.h"

int		player_alive(t_player **player)
{
  int		i;
  int		cpt;

  i = -1;
  cpt = 0;
  while (player[++i])
    if (player[i]->hp > 0)
      cpt++;
  return (cpt);
}
