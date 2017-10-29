/*
** worm.h for worm in /home/maxence.fourrier/Documents/Project_C/worm/include
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Oct 17 10:47:50 2017 maxence.fourrier
** Last update Sun Oct 22 15:07:36 2017 maxence.fourrier
*/

#ifndef _WORM_H_
# define _WORM_H_

/*      __________ ________________________ __________
**
**                        INCLUDES
**      __________ ________________________ __________ 
*/

# include <stdlib.h>
# include <unistd.h>
# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <SFML/Window.h>
# include <SFML/System.h>

/*      __________ ________________________ __________
**
**                        DEFINES
**      __________ ________________________ __________ 
*/
/*
**		     __ Windows __
*/
# define SCREEN_WIDTH	        1600
# define SCREEN_HEIGHT		900
# define SCREEN_NAME		"__ Tank & worms __"

/*
**		     __ POS __
*/
# define MENU_X			-160
# define MENU_Y			-20

# define WORM_X			219
# define WORM_Y			665

/*
**		     __ Sprites __
*/
# define NB_SPRITE		30

# define SPR_FLOOR		0
# define PATH_FLOOR		"texture/worms_floor.png"
# define SPR_MENU		1
# define PATH_MENU		"texture/menu.png"
# define SPR_WORM1G		2
# define PATH_WORM1G		"texture/worm_1G.png"
# define SPR_WORM2G		3
# define PATH_WORM2G		"texture/worm_2G.png"
# define SPR_WORM3G		4
# define PATH_WORM3G		"texture/worm_3G.png"
# define SPR_WORM4G		5
# define PATH_WORM4G		"texture/worm_4G.png"
# define SPR_WORM5G		6
# define PATH_WORM5G		"texture/worm_5G.png"
# define SPR_WORM1R		7
# define PATH_WORM1R		"texture/worm_1R.png"
# define SPR_WORM2R		8
# define PATH_WORM2R		"texture/worm_2R.png"
# define SPR_WORM3R		9
# define PATH_WORM3R		"texture/worm_3R.png"
# define SPR_WORM4R		10
# define PATH_WORM4R		"texture/worm_4R.png"
# define SPR_WORM5R		11
# define PATH_WORM5R		"texture/worm_5R.png"
# define SPR_WORM1		12
# define PATH_WORM1		"texture/charac/worm_1.png"
# define SPR_WORM2		13
# define PATH_WORM2		"texture/charac/worm_2.png"
# define SPR_WORM3		14
# define PATH_WORM3		"texture/charac/worm_3.png"
# define SPR_WORM4		15
# define PATH_WORM4		"texture/charac/worm_4.png"
# define SPR_WORM5		16
# define PATH_WORM5		"texture/charac/worm_5.png"
# define SPR_CIRCLE_R		17
# define PATH_CIRCLE_R		"texture/circle.png"
# define SPR_CIRCLE_G		18
# define PATH_CIRCLE_G		"texture/circle_.png"
# define SPR_MISSILE		19
# define PATH_MISSILE		"texture/missile.png"
# define SPR_WORM1_		20
# define PATH_WORM1_		"texture/charac/worm_1_.png"
# define SPR_WORM2_		21
# define PATH_WORM2_		"texture/charac/worm_2_.png"
# define SPR_WORM3_		22
# define PATH_WORM3_		"texture/charac/worm_3_.png"
# define SPR_WORM4_		23
# define PATH_WORM4_		"texture/charac/worm_4_.png"
# define SPR_WORM5_		24
# define PATH_WORM5_		"texture/charac/worm_5_.png"
# define SPR_FRAME		25
# define PATH_FRAME		"texture/frame.png"
# define SPR_SEARCH		26
# define PATH_SEARCH		"texture/auto_missile.png"
# define SPR_W1			27
# define PATH_W1		"texture/no_search.png"
# define SPR_W2			28
# define PATH_W2		"texture/search.png"

# define NB_GIF			5

# define GIF_SKY		0
# define GIF_SKY_NAME		"texture/sky/sky-"
# define GIF_SKY_TOTAL		57
# define GIF_SKY_TIME		3

# define GIF_B1			1
# define GIF_B1_NAME		"texture/background1/b1-"
# define GIF_B1_TOTAL		7
# define GIF_B1_TIME		24

# define GIF_B2			2
# define GIF_B2_NAME		"texture/background2/b2-"
# define GIF_B2_TOTAL		7
# define GIF_B2_TIME		24

# define GIF_B3			3
# define GIF_B3_NAME		"texture/background3/b3-"
# define GIF_B3_TOTAL		15
# define GIF_B3_TIME		40

# define GIF_MISSILE		4
# define GIF_MISSILE_NAME	"texture/explod_missile/explod-"
# define GIF_MISSILE_TOTAL	10
# define GIF_MISSILE_TIME	10

