/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:18:49 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 15:48:00 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vectord
{
	double	x;
	double	y;
}	t_vectord;

typedef struct s_vectori
{
	int	x;
	int	y;
}	t_vectori;

typedef struct s_onkeys
{
	int			keyw;
	int			keya;
	int			keys;
	int			keyd;
	int			keyup;
	int			keydown;
	int			keyleft;
	int			keyright;
	t_vectori	cursorpos;
}	t_onkeys;

typedef struct s_map
{
	char	**map;
	size_t	x;
	size_t	y;
	int		player_count;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_textures
{
	int		top;
	int		bot;
	t_data	*xpm[4];
	t_data	*sprite[5];
	t_data	*lastanimation;
}	t_textures;

typedef struct s_chararacter
{
	t_vectord	pos;
	t_vectord	dir;
	t_vectord	plane;
	double		angle;
}	t_character;

typedef struct s_draw
{
	int			wall;
	int			color;
	int			lineheight;
	double		step;
	double		texpos;
	double		wallx;
	double		perpwalldist;
	t_vectori	tex;
	t_vectori	drawwall;
}	t_draw;

typedef struct s_raycast
{
	int			hit;
	int			side;
	t_draw		draw;
	t_vectord	pos;
	t_vectord	dir;
	t_vectord	plane;
	t_vectord	raydir;
	t_vectord	deltadist;
	t_vectord	sidedist;
	t_vectori	step;
	t_vectori	map;
}	t_raycast;

typedef struct s_minimap
{
	t_data	*img;
}	t_minimap;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	size_t		loop;
	t_map		*map;
	t_data		*img;
	t_onkeys	onkey;
	t_minimap	*mmap;
	t_raycast	raycast;
	t_textures	texture;
	t_character	*player;
}	t_cub3d;

#endif
