/*
** draw_other.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct 19 15:36:39 2017 maxence.fourrier
** Last update Thu Oct 19 20:51:02 2017 maxence.fourrier
*/

#include "worm.h"

void		draw_selected_charac(t_worm *worm, t_player ***player)
{
  sfVector2f	pos;
  int		sprite;

  pos = vector2f(player[worm->game->turn][worm->game->select]->pos.x,
		 player[worm->game->turn][worm->game->select]->pos.y);
  sprite = SPR_CIRCLE_R;
  pos = vector2f(pos.x - 50, pos.y - 70);
  if (worm->game->turn == GREEN)
    sprite++;
  sfSprite_setPosition(worm->sprite->gen[sprite], pos);
  sfRenderWindow_drawSprite(worm->graph->window,
			    worm->sprite->gen[sprite], NULL);
}
