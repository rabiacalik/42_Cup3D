/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:20:08 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 13:20:38 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_event(t_cub3d *game)
{
	game->onkey.keya = 0;
	game->onkey.keys = 0;
	game->onkey.keyd = 0;
	game->onkey.keyw = 0;
	game->onkey.keyup = 0;
	game->onkey.keydown = 0;
	game->onkey.keyleft = 0;
	game->onkey.keyright = 0;
	return (0);
}

int	initialize_image(t_cub3d *game)
{
	game->img = malloc(sizeof(t_data));
	if (!game->img)
		return (0);
	game->img->img = mlx_new_image(game->mlx, 1920, 1080);
	game->img->addr = \
	mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel,
			&game->img->line_length, &game->img->endian);
	if (!(game->img->img) || !(game->img->addr))
		return (0);
	else
		return (1);
}

int	initialize(t_cub3d *game, char **argv)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (0);
	if (!map_generate(game, argv[1]))
		return (0);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!(game->win))
		return (0);
	init_event(game);
	game->map->player_count = 0;
	if (!initialize_player(game))
		return (0);
	if (!initialize_image(game))
		return (0);
	mlx_hook(game->win, ON_KEYUP, 1L << 1, keyup, game);
	mlx_hook(game->win, ON_DESTROY, 1L << 0, finish, game);
	mlx_hook(game->win, ON_KEYDOWN, 1L << 0, keydown, game);
	mlx_loop_hook(game->mlx, basic_loop, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	get_screen(game);
	return (1);
}
