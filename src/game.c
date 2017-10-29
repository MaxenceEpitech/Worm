/*
** game.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Oct 17 10:48:40 2017 maxence.fourrier
** Last update Sun Oct 22 14:12:54 2017 maxence.fourrier
*/

#include "worm.h"

void		draw_winner_name(t_worm *worm)
{
  int		sprite;
  char		*str;

  if (player_alive(worm->player[GREEN]) <= 0)
    {
      sprite = SPR_WORM1R + worm->game->p2 - 1;
      str = TEAM_RED_WIN;
    }
  if (player_alive(worm->player[RED]) <= 0)
    {
      sprite = SPR_WORM1G + worm->game->p1 - 1;
      str = TEAM_GREEN_WIN;
    }
  sfText_setCharacterSize(worm->graph->text, 150);
  sfText_setPosition(worm->graph->text, vector2f(400, 0));
  sfText_setString(worm->graph->text, str);
  sfRenderWindow_drawText(worm->graph->window,
                          worm->graph->text, NULL);
  sfSprite_setPosition(worm->sprite->gen[sprite],
		       vector2f(650, 270));
  sfRenderWindow_drawSprite(worm->graph->window,
			    worm->sprite->gen[sprite], NULL);
}

void		draw_winner(t_worm *worm)
{
  sfVector2i	cpt;

  cpt.x = 0;
  cpt.y = 0;
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      cpt.x++;
      if (cpt.x > GIF_WIN_TIME && !(cpt.x = 0))
	cpt.y++;
      if (cpt.y >= GIF_WIN_TOTAL - 1)
	cpt.y = 0;
      draw(worm);
      sfSprite_setPosition(worm->sprite->gif[GIF_WIN][cpt.y],
			   vector2f(500, 120));
      sfRenderWindow_drawSprite(worm->graph->window,
				worm->sprite->gif[GIF_WIN][cpt.y], NULL);
      draw_winner_name(worm);
      sfRenderWindow_display(worm->graph->window);
    }
}

int		game(t_worm *worm)
{
  if (menu(worm))
    return (SUCCESS);
  init_player_hp(worm);
  init_player_walk(worm);
  draw_map(worm);
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      if (next_turn(worm) == ERROR)
	return (ERROR);
      if (player_alive(worm->player[GREEN]) <= 0
	  || player_alive(worm->player[RED]) <= 0)
	return (1);
    }
  return (SUCCESS);
}
