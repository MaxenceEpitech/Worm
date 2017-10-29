/*
** view.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Oct 18 23:36:04 2017 maxence.fourrier
** Last update Wed Oct 18 23:41:31 2017 maxence.fourrier
*/

#include "worm.h"

sfView          *init_full_view()
{
  sfView        *view;
  sfFloatRect   rect;

  rect.left = 0;
  rect.top = 0;
  rect.width = 1;
  rect.height = 0.5;
  view = sfView_create();
  sfView_setCenter(view, vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
  sfView_setSize(view, vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
  return (view);
}

sfView          *init_zoom_view()
{
  sfView        *view;
  sfFloatRect   rect;

  rect.left = 0;
  rect.top = 0;
  rect.width = 1;
  rect.height = 0.5;
  view = sfView_create();
  sfView_setCenter(view, vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
  sfView_setSize(view, vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3));
  return (view);
}

t_view		*init_view()
{
  t_view	*view;

  if ((view = malloc(sizeof(t_view))) == NULL
      || (view->full = init_full_view()) == NULL
      || (view->zoom = init_zoom_view()) == NULL)
    return (NULL);
  return (view);
}
