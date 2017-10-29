/*
** draw.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Oct 17 14:02:38 2017 maxence.fourrier
** Last update Sun Oct 22 15:12:51 2017 maxence.fourrier
*/

#include "worm.h"

void		draw_gif(t_worm *worm, sfVector2f pos,
			 int name, sfVector2i gif)
{
  int		nb;

  if (worm->sprite->cpt_gif[name] == gif.x * gif.y)
    worm->sprite->cpt_gif[name] = 0;
  nb = worm->sprite->cpt_gif[name] / gif.y;
  sfSprite_setPosition(worm->sprite->gif[name][nb], pos);		       
  sfRenderWindow_drawSprite(worm->graph->window,
                            worm->sprite->gif[name][nb], NULL);
  worm->sprite->cpt_gif[name]++;
}

void		draw_background(t_worm *worm)
{
  if (worm->sprite->background == 1)
    draw_gif(worm, vector2f(0, 0), GIF_B1,
	     vector2i(GIF_B1_TOTAL, GIF_B1_TIME));
  if (worm->sprite->background == 2)
    draw_gif(worm, vector2f(0, 0), GIF_B2,
	     vector2i(GIF_B2_TOTAL, GIF_B2_TIME));
  if (worm->sprite->background == 3)
    draw_gif(worm, vector2f(0, 0), GIF_B3,
	     vector2i(GIF_B3_TOTAL, GIF_B3_TIME));
}

void		draw_map(t_worm *worm)
{
  sfVector2i	vec;

  vec.y = -1;
  while (worm->map[++vec.y] && (vec.x = -1))
    while (worm->map[vec.y][++vec.x] != -1)
      if (worm->map[vec.y][vec.x] == 1)
	my_put_pixel(worm->graph->framebuffer, vec.x,
		     vec.y, worm->sprite->color[vec.y][vec.x]);
  sfTexture_updateFromPixels(worm->graph->texture,
                             worm->graph->framebuffer->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
}

void		draw_charac(t_worm *worm, t_player ***player)
{
  sfVector2i	cpt;
  int		sprite;

  cpt.y = -1;
  while (player[++cpt.y] && (cpt.x = -1))
    while (player[cpt.y][++cpt.x])
      if (player[cpt.y][cpt.x]->hp > 0)
	{
	  sprite = get_sprite_charac(player[cpt.y][cpt.x], worm->game);
	  sfSprite_setPosition(worm->sprite->gen[sprite],
			       get_draw_charac(player[cpt.y][cpt.x]));
	  sfRenderWindow_drawSprite(worm->graph->window,
				    worm->sprite->gen[sprite], NULL);
	}
}

int		draw(t_worm *worm)
{
  draw_background(worm);
  draw_turn(worm);
  sfRenderWindow_drawSprite(worm->graph->window,
			    worm->graph->sprite, NULL);
  draw_charac(worm, worm->player);
  draw_selected_charac(worm, worm->player);
  draw_player_hp(worm);
  draw_player_walk(worm);
}
