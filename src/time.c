/*
** time.c for worm in /home/maxence.fourrier/Documents/Project_C/worm/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Oct 18 16:52:17 2017 maxence.fourrier
** Last update Wed Oct 18 16:52:52 2017 maxence.fourrier
*/

#include <sys/time.h>
#include "worm.h"

unsigned long long	get_time()
{
  struct timeval	tv;

  gettimeofday(&tv, NULL);
  return ((unsigned long long)(tv.tv_sec) * 1000 +
          (unsigned long long)(tv.tv_usec) / 1000);
}
