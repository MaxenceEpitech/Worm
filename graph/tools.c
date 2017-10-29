/*
** tools.c for tools in /home/maxence.fourrier/Documents/Project_C/raytracer1/bonus/graph
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug  2 16:32:41 2017 maxence.fourrier
** Last update Tue Oct 17 10:50:15 2017 maxence.fourrier
*/

#include "worm.h"

void		clear_screen(t_graph *graph)
{
  int		x;
  int		y;

  y = 0;
  while (y < SCREEN_HEIGHT)
    {
      x = 0;
      while (x < SCREEN_WIDTH)
	{
	  my_put_pixel(graph->framebuffer, x, y, sfBlack);
	  x++;
	}
      y++;
    }
  sfTexture_updateFromPixels(graph->texture,
                             graph->framebuffer->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(graph->window, graph->sprite, NULL);
  sfRenderWindow_display(graph->window);
}

void		refresh(t_graph *graph)
{
  sfTexture_updateFromPixels(graph->texture,
                             graph->framebuffer->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(graph->window, graph->sprite, NULL);
  sfRenderWindow_display(graph->window);
}
