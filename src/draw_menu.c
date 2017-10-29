/*
** draw_menu.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Oct 18 14:48:47 2017 maxence.fourrier
** Last update Wed Oct 18 17:29:13 2017 maxence.fourrier
*/

#include "worm.h"

void		draw_background_menu(t_worm *worm)
{
  sfSprite_setPosition(worm->sprite->gen[SPR_MENU],
		       vector2f(MENU_X, MENU_Y));
  sfRenderWindow_drawSprite(worm->graph->window,
                            worm->sprite->gen[SPR_MENU], NULL);
}

void		draw_current(t_worm *worm, int sprite)
{
  sfVector2f	pos;

  pos = vector2f(WORM_X, WORM_Y);
  sprite += worm->game->current - 1;
  if (worm->game->current == 2)
    pos = vector2f(pos.x + 228, pos.y - 4);
  if (worm->game->current == 3)
    pos = vector2f(pos.x + 433, pos.y - 7);
  if (worm->game->current == 4)
    pos = vector2f(pos.x + 670, pos.y - 7);
  if (worm->game->current == 5)
    pos = vector2f(pos.x + 890, pos.y - 3);
  sfSprite_setPosition(worm->sprite->gen[sprite], pos);
  sfRenderWindow_drawSprite(worm->graph->window,
                            worm->sprite->gen[sprite], NULL);    
}

void		draw_selected(t_worm *worm, int sprite)
{
  sfVector2f	pos;

  pos = vector2f(WORM_X, WORM_Y);
  sprite += worm->game->p1 - 1;
  if (worm->game->p1 == 2)
    pos = vector2f(pos.x + 228, pos.y - 4);
  if (worm->game->p1 == 3)
    pos = vector2f(pos.x + 433, pos.y - 7);
  if (worm->game->p1 == 4)
    pos = vector2f(pos.x + 670, pos.y - 7);
  if (worm->game->p1 == 5)
    pos = vector2f(pos.x + 890, pos.y - 3);
  sfSprite_setPosition(worm->sprite->gen[sprite], pos);
  sfRenderWindow_drawSprite(worm->graph->window,
                            worm->sprite->gen[sprite], NULL);    
}

int		draw_play(t_worm *worm)
{
  char		*str;

  if (worm->game->time + 1000 < get_time())
    {
      worm->game->time = get_time();
      worm->game->time_left--;
      draw_background_menu(worm);
      draw_selected(worm, SPR_WORM1G);
      draw_current(worm, SPR_WORM1R);
      str = my_int_to_str(worm->game->time_left);
      sfText_setCharacterSize(worm->graph->text, 140);
      sfText_setColor(worm->graph->text, sfBlack);
      sfText_setPosition(worm->graph->text, vector2f(500, 60));
      sfText_setString(worm->graph->text, new_cat(START, str));
      sfRenderWindow_drawText(worm->graph->window,
			      worm->graph->text, NULL);
      sfRenderWindow_display(worm->graph->window);
    }
  if (worm->game->time_left <= 0)
    return (1);
  return (SUCCESS);
}

void		draw_menu(t_worm *worm)
{
  draw_background_menu(worm);
  if (worm->game->p1 == 0 && worm->game->current != -1)
    draw_current(worm, SPR_WORM1G);
  else if (worm->game->p2 == 0 && worm->game->current != -1)
    {
      draw_selected(worm, SPR_WORM1G);
      draw_current(worm, SPR_WORM1R);
    }
  sfRenderWindow_display(worm->graph->window);
}
