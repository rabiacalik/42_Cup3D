/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:26:02 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 12:31:58 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	turn(t_cub3d *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->player->dir.x;
	oldplanex = game->player->plane.x;
	if (game->onkey.keyleft)
	{
		game->player->dir.x = game->player->dir.x * cos(-TURNSPEED)
			- game->player->dir.y * sin(-TURNSPEED);
		game->player->dir.y = olddirx * sin(-TURNSPEED)
			+ game->player->dir.y * cos(-TURNSPEED);
		game->player->plane.x = game->player->plane.x * cos(-TURNSPEED)
			- game->player->plane.y * sin(-TURNSPEED);
		game->player->plane.y = oldplanex * sin(-TURNSPEED)
			+ game->player->plane.y * cos(-TURNSPEED);
		return ;
	}
	game->player->dir.x = game->player->dir.x * cos(TURNSPEED)
		- game->player->dir.y * sin(TURNSPEED);
	game->player->dir.y = olddirx * sin(TURNSPEED)
		+ game->player->dir.y * cos(TURNSPEED);
	game->player->plane.x = game->player->plane.x * cos(TURNSPEED)
		- game->player->plane.y * sin(TURNSPEED);
	game->player->plane.y = oldplanex * sin(TURNSPEED)
		+ game->player->plane.y * cos(TURNSPEED);
}

static double	get_distance(double newpos)
{
	return (newpos * WALKINGSPEED * WLK);
}

void	set_pos(t_cub3d *game, double newposx, double newposy, char mod)
{
	double	*posx;
	double	*posy;

	posx = &(game->player->pos.x);
	posy = &(game->player->pos.y);
	if (mod == '-')
	{
		if (!(game->map->map[(int)(*posy - get_distance(newposy))]))
			return ;
		if (ft_strchr("1C", game->map->map[(int)(*posy - get_distance(newposy))]
			[(int)(*posx - get_distance(newposx))]))
			return ;
		game->player->pos.x -= newposx * (WALKINGSPEED * WLK);
		game->player->pos.y -= newposy * (WALKINGSPEED * WLK);
	}
	else if (mod == '+')
	{
		if (!(game->map->map[(int)(*posy + get_distance(newposy))]))
			return ;
		if (ft_strchr("1C", game->map->map[(int)(*posy + get_distance(newposy))]
			[(int)(*posx + get_distance(newposx))]))
			return ;
		game->player->pos.x += newposx * (WALKINGSPEED * WLK);
		game->player->pos.y += newposy * (WALKINGSPEED * WLK);
	}
}
