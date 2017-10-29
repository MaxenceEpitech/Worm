/*
** init_map.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Oct 17 11:46:07 2017 maxence.fourrier
** Last update Sat Oct 21 20:02:30 2017 maxence.fourrier
*/

#include "worm.h"

int		**fill_map(int **map)
{
  sfVector2i	cpt;

  cpt.y = -1;
  while (++cpt.y < SCREEN_HEIGHT && (cpt.x = -1))
    {
      while (++cpt.x < SCREEN_WIDTH)
	map[cpt.y][cpt.x] = 0;
      map[cpt.y][cpt.x] = -1;
    }
  map[cpt.y] = NULL;
  return (map);
}

int		*gen_smooth()
{
  int		*map;
  int		size;
  int		cpt;
  int		dir;

  if ((map = malloc(sizeof(int *) * (SCREEN_WIDTH + 1))) == NULL)
    return (NULL);
  cpt = -1;
  while (cpt < SCREEN_WIDTH)
    {
      size = my_rand(MIN_SMOOTH, MAX_SMOOTH);
      dir = my_rand(0, 2);
      while (--size > 0 && ++cpt < SCREEN_WIDTH)
	map[cpt] = dir;
    }
  map[cpt] = -1;
  return (map);
}

int		**init_map()
{
  int		*smooth;
  int		**map;
  int		i;

  if ((map = malloc(sizeof(int **) * (SCREEN_HEIGHT + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < SCREEN_HEIGHT)
    if ((map[i] = malloc(sizeof(int *) * (SCREEN_WIDTH + 1))) == NULL)
      return (NULL);
  if ((map = fill_map(map)) == NULL
      || (smooth = gen_smooth()) == NULL
      || create_map(map, smooth) == ERROR)
    return (NULL);
  return (map);
}
