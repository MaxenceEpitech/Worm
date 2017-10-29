/*
** utils.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Oct 18 14:40:47 2017 maxence.fourrier
** Last update Thu Oct 19 12:25:08 2017 maxence.fourrier
*/

#include <math.h>
#include "worm.h"

sfColor                 **create_color(char *str)
{
  sfImage               *image;
  sfColor               **color;
  sfVector2i		cpt;

  if ((image = sfImage_createFromFile(str)) == NULL
      || (color = malloc (sizeof(sfColor *) * SCREEN_HEIGHT)) == NULL)
    return (NULL);
  cpt.y = -1;
  while (++cpt.y < SCREEN_HEIGHT && (cpt.x = -1))
    {
      if ((color[cpt.y] = malloc(sizeof(sfColor) * SCREEN_WIDTH)) == NULL)
        return (NULL);
      while (++cpt.x < SCREEN_WIDTH)
	color[cpt.y][cpt.x] = sfImage_getPixel(image, cpt.x, cpt.y);
    }
  sfImage_destroy(image);
  return (color);
}

int		wait_key(sfRenderWindow *window, sfKeyCode key)
{
  sfEvent	event;

  sfRenderWindow_waitEvent(window, &event);
  while (event.type != sfEvtKeyReleased
         || event.key.code != key)
    sfRenderWindow_waitEvent(window, &event);
  return (SUCCESS);
}

int		wait_mouse(sfRenderWindow *window)
{
  sfEvent	event;

  sfRenderWindow_waitEvent(window, &event);
  while (event.type != sfEvtMouseButtonReleased)
    sfRenderWindow_waitEvent(window, &event);
  usleep(100000);
  return (SUCCESS);
}

int		get_dist_btw(sfVector2f a, sfVector2f b)
{
  int		ret;

  ret = sqrt(((a.x - b.x) * (a.x - b.x))
             + ((a.y - b.y) * (a.y - b.y)));
  return (ret);
}
