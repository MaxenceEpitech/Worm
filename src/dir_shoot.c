/*
** dir_shoot.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct 22 14:20:41 2017 maxence.fourrier
** Last update Sun Oct 22 14:46:54 2017 maxence.fourrier
*/

#include "worm.h"

void		shoot_type(t_worm *worm, t_shoot *shoot)
{
  sfVector2f	dir;
  sfVector2i	tmp;

  if (shoot->type == 0)
    {
      tmp = sfMouse_getPositionRenderWindow(worm->graph->window);
      dir = get_dir_fire(vector2i(shoot->pos.x, shoot->pos.y), tmp);
      shoot->dir.x += (dir.x / 80);
      shoot->dir.y += (dir.y / 80) + (GRAVITY / 2);
    }
  if (shoot->type)
    shoot->dir.y += GRAVITY;
  shoot->pos.x += shoot->dir.x * MISSILE_SPEED;
  shoot->pos.y += shoot->dir.y * MISSILE_SPEED;
}

void		change_dir_shoot(t_worm *worm, t_shoot *shoot)
{
  
}
