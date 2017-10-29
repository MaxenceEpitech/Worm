/*
** init_sprite.c for worms in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Oct 17 21:04:15 2017 maxence.fourrier
** Last update Sun Oct 22 15:01:30 2017 maxence.fourrier
*/

#include "worm.h"

sfSprite	**init_gen_other(sfSprite **sprite)
{
  if ((sprite[SPR_CIRCLE_R] = load_picture(PATH_CIRCLE_R)) == NULL
      || (sprite[SPR_CIRCLE_G] = load_picture(PATH_CIRCLE_G)) == NULL
      || (sprite[SPR_MISSILE] = load_picture(PATH_MISSILE)) == NULL
      || (sprite[SPR_WORM1_] = load_picture(PATH_WORM1_)) == NULL
      || (sprite[SPR_WORM2_] = load_picture(PATH_WORM2_)) == NULL
      || (sprite[SPR_WORM3_] = load_picture(PATH_WORM3_)) == NULL
      || (sprite[SPR_WORM4_] = load_picture(PATH_WORM4_)) == NULL
      || (sprite[SPR_WORM5_] = load_picture(PATH_WORM5_)) == NULL
      || (sprite[SPR_FRAME] = load_picture(PATH_FRAME)) == NULL
      || (sprite[SPR_SEARCH] = load_picture(PATH_SEARCH)) == NULL
      || (sprite[SPR_W1] = load_picture(PATH_W1)) == NULL
      || (sprite[SPR_W2] = load_picture(PATH_W2)) == NULL)
    return (NULL);
  sfSprite_setOrigin(sprite[SPR_MISSILE], vector2f(8, 23));
  sfSprite_setOrigin(sprite[SPR_SEARCH], vector2f(10, 26));
  return (sprite);
}

sfSprite	**init_gen()
{
  sfSprite	**sprite;

  if ((sprite = malloc(sizeof(sfSprite *) * (NB_SPRITE + 1))) == NULL
      || (sprite[SPR_FLOOR] = load_picture(PATH_MENU)) == NULL
      || (sprite[SPR_MENU] = load_picture(PATH_MENU)) == NULL
      || (sprite[SPR_WORM1G] = load_picture(PATH_WORM1G)) == NULL
      || (sprite[SPR_WORM2G] = load_picture(PATH_WORM2G)) == NULL
      || (sprite[SPR_WORM3G] = load_picture(PATH_WORM3G)) == NULL
      || (sprite[SPR_WORM4G] = load_picture(PATH_WORM4G)) == NULL
      || (sprite[SPR_WORM5G] = load_picture(PATH_WORM5G)) == NULL
      || (sprite[SPR_WORM1R] = load_picture(PATH_WORM1R)) == NULL
      || (sprite[SPR_WORM2R] = load_picture(PATH_WORM2R)) == NULL
      || (sprite[SPR_WORM3R] = load_picture(PATH_WORM3R)) == NULL
      || (sprite[SPR_WORM4R] = load_picture(PATH_WORM4R)) == NULL
      || (sprite[SPR_WORM5R] = load_picture(PATH_WORM5R)) == NULL
      || (sprite[SPR_WORM1] = load_picture(PATH_WORM1)) == NULL
      || (sprite[SPR_WORM2] = load_picture(PATH_WORM2)) == NULL
      || (sprite[SPR_WORM3] = load_picture(PATH_WORM3)) == NULL
      || (sprite[SPR_WORM4] = load_picture(PATH_WORM4)) == NULL
      || (sprite[SPR_WORM5] = load_picture(PATH_WORM5)) == NULL
      || (sprite = init_gen_other(sprite)) == NULL)
    return (NULL);
  return (sprite);
}

char		*random_floor()
{
  int		nb;

  nb = my_rand(1, 1);
  if (nb == 1)
    return ("texture/floor/floor4.jpg");
}

t_sprite	*init_sprite()
{
  t_sprite	*sprite;
  char		*str;
  int		i;

  if ((sprite = malloc(sizeof(t_sprite))) == NULL
      || (sprite->gen = init_gen()) == NULL
      || (sprite->gif = init_gif()) == NULL
      || (sprite->cpt_gif = malloc(sizeof(int *)
				   * (NB_GIF + 1))) == NULL
      || (str = random_floor()) == NULL
      || (sprite->color = create_color(str)) == NULL)
    return (NULL);
  i = -1;
  while (++i < NB_GIF)
    sprite->cpt_gif[i] = 0;
  sprite->background = my_rand(1, 3);
  return (sprite);
}
