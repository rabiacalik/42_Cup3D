/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:26:06 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 10:40:22 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_perp_wall_dist(t_raycast *ray)
{
	if (ray->side == 0)
		return (ray->sidedist.x - ray->deltadist.x);
	else
		return (ray->sidedist.y - ray->deltadist.y);
}

t_raycast	set_wall(t_cub3d *game, t_raycast *ray)
{
	if (ray->side == 0)
	{
		ray->draw.wallx = \
			game->player->pos.y + ray->draw.perpwalldist * ray->raydir.y;
		if (ray->map.x < game->player->pos.x)
			ray->draw.wall = 3;
		else
			ray->draw.wall = 2;
	}
	else
	{
		ray->draw.wallx = \
			game->player->pos.x + ray->draw.perpwalldist * ray->raydir.x;
		if (ray->map.y < game->player->pos.y)
			ray->draw.wall = 1;
		else
			ray->draw.wall = 0;
	}
	return (*ray);
}