# define GIF_WIN		5
# define GIF_WIN_NAME		"texture/win/win-"
# define GIF_WIN_TOTAL		7
# define GIF_WIN_TIME		50

/*
**		     __ Worms __
*/
# define TOTAL_PLAYER		6
# define BORDER			SCREEN_HEIGHT / 8
# define NB_EXPLOD		100
# define SPACE_CHARAC		60
# define GEN_BORDER		50
# define HEIGHT_DIFF		3
# define MIN_SMOOTH		7
# define MAX_SMOOTH		26
# define POWER_MIN		2
# define POWER_MAX		6
# define FONT			"font.ttf"

# define TIME_TURN		60

# define NB_WORMS		4

# define TLEFT			"End turn in : "
# define START			"Starting in : "

# define TEAM_RED_WIN		"RED team won !"
# define TEAM_GREEN_WIN		"GREEN team won !"

# define GREEN			0
# define RED			1

# define LEFT			-1
# define RIGHT			1

# define INITIAL_WALK		1000
# define JUMP			100

# define NB_MISSILE		3
# define MOVE_SPEED		0.4
# define MISSILE_SPEED		1.6
# define GRAVITY		0.003
# define EXPLOD_RADIUS		30

/*
**		     __ Error Message __
*/

# define OPEN_MSG		"Open Error.\n"

# define READ_MSG		"Read Error.\n"

# define MALLOC_MSG		"Malloc Error.\n"

/*
**	             __ Returns Values __
*/

# define SUCCESS		0
# define ERROR			84

/*      __________ ________________________ __________
**
**                       STRUCTURES
**      __________ ________________________ __________ 
*/
typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_graph
{
  sfRenderWindow	*window;
  t_my_framebuffer	*framebuffer;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfText		*text;
  sfFont		*font;
}			t_graph;

typedef struct		s_ptr
{
  char			*str;
  void			(*fnc)();
}			t_ptr;

typedef struct		s_list
{
  char			*data;
  struct s_list		*next;
}			t_list;

typedef struct		s_shoot
{
  int			type;
  sfVector2i		id;
  int			alive;
  sfVector2f		dir;
  sfVector2f		pos;
}			t_shoot;

typedef struct		s_explod
{
  sfVector2i		pos;
  int			cpt;
  int			draw;
  int			alive;
}			t_explod;

typedef struct		s_game
{
  t_shoot		**shoot;
  t_explod		**explod;
  int			select;
  unsigned long long	time;
  int			time_left;
  int			current;
  int			p1;
  int			p2;
  int			turn;
}			t_game;

typedef struct		s_view
{
  sfView		*full;
  sfView		*zoom;
  int			current;
}			t_view;

typedef struct		s_sprite
{
  sfColor		**color;
  sfSprite		**gen;
  sfSprite		***gif;
  int			*cpt_gif;
  int			background;
}			t_sprite;

typedef struct		s_player
{
  int			type;
  int			jump;
  int			walk;
  int			dir;
  sfSprite		*sprite;
  sfTexture		*texture;
  t_my_framebuffer	*framebuffer;
  sfSprite		*sprwalk;
  sfTexture		*texwalk;
  t_my_framebuffer	*fwalk;
  int			fire;
  int			team;
  float			hp;
  sfVector2f		pos;
}			t_player;

typedef struct		s_worm
{
  t_player		***player;
  t_view		*view;
  t_game		*game;
  t_sprite		*sprite;
  t_graph		*graph;
  int			**map;
}			t_worm;

/*      __________ ________________________ __________
**
**                          WORMS
**      __________ ________________________ __________ 
*/
/*
**		     __ dir_shoot.c __
*/
void		shoot_type(t_worm *, t_shoot *);

/*
**		     __ walk.c __
*/
void		init_player_walk(t_worm *);
void		draw_player_walk(t_worm *);
void		draw_player_framebuffer_walk(t_player *);
void		draw_framebuffer_walk_turn(t_player **);

/*
**		     __ fall.c __
*/
void		player_fall(t_worm *);

/*
**		     __ select.c __
*/
void		event_select(t_worm *);
void		check_select_worm(t_worm *);

/*
**		     __ player_alive.c __
*/
int		player_alive(t_player **);

/*
**		     __ draw_hp.c __
*/
void		init_player_hp(t_worm *);
void		draw_player_hp(t_worm *);
void		draw_player_framebuffer(t_player *);
void		update_all_framebuffer(t_player ***);

/*
**		     __ move_utils.c __
*/
int		check_wall(t_player *, int **, int);

/*
**		     __ move.c __
*/
int		can_jump(sfVector2f, int **);
void		event_move(t_worm *);

/*
**		     __ init_event.c __
*/
t_explod	**init_explod();
t_shoot		**init_shoot();

