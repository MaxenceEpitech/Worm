/*
** init_event.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct 20 13:55:45 2017 maxence.fourrier
** Last update Fri Oct 20 14:27:54 2017 maxence.fourrier
*/

#include "worm.h"

t_explod	**init_explod()
{
  t_explod	**explod;
  int		i;

  if ((explod = malloc(sizeof(t_explod *) * (NB_EXPLOD + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < NB_EXPLOD)
    {
      if ((explod[i] = malloc(sizeof(t_explod))) == NULL)
	return (NULL);
      explod[i]->pos = vector2i(0, 0);
      explod[i]->draw = 0;
      explod[i]->cpt = 0;
      explod[i]->alive = 0;      
    }
  explod[i] = NULL;
  return (explod);
}

t_shoot		**init_shoot()
{
  int		i;
  t_shoot	**shoot;

  if ((shoot = malloc(sizeof(t_shoot *) * (NB_EXPLOD + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < NB_EXPLOD)
    {
      if ((shoot[i] = malloc(sizeof(t_shoot))) == NULL)
        return (NULL);
      shoot[i]->pos = vector2f(0, 0);
      shoot[i]->dir = vector2f(0, 0);
      shoot[i]->alive = 0;
    }
  shoot[i] = NULL;
  return (shoot);
}
