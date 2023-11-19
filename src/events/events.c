/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:19:40 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 10:26:57 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	basic_loop(t_cub3d *game)
{
	if (move(game))
		get_screen(game);
	return (0);
}

void	get_screen(t_cub3d *game)
{
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}

int	keydown(int keycode, t_cub3d *game)
{
	if (keycode == KEY_ESC)
		finish(game);
	else if (keycode == KEY_W)
		game->onkey.keyw = 1;
	else if (keycode == KEY_S)
		game->onkey.keys = 1;
	else if (keycode == KEY_A)
		game->onkey.keya = 1;
	else if (keycode == KEY_D)
		game->onkey.keyd = 1;
	else if (keycode == KEY_LEFT)
		game->onkey.keyleft = 1;
	else if (keycode == KEY_RIGHT)
		game->onkey.keyright = 1;
	return (1);
}

int	keyup(int keycode, t_cub3d *game)
{
	if (keycode == KEY_ESC)
		finish(game);
	else if (keycode == KEY_W)
		game->onkey.keyw = 0;
	else if (keycode == KEY_S)
		game->onkey.keys = 0;
	else if (keycode == KEY_A)
		game->onkey.keya = 0;
	else if (keycode == KEY_D)
		game->onkey.keyd = 0;
	else if (keycode == KEY_LEFT)
		game->onkey.keyleft = 0;
	else if (keycode == KEY_RIGHT)
		game->onkey.keyright = 0;
	return (1);
}
