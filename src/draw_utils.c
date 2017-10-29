/*
** draw_utils.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct 19 14:00:44 2017 maxence.fourrier
** Last update Sat Oct 21 03:04:55 2017 maxence.fourrier
*/

#include "worm.h"

int		get_sprite_charac(t_player *player, t_game *game)
{
  if (player->team == GREEN && player->dir == LEFT)
    return (SPR_WORM1 + game->p1 - 1);
  if (player->team == RED && player->dir == LEFT)
    return (SPR_WORM1 + game->p2 - 1);
  if (player->team == GREEN && player->dir == RIGHT)
    return (SPR_WORM1_ + game->p1 - 1);
  if (player->team == RED && player->dir == RIGHT)
    return (SPR_WORM1_ + game->p2 - 1);
}

sfVector2f	get_draw_charac(t_player *player)
{
  if (player->team == GREEN)
    return (vector2f(player->pos.x - 23,
		     player->pos.y - 35));
  else
    return (vector2f(player->pos.x - 23,
		     player->pos.y - 35));    
}
