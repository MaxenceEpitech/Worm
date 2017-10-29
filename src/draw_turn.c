/*
** draw_turn.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct 19 11:49:22 2017 maxence.fourrier
** Last update Sun Oct 22 15:09:06 2017 maxence.fourrier
*/

#include "worm.h"

void		draw_time(t_worm *worm, sfVector2f vec)
{
  char		*str;

  sfText_setCharacterSize(worm->graph->text, 50);
  str = my_int_to_str(worm->game->time_left);
  sfText_setColor(worm->graph->text, sfBlack);
  sfText_setPosition(worm->graph->text, vec);
  sfText_setString(worm->graph->text, new_cat(TLEFT, str));
  sfRenderWindow_drawText(worm->graph->window,
			  worm->graph->text, NULL);
}

void		draw_weapon(t_worm *worm)
{
  int		sprite;
  sfVector2f	pos;

  sprite = SPR_W1;
  pos = vector2f(SCREEN_WIDTH - 350, 0);
  if (worm->player[worm->game->turn][worm->game->select]->type == 0)
    {
      pos = vector2f(SCREEN_WIDTH - 370, 40);
      sprite = SPR_W2;
    }
  sfSprite_setPosition(worm->sprite->gen[sprite], pos);
  sfRenderWindow_drawSprite(worm->graph->window,
                            worm->sprite->gen[sprite], NULL);
}

void		draw_turn(t_worm *worm)
{
  int		sprite;

  sfSprite_setPosition(worm->sprite->gen[SPR_FRAME],
		       vector2f(SCREEN_WIDTH - 250, 0));
  sfRenderWindow_drawSprite(worm->graph->window,
                            worm->sprite->gen[SPR_FRAME], NULL);
  if (worm->game->turn == GREEN)
    sprite = SPR_WORM1G + worm->game->p1 - 1;
  if (worm->game->turn == RED)
    sprite = SPR_WORM1R + worm->game->p2 - 1;
  sfSprite_setPosition(worm->sprite->gen[sprite],
		       vector2f(SCREEN_WIDTH - 245, 35));
  sfRenderWindow_drawSprite(worm->graph->window,
                            worm->sprite->gen[sprite], NULL);
  draw_weapon(worm);
}
