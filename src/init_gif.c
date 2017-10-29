/*
** init_gif.c for worms in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Oct 18 12:55:27 2017 maxence.fourrier
** Last update Fri Oct 20 17:03:11 2017 maxence.fourrier
*/

#include "worm.h"

sfSprite	**create_gif(char *str, int nb)
{
  sfSprite	**gif;
  int		i;

  if ((gif = malloc(sizeof(sfSprite *) * (nb + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < nb)
    {
      if ((gif[i] = load_picture(new_cat(new_cat(str, my_int_to_str(i)),
                                         ".png"))) == NULL)
        return (NULL);
    }
  gif[i] = NULL;
  return (gif);
}

char		*new_cat(char *start, char *end)
{
  char		*ret;
  int		i;
  int		x;

  i = 0;
  if ((ret = malloc(sizeof(char)
                    * (my_strlen(start) + my_strlen(end) + 1))) == NULL)
    return (NULL);
  while (start[i])
    {
      ret[i] = start[i];
      i++;
    }
  x = 0;
  while (end[x])
    {
      ret[x + i] = end[x];
      x++;
    }
  ret[i + x] = 0;
  return (ret);
}

sfSprite	***init_gif()
{
  sfSprite	***gif;

  if ((gif = malloc(sizeof(sfSprite **) * (NB_GIF + 1))) == NULL
      || (gif[GIF_SKY] = create_gif(GIF_SKY_NAME, GIF_SKY_TOTAL)) == NULL
      || (gif[GIF_B1] = create_gif(GIF_B1_NAME, GIF_B1_TOTAL)) == NULL
      || (gif[GIF_B2] = create_gif(GIF_B2_NAME, GIF_B2_TOTAL)) == NULL
      || (gif[GIF_B3] = create_gif(GIF_B3_NAME, GIF_B3_TOTAL)) == NULL
      || (gif[GIF_MISSILE] = create_gif(GIF_MISSILE_NAME,
					GIF_MISSILE_TOTAL)) == NULL
      || (gif[GIF_WIN] = create_gif(GIF_WIN_NAME, GIF_WIN_TOTAL)) == NULL)
    return (NULL);
  return (gif);
}
