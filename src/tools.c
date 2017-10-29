/*
** tools.c for tools in /home/Max/Documents/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue May 16 10:17:17 2017 fourrier maxence
** Last update Tue Oct 17 21:15:12 2017 maxence.fourrier
*/

#include "worm.h"

int		my_rand(int min, int max)
{
  return (rand() % (max - min + 1) + min);
}

sfVector2f	vector2f(float x, float y)
{
  sfVector2f	vec;

  vec.x = x;
  vec.y = y;
  return (vec);
}

sfVector2i	vector2i(int x, int y)
{
  sfVector2i	vec;

  vec.x = x;
  vec.y = y;
  return (vec);
}

sfSprite	*load_picture(char *str)
{
  sfSprite	*sprite;
  sfTexture	*texture;

  if ((texture = sfTexture_createFromFile(str, NULL)) == NULL)
    {
      if ((sprite = sfSprite_create()) == NULL)
        return (NULL);
      sfSprite_setColor(sprite, sfBlue);
      return (sprite);
    }
  if ((sprite = sfSprite_create()) == NULL)
    return (NULL);
  sfSprite_setTexture(sprite, texture, sfTrue);
  return (sprite);
}
