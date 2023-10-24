#ifndef CUB3D_H
# define CUB3D_H

//----- LIBRARİES -----//
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"

//------ DEFINES ------//
# define BUFFER_SIZE 10

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGH 720

# define FOV 0.66

# define ON_KEY_DOWN 2
# define ON_KEY_UP 3
# define ON_MOUSE_DOWN 4
# define ON_MOUSE_MOVE 6
# define ON_EXPOSE 12    //peki bu nee !!!!
# define ON_DESTROY 17

//# ifdef _APPLE_ !!!!!!!!! yorumdan çıkar
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2

#  define KEY_E 14

#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_DOWN 125
#  define KEY_UP 126
//# endif

//------ STRUCTS ------//
typedef struct s_vectord
{
	double  x;
	double  y;
}   t_vectord;

typedef struct s_character
{
	t_vectord   pos;
	t_vectord   dir;
	t_vectord   plane;
	double      angle; //açı
}   t_character;

typedef struct s_keyevnts
{
	int     key_w;
	int     key_a;
	int     key_s;
	int     key_d;
	int     key_up;
	int     key_down;
	int     key_left;
	int     key_right;
}   t_keyevents;


typedef struct s_data
{
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}   t_data;


typedef struct s_textures
{
	int         top;
	int         bot;
	t_data      *xpm[4];
}   t_textures;

typedef struct s_map
{
	char    **map;
	size_t  x;
	size_t  y;
	int     player_counter;
}   t_map;


typedef struct s_cub3d
{
	void    *mlx;
	void    *win;

	t_map       *map;
	t_textures  texture;
	t_keyevents key;
	t_character *player;
	t_data      *image;

}   t_cup3d;


//----- FONCTION DEFİNİTİONS -----//

//* map
int         map_creat_and_controll(t_cup3d *game, char *map_file);
int         map_xpm_to_image(t_cup3d *game, char *line);
int         map_check(char **map);

//* initialize
int			initialize(t_cup3d *game, char **argv);
void        init_keyboard_events(t_cup3d *game);
int         init_player(t_cup3d *game);
int			init_image(t_cup3d *game);


//* utils
size_t      ft_strlen(const char *s);
int         ft_strrcmp(char *src, char *dest);
char        *ft_strjoin(char const *s1, char const *s2);
char        *get_next_line(int fd);
int         ft_strncmp(const char *s1, const char *s2, size_t n);
char	    *ft_strndup(const char *str, size_t n);
char	    **ft_split(char const *s, char c);
int         ft_atoi(const char *nptr);
char        *ft_strnstr(const char *haystack, const char *needle, size_t len);
void	    *ft_calloc(size_t nmemb, size_t size);
char	    *ft_strchr(const char *s, int c);

//* events
void		finish_game(t_cup3d *game);
int			key_up(int keycode, t_cup3d *game);
int			key_down(int keycode, t_cup3d *game);



#endif