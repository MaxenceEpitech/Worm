/*
** main.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Oct 17 10:49:04 2017 maxence.fourrier
** Last update Fri Oct 20 16:43:49 2017 maxence.fourrier
*/

#include <time.h>
#include "worm.h"

int		main(void)
{
  t_worm	*worm;
  int		ret;

  srand(time(NULL));
  if ((worm = init_worm()) == NULL)
    return (ERROR);
  if ((ret = game(worm)) == ERROR)
    return (ret);
  if (ret == 1)
    draw_winner(worm);
  return (SUCCESS);
}
