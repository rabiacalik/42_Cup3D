/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:19:44 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 10:37:42 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move(t_cub3d *game)
{
	if (game->onkey.keyw)
		set_pos(game, game->player->dir.x, game->player->dir.y, '+');
	if (game->onkey.keys)
		set_pos(game, game->player->dir.x, game->player->dir.y, '-');
	if (game->onkey.keyd)
		set_pos(game, game->player->plane.x, game->player->plane.y, '+');
	if (game->onkey.keya)
		set_pos(game, game->player->plane.x, game->player->plane.y, '-');
	if (game->onkey.keyleft || game->onkey.keyright)
		turn(game);
	return (retmove(game));
}

int	retmove(t_cub3d *game)
{
	if (game->onkey.keyw || game->onkey.keys || game->onkey.keya
		|| game->onkey.keyd || game->onkey.keyleft || game->onkey.keyright)
		return (1);
	else
		return (0);
}
