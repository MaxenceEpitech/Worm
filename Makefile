##
## Makefile for worms in /home/maxence.fourrier/Documents/Project_C/worm
## 
## Made by maxence.fourrier
## Login   <maxence.fourrier@epitech.eu>
## 
## Started on  Tue Oct 17 10:46:59 2017 maxence.fourrier
## Last update Sun Oct 22 14:21:16 2017 maxence.fourrier
##

NAME		= 	worms

CC		= 	gcc

RM		= 	rm -f

SRCS_DIR	= 	./src/

GRAPH_DIR	= 	./graph/

SRCS		=	$(GRAPH_DIR)graph.c			\
			$(GRAPH_DIR)tools.c			\
			$(SRCS_DIR)main.c			\
			$(SRCS_DIR)view.c			\
			$(SRCS_DIR)menu.c			\
			$(SRCS_DIR)draw_walk.c			\
			$(SRCS_DIR)move_utils.c			\
			$(SRCS_DIR)dir_shoot.c			\
			$(SRCS_DIR)fall.c			\
			$(SRCS_DIR)select.c			\
			$(SRCS_DIR)player_alive.c		\
			$(SRCS_DIR)shoot.c			\
			$(SRCS_DIR)shoot_explod.c		\
			$(SRCS_DIR)move.c			\
			$(SRCS_DIR)explod.c			\
			$(SRCS_DIR)draw_hp.c			\
			$(SRCS_DIR)init_event.c			\
			$(SRCS_DIR)draw_other.c			\
			$(SRCS_DIR)turn.c			\
			$(SRCS_DIR)event.c			\
			$(SRCS_DIR)draw_utils.c			\
			$(SRCS_DIR)draw_turn.c			\
			$(SRCS_DIR)init_player.c		\
			$(SRCS_DIR)starting_menu.c		\
			$(SRCS_DIR)draw.c			\
			$(SRCS_DIR)utils.c			\
			$(SRCS_DIR)time.c			\
			$(SRCS_DIR)draw_menu.c			\
			$(SRCS_DIR)init.c			\
			$(SRCS_DIR)init_map.c			\
			$(SRCS_DIR)init_gif.c			\
			$(SRCS_DIR)init_sprite.c		\
			$(SRCS_DIR)gen_map.c			\
			$(SRCS_DIR)game.c			\
			$(SRCS_DIR)tools.c

OBJS		= 	$(SRCS:.c=.o)

CFLAGS		+= 	-I./include

LDFLAGS		+=	-L./lib/my -lmy -lcsfml-graphics -lcsfml-window
LDFLAGS		+=	-lcsfml-system -lcsfml-audio -lm -lpthread

all		:	$(NAME)

$(NAME)		: 	$(OBJS)
			make -C ./lib/my
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean		:
			make clean -C ./lib/my
			$(RM) $(OBJS)

fclean		:	clean
			make fclean -C ./lib/my
			$(RM) $(NAME)

re		:	fclean all

.PHONY		: 	all clean fclean re

