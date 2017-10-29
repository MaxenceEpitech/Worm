/*
** explod.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct 20 13:51:46 2017 maxence.fourrier
** Last update Fri Oct 20 14:17:58 2017 maxence.fourrier
*/

#include "worm.h"

void		add_explod(t_worm *worm, sfVector2i pos)
{
  int		i;

  i = -1;
  while (worm->game->explod[++i])
    if (worm->game->explod[i]->alive == 0)
      {
	worm->game->explod[i]->alive = 1;
	worm->game->explod[i]->pos = vector2i(pos.x - 70,
					      pos.y - 120);
	break;
      }
}

void		draw_cpt_explod(t_explod *explod)
{
  explod->cpt++;
  if (explod->cpt > GIF_MISSILE_TIME)
    {
      explod->cpt = 0;
      explod->draw++;
    }
  if (explod->draw >= GIF_MISSILE_TOTAL - 1)
    {
      explod->alive = 0;
      explod->draw = 0;
      explod->cpt = 0;
    }
}

void		draw_explod(t_worm *worm)
{
  int		i;

  i = -1;
  while (worm->game->explod[++i])
    {
      if (worm->game->explod[i]->alive == 1)
	draw_cpt_explod(worm->game->explod[i]);
      if (worm->game->explod[i]->alive == 1)
	{
	  sfSprite_setPosition(worm->sprite->gif[GIF_MISSILE]
			       [worm->game->explod[i]->draw],
			       vector2f(worm->game->explod[i]->pos.x,
					worm->game->explod[i]->pos.y));
	  sfRenderWindow_drawSprite(worm->graph->window,
				    worm->sprite->gif[GIF_MISSILE]
				    [worm->game->explod[i]->draw], NULL);	    
	  }
      }
}
