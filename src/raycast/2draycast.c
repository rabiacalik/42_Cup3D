/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2draycast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:25:35 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 10:33:05 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_raycast	summonray(t_cub3d *game, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (!game->map->map[ray->map.y])
			break ;
		else if (game->map->map[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
	return (*ray);
}

t_raycast	get_wall_length(t_cub3d *game, t_raycast *ray)
{
	ray->draw.perpwalldist = get_perp_wall_dist(ray);
	ray->draw.lineheight = (int)(SCREEN_HEIGHT / ray->draw.perpwalldist);
	ray->draw.drawwall.x = -ray->draw.lineheight / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw.drawwall.x < 0)
		ray->draw.drawwall.x = 0;
	ray->draw.drawwall.y = ray->draw.lineheight / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw.drawwall.y > SCREEN_HEIGHT)
		ray->draw.drawwall.y = SCREEN_HEIGHT;
	*ray = set_wall(game, ray);
	return (*ray);
}

void	raycast(t_cub3d *game)
{
	int			x;
	t_raycast	ray;

	x = -1;
	ray = init_raycast(game);
	while (++x < SCREEN_WIDTH)
	{
		ray = raycast_loop_start(&ray, x);
		ray = summonray(game, &ray);
		ray = get_wall_length(game, &ray);
		draw_vertical(x, game, &ray);
	}
}
