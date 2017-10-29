/*
** graph.c for graph in /home/maxence.fourrier/Documents/Project_C/raytracer1/bonus/graph
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug  2 16:11:10 2017 maxence.fourrier
** Last update Sat Oct 21 18:14:16 2017 maxence.fourrier
*/

#include "worm.h"

sfUint8		*create_pixel_buffer(int width, int height)
{
  int		i;
  sfUint8	*pixels;

  if ((pixels = malloc(width * height * 4 * sizeof(*pixels))) == NULL)
    return (NULL);
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i++;
    }
  return (pixels);
}

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfVideoMode		mode;
  sfRenderWindow		*window;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*framebuffer;
  int			i;

  i = 0;
  framebuffer = malloc(sizeof(t_my_framebuffer));
  if (framebuffer == NULL)
    return (NULL);
  framebuffer->pixels = malloc(width * height
                               * 4 * sizeof(*framebuffer->pixels));
  if (framebuffer->pixels == NULL)
    return (NULL);
  while (i < width * height * 4)
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
  framebuffer->width = width;
  framebuffer->height = height;
  return (framebuffer);
}

void			my_put_pixel(t_my_framebuffer *framebuffer,
				     int y, int x, sfColor color)
{
  if ((x >= 0 && x < framebuffer->height) && (y >= 0 &&
					      y < framebuffer->width))
    {
      framebuffer->pixels[((framebuffer->width) * x + y) * 4] = color.r;
      framebuffer->pixels[((framebuffer->width) * x + y) * 4 + 1] = color.g;
      framebuffer->pixels[((framebuffer->width) * x + y) * 4 + 2] = color.b;
      framebuffer->pixels[((framebuffer->width) * x + y) * 4 + 3] = color.a;
    }
}
