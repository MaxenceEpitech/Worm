/*
** init.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Oct 17 11:01:59 2017 maxence.fourrier
** Last update Fri Oct 20 14:21:58 2017 maxence.fourrier
*/

#include "worm.h"

sfText		*init_text(sfFont *font)
{
  sfText	*text;

  if ((text = sfText_create()) == NULL)
    return (NULL);
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, 50);
  sfText_setStyle(text, sfTextBold);
  return (text);
}

t_graph		*init_graph()
{
  t_graph	*graph;

  if ((graph = malloc(sizeof(t_graph))) == NULL
      || (graph->window =
          create_window(SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (graph->font = sfFont_createFromFile(FONT)) == NULL
      || (graph->text = init_text(graph->font)) == NULL
      || (graph->sprite = sfSprite_create()) == NULL
      || (!graph->window)
      || (graph->texture
          = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (graph->framebuffer =
          my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL)
    return (NULL);
  sfSprite_setTexture(graph->sprite, graph->texture, sfTrue);
  return (graph);
}

t_game		*init_game()
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL
      || (game->shoot = init_shoot()) == NULL
      || (game->explod = init_explod()) == NULL)
    return (NULL);
  game->time = get_time();
  game->time_left = 6;
  game->p1 = 0;
  game->p2 = 0;
  game->turn = my_rand(GREEN, RED);
  game->current = 1;
  return (game);
}

t_worm		*init_worm()
{
  t_worm	*worm;

  if ((worm = malloc(sizeof(t_worm))) == NULL
      || (worm->graph = init_graph()) == NULL
      || (worm->map = init_map()) == NULL
      || (worm->sprite = init_sprite()) == NULL
      || (worm->game = init_game()) == NULL
      || (worm->view = init_view()) == NULL
      || (worm->player = init_player(worm->map)) == NULL)
    return (NULL);
  sfRenderWindow_setView(worm->graph->window, worm->view->full);
  return (worm);
}
