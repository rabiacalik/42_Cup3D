/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:31:47 by ekaymaz           #+#    #+#             */
/*   Updated: 2023/10/09 15:48:05 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move(t_cub3d *game)
{
	if (game->onkey.keyw)
		setpos(game, game->player->dir.x, game->player->dir.y, '+');
	if (game->onkey.keys)
		setpos(game, game->player->dir.x, game->player->dir.y, '-');
	if (game->onkey.keyd)
		setpos(game, game->player->plane.x, game->player->plane.y, '+');
	if (game->onkey.keya)
		setpos(game, game->player->plane.x, game->player->plane.y, '-');
	if (game->onkey.keyleft || game->onkey.keyright)
		turn(game);
	return (retmove(game));
}

/*
	belirli tuslara basılıp basılmadığını kontrol eder
*/
int	retmove(t_cub3d *game)
{
	if (game->onkey.keyw || game->onkey.keys || game->onkey.keya
		|| game->onkey.keyd || game->onkey.keyleft || game->onkey.keyright)
		return (1);
	else
		return (0);
}