/*
**		     __ explod.c __
*/
void		add_explod(t_worm *, sfVector2i);
void		draw_cpt_explod(t_explod *);
void		draw_explod(t_worm *);

/*
**		     __ draw_other.c __
*/
void		draw_selected_charac(t_worm *, t_player ***);

/*
**		     __ draw_utils.c __
*/
int		get_sprite_charac(t_player *, t_game *);
sfVector2f	get_draw_charac(t_player *);

/*
**		     __ shoot_explod.c __
*/
void		shoot_explode(t_worm *, t_shoot *, int **map, int);
void		has_hit(t_worm *, int, t_shoot **, int **);

/*
**		     __ shoot.c __
*/
int		shoot_player(t_worm *, t_shoot *);
void		draw_transparent(t_worm *);
void		event_shoot(t_worm *, t_shoot **, int **);
void		draw_shoot(t_worm *, t_shoot **);

/*
**		     __ event.c __
*/
sfVector2f	get_dir_fire(sfVector2i, sfVector2i);
void		event(t_worm *);

/*
**		     __ draw_turn.c __
*/
void		draw_time(t_worm *, sfVector2f);
void		draw_turn(t_worm *);

/*
**		     __ turn.c __
*/
int		next_turn(t_worm *);

/*
**		     __ init_player.c __
*/
t_player	***init_player();

/*
**		     __ view.c __
*/
t_view		*init_view();

/*
**		     __ starting_menu.c __
*/
int		starting_menu(t_worm *);

/*
**		     __ time.c __
*/
unsigned long long	get_time();

/*
**		     __ draw_menu.c __
*/
void		draw_background_menu(t_worm *);
void		draw_current(t_worm *, int);
void		draw_selected(t_worm *, int);
int		draw_play(t_worm *);
void		draw_menu(t_worm *);

/*
**		     __ utils.c __
*/
sfColor		**create_color(char *);
int		wait_key(sfRenderWindow *, sfKeyCode);
int		wait_mouse(sfRenderWindow *);
int		get_dist_btw(sfVector2f, sfVector2f);

/*
**		     __ menu.c __
*/
void		check_select(t_worm *);
void		select_charac(t_worm *);
void		validate_selection(t_worm *);
void		reset_charac(t_worm *);
int		menu(t_worm *);

/*
**		     __ init_sprite.c __
*/
sfSprite	**create_gif(char *, int);
char		*new_cat(char *, char *);
sfSprite	***init_gif();

/*
**		     __ init_sprite.c __
*/
sfSprite	**init_gen();
t_sprite	*init_sprite();

/*
**		     __ draw.c __
*/
void		draw_map(t_worm *);
int		draw(t_worm *);

/*
**		     __ gen_map.c __
*/
int		**gen_map(int **, int *);
int		get_total_mountain(int **);
int		create_map(int **, int *);

/*
**		     __ init_map.c __
*/
int		**fill_map(int **);
int		*gen_smooth();
int		**init_map();

/*
**		     __ game.c __
*/
void		draw_winner(t_worm *);
int		game(t_worm *);

/*
**		     __ tools.c __
*/
int		my_rand(int, int);
sfVector2f	vector2f(float, float);
sfVector2i	vector2i(int, int);
sfSprite	*load_picture(char *);

/*
**		     __ init.c __
*/
sfText		*init_text();
t_graph		*init_graph();
t_game		*init_game();
t_worm		*init_worm();

/*      __________ ________________________ __________
**
**                    LIBRARY #GRAPHIC
**      __________ ________________________ __________
*/
sfUint8			*create_pixel_buffer(int width, int height);
sfRenderWindow		*create_window(char *name, int width, int height);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			my_put_pixel(t_my_framebuffer *framebuffer,
				     int y, int x, sfColor color);
void			refresh(t_graph *);
void			clear_screen(t_graph *);

/*      __________ ________________________ __________
**
**                         LIBRARY
**      __________ ________________________ __________ 
*/

t_list	*my_rev_list(t_list *list);
t_list	*my_link_list(t_list *list, char *data);
t_list	*my_list_cpy(t_list *list);
int	my_list_size(t_list *begin);
int	my_list_is_empty(t_list *liste);
void	my_print_list(t_list *liste);

int	my_decimal_to_octal(int nb);
int	my_strlen(char *str);
int	my_str_who_bigger(char *s1, char *s2);
int	my_str_to_int(char *str);
int	my_strcmp(char *a, char *b);
int	my_swap(int *a, int *b);

void	my_putstr_error(char *str);
void	my_putnbr(int nb);
void	my_putchar(char a);
void	my_putstr(char *str);

char	*my_int_to_str(int nb);
char	*my_str_maj(char *str);
char	*my_decimal_to_hexa(int nb);
char	*supp_0(char *str);
char	*my_revstr(char *str);
char	*my_strcpy(char *dest, char *src);

#endif /* !__WORM_H_ */
