/*
** draw_walk.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Oct 21 17:34:53 2017 maxence.fourrier
** Last update Sat Oct 21 18:29:38 2017 maxence.fourrier
*/

#include "worm.h"

void		init_player_walk(t_worm *worm)
{
  sfVector2i	cp;
  int		i;

  cp.y = -1;
  while (worm->player[++cp.y] && (cp.x = -1))
    while (worm->player[cp.y][++cp.x] && (i = -1))
      {
        while (++i < 50)
          {
            my_put_pixel(worm->player[cp.y][cp.x]->fwalk, i, 10, sfYellow);
            my_put_pixel(worm->player[cp.y][cp.x]->fwalk, i, 11, sfYellow);
            my_put_pixel(worm->player[cp.y][cp.x]->fwalk, i, 12, sfYellow);
            my_put_pixel(worm->player[cp.y][cp.x]->fwalk, i, 13, sfYellow);
            my_put_pixel(worm->player[cp.y][cp.x]->fwalk, i, 14, sfYellow);
          }
        sfTexture_updateFromPixels(worm->player[cp.y][cp.x]->texwalk,
                                   worm->player[cp.y][cp.x]->fwalk->pixels,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
      }
}

void		draw_player_walk(t_worm *worm)
{
  sfVector2i	cpt;

  cpt.y = -1;
  while (worm->player[++cpt.y] && (cpt.x = -1))
    while (worm->player[cpt.y][++cpt.x])
      if (worm->player[cpt.y][cpt.x]-> hp > 0)
	{
	  sfSprite_setPosition(worm->player[cpt.y][cpt.x]->sprwalk,
			       vector2f(worm->player[cpt.y]
					[cpt.x]->pos.x
					- (worm->player[cpt.y]
					   [cpt.x]->walk / 10 / 3.5),
					worm->player[cpt.y]
					[cpt.x]->pos.y - 50));
	  sfRenderWindow_drawSprite(worm->graph->window,
				    worm->player[cpt.y][cpt.x]->sprwalk,
				    NULL);
	}
}

void		draw_player_framebuffer_walk(t_player *player)
{
  int		i;

  i = -1;
  while (++i < 50)
    {
      my_put_pixel(player->fwalk, i, 10, sfTransparent);
      my_put_pixel(player->fwalk, i, 11, sfTransparent);
      my_put_pixel(player->fwalk, i, 12, sfTransparent);
      my_put_pixel(player->fwalk, i, 13, sfTransparent);
      my_put_pixel(player->fwalk, i, 14, sfTransparent);
    }
  i = -1;
  while (++i < player->walk / 10 / 2)
    {
      my_put_pixel(player->fwalk, i, 10, sfYellow);
      my_put_pixel(player->fwalk, i, 11, sfYellow);
      my_put_pixel(player->fwalk, i, 12, sfYellow);
      my_put_pixel(player->fwalk, i, 13, sfYellow);
      my_put_pixel(player->fwalk, i, 14, sfYellow);
    }
  sfTexture_updateFromPixels(player->texwalk, player->fwalk->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
}

void		draw_framebuffer_walk_turn(t_player **player)
{
  int		cpt;
  int		i;

  cpt = -1;
  while (player[++cpt])
    {
      i = -1;
      while (++i < player[cpt]->walk / 10 / 2 && i < 50)
	{
	  my_put_pixel(player[cpt]->fwalk, i, 10, sfYellow);
	  my_put_pixel(player[cpt]->fwalk, i, 11, sfYellow);
	  my_put_pixel(player[cpt]->fwalk, i, 12, sfYellow);
	  my_put_pixel(player[cpt]->fwalk, i, 13, sfYellow);
	  my_put_pixel(player[cpt]->fwalk, i, 14, sfYellow);
	}
      sfTexture_updateFromPixels(player[cpt]->texwalk,
				 player[cpt]->fwalk->pixels,
				 SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    }
}
