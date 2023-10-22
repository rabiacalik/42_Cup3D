#ifndef CUB3D_H
# define CUB3D_H

//----- LIBRARİES -----//
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"

//------ STRUCTS ------//
typedef struct s_textures
{
    int         top;
    int         bot;
    t_data      *xpm[4];
}   t_textures;


typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;


typedef struct s_map
{
    char    **map;
    
}   t_map;


typedef struct s_cub3d
{
    void    **mlx;

    t_map       *map;
    t_textures  texture;
}   t_cup3d;


//----- FONCTION DEFİNİTİONS -----//

# define BUFFER_SIZE 10

//* map
int     map_creat_and_controll(t_cup3d *game, char *map_file);
int     map_xpm_to_image(t_cup3d *game, char *line);

//* utils
size_t      ft_strlen(const char *s);
int         ft_strrcmp(char *src, char *dest);
char        *ft_strjoin(char const *s1, char const *s2);
char        *get_next_line(int fd);
int         ft_strncmp(const char *s1, const char *s2, size_t n);
char	    *ft_strndup(const char *str, size_t n);
char	    **ft_split(char const *s, char c);
int         ft_atoi(const char *nptr);


#endif