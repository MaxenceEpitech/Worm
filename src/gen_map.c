/*
** gen_map.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Oct 17 12:13:11 2017 maxence.fourrier
** Last update Wed Oct 18 23:23:57 2017 maxence.fourrier
*/

#include "worm.h"

int		get_height(int pos, int *smooth, int power, int prev)
{
  int		height;

  if (smooth[pos] == 0)
    height = my_rand(prev - power, prev);
  else if (smooth[pos] == 1)
    height = my_rand(prev, prev + power);
  else if (smooth[pos] == 2)
    height = my_rand(prev - (power / 3), prev + (power / 3));
  if (height > SCREEN_HEIGHT - BORDER)
    height = SCREEN_HEIGHT - BORDER;
  if (height < BORDER * 2)
    height = BORDER * 2;
  return (height);
}

int		**gen_map(int **map, int *smooth)
{
  sfVector2i	cpt;
  int		height;
  int		prev;
  int		power;

  cpt.x = -1;
  height = my_rand((SCREEN_HEIGHT / 2) - BORDER,
		   (SCREEN_HEIGHT / 2) + BORDER);
  power = my_rand(POWER_MIN, POWER_MAX);
  while (++cpt.x < SCREEN_WIDTH)
    {
      if (cpt.x % 10 == 0)
	power = my_rand(POWER_MIN, POWER_MAX);
      prev = height;
      height = get_height(cpt.x, smooth, power, prev);
      cpt.y = (SCREEN_HEIGHT - 1) - height;
      while (cpt.y < SCREEN_HEIGHT)
	{
	  map[cpt.y][cpt.x] = 1;
	  cpt.y++;
	}
    }
  return (map);
}

int		get_total_mountain(int **map)
{
  sfVector2i	vec;
  int		cpt;

  cpt = 0;
  vec.y = -1;
  while (map[++vec.y] && (vec.x = -1))
    while (map[vec.y][++vec.x] != -1)
      if (map[vec.y][vec.x] == 1)
	cpt++;
  return (cpt);
}

int		create_map(int **map, int *smooth)
{
  map = gen_map(map, smooth);
  while (get_total_mountain(map)
	 < ((SCREEN_HEIGHT * SCREEN_WIDTH) / 2) / 1.1
         || get_total_mountain(map)
	 > ((SCREEN_HEIGHT * SCREEN_WIDTH) / 2) * 1.1)
    {
      if ((map = fill_map(map)) == NULL
          || (smooth = gen_smooth()) == NULL)
        return (ERROR);
      map = gen_map(map, smooth);
    }
  return (SUCCESS);
}
