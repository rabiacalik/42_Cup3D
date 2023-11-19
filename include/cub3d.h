/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:18:22 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 14:06:29 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "structures.h"
# include "defines.h"
# include "raycast.h"
# include "events.h"

int		initialize(t_cub3d *init, char **argv);
int		initialize_player(t_cub3d *game);
int		initialize_image(t_cub3d *game);
int		import_xpm(t_cub3d *game, char *line);

void	draw_vertical(int x, t_cub3d *game, t_raycast *ray);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
size_t	get_texture_color(t_data *texture, int pixel_x, int pixel_y);

void	get_screen(t_cub3d *game);

int		map_check(char **map);
int		map_generate(t_cub3d *game, char *file);

void	map_cleaner(t_cub3d *game);
void	cleaner(t_cub3d *game);

int		abs(int n);
double	dabs(double n);

#endif
