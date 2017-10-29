/*
** init_player.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct 19 00:49:49 2017 maxence.fourrier
** Last update Sat Oct 21 20:00:49 2017 maxence.fourrier
*/

#include "worm.h"

int		get_height_map(int **map, int x)
{
  int		i;

  i = SCREEN_HEIGHT - 1;
  while (map[i][x] && map[i][x] == 1)
    i--;
  return (i);
}

sfVector2f	gen_pos_green(t_player ***player, int **map, int cpt)
{
  if (cpt == 0)
    return (vector2f(my_rand(SCREEN_WIDTH - 100,
			     SCREEN_WIDTH - 20), 100));
  if (cpt == 1)
    return (vector2f(my_rand(SCREEN_WIDTH - 250,
			     SCREEN_WIDTH - 150), 100));
  if (cpt == 2)
    return (vector2f(my_rand(SCREEN_WIDTH - 400,
			     SCREEN_WIDTH - 300), 100));
  return (vector2f(0, 0));
}

sfVector2f	gen_pos_red(t_player ***player, int **map, int cpt)
{
  if (cpt == 0)
    return (vector2f(my_rand(20, 100), 100));
  if (cpt == 1)
    return (vector2f(my_rand(150, 250), 100));
  if (cpt == 2)
    return (vector2f(my_rand(300, 400), 100));
  return (vector2f(0, 0));
}

t_player	*create_player(t_player ***last, int team,
			       int **map, int current)
{
  t_player	*player;

  if ((player = malloc(sizeof(t_player))) == NULL
      || (player->sprite = sfSprite_create()) == NULL
      || (player->texture
          = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (player->framebuffer =
          my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (player->sprwalk = sfSprite_create()) == NULL
      || (player->texwalk
          = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (player->fwalk =
          my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL)
    return (NULL);
  sfSprite_setTexture(player->sprite, player->texture, sfTrue);
  sfSprite_setTexture(player->sprwalk, player->texwalk, sfTrue);
  player->team = team;
  player->hp = 100;
  player->fire = 1;
  player->jump = 0;
  if (team == GREEN && (player->dir = LEFT))
    player->pos = gen_pos_green(last, map, current);
  if (team == RED && (player->dir = RIGHT))
    player->pos = gen_pos_red(last, map, current);
  return (player);
}

t_player	***init_player(int **map)
{
  t_player	***player;
  sfVector2i	cpt;

  if ((player = malloc(sizeof(t_player **) * 3)) == NULL
      || (player[GREEN] = malloc(sizeof(t_player *)
				 * (TOTAL_PLAYER + 1))) == NULL
      || (player[RED] = malloc(sizeof(t_player *)
			       * (TOTAL_PLAYER + 1))) == NULL)
    return (NULL);
  player[2] = NULL;
  cpt.y = -1;
  while (++cpt.y < 2 && (cpt.x = -1))
    {
      while (++cpt.x < TOTAL_PLAYER / 2)
	if ((player[cpt.y][cpt.x] = create_player(player, cpt.y,
						  map, cpt.x)) == NULL)
	  return (NULL);
      player[cpt.y][cpt.x] = NULL;
    }
  return (player);
}
