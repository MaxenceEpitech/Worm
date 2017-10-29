/*
** draw_hp.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct 20 15:05:41 2017 maxence.fourrier
** Last update Sat Oct 21 17:54:13 2017 maxence.fourrier
*/

#include "worm.h"

void		init_player_hp(t_worm *worm)
{
  sfVector2i	cpt;
  int		i;

  cpt.y = -1;
  while (worm->player[++cpt.y] && (cpt.x = -1))
    while (worm->player[cpt.y][++cpt.x] && (i = -1))
      {
	while (++i < 50)
	  {
	    my_put_pixel(worm->player[cpt.y][cpt.x]->framebuffer, i, 0, sfRed);
	    my_put_pixel(worm->player[cpt.y][cpt.x]->framebuffer, i, 1, sfRed);
	    my_put_pixel(worm->player[cpt.y][cpt.x]->framebuffer, i, 2, sfRed);
	    my_put_pixel(worm->player[cpt.y][cpt.x]->framebuffer, i, 3, sfRed);
	    my_put_pixel(worm->player[cpt.y][cpt.x]->framebuffer, i, 4, sfRed);
	  }
	sfTexture_updateFromPixels(worm->player[cpt.y]
				   [cpt.x]->texture,
				   worm->player[cpt.y]
				   [cpt.x]->framebuffer->pixels,
				   SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
      }
}

void		draw_player_hp(t_worm *worm)
{
  sfVector2i	cpt;

  cpt.y = -1;
  while (worm->player[++cpt.y] && (cpt.x = -1))
    while (worm->player[cpt.y][++cpt.x])
      if (worm->player[cpt.y][cpt.x]->hp > 0)
	{
	  sfSprite_setPosition(worm->player[cpt.y][cpt.x]->sprite,
			       vector2f(worm->player[cpt.y]
					[cpt.x]->pos.x
					- (worm->player[cpt.y]
					   [cpt.x]->hp / 3.5),
					worm->player[cpt.y]
					[cpt.x]->pos.y - 60));
	  sfRenderWindow_drawSprite(worm->graph->window,
				    worm->player[cpt.y][cpt.x]->sprite,
				    NULL);
	}
}

void		draw_player_framebuffer(t_player *player)
{
  int		i;

  i = -1;
  while (++i < 50)
    {
      my_put_pixel(player->framebuffer, i, 0, sfTransparent);
      my_put_pixel(player->framebuffer, i, 1, sfTransparent);
      my_put_pixel(player->framebuffer, i, 2, sfTransparent);
      my_put_pixel(player->framebuffer, i, 3, sfTransparent);
      my_put_pixel(player->framebuffer, i, 4, sfTransparent);
    }
  i = -1;
  while (++i < player->hp / 2)
    {
      my_put_pixel(player->framebuffer, i, 0, sfRed);
      my_put_pixel(player->framebuffer, i, 1, sfRed);
      my_put_pixel(player->framebuffer, i, 2, sfRed);
      my_put_pixel(player->framebuffer, i, 3, sfRed);
      my_put_pixel(player->framebuffer, i, 4, sfRed);
    }
}

void		update_all_framebuffer(t_player ***player)
{
  sfVector2i	vec;

  vec.y = -1;
  while (player[++vec.y] && (vec.x = -1))
    while (player[vec.y][++vec.x])
      sfTexture_updateFromPixels(player[vec.y][vec.x]->texture,
				 player[vec.y][vec.x]->framebuffer->pixels,
				 SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
}
