/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:18:44 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 10:36:22 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "structures.h"

void		raycast(t_cub3d *game);
double		get_perp_wall_dist(t_raycast *ray);
t_raycast	init_raycast(t_cub3d *game);
t_raycast	set_wall(t_cub3d *game, t_raycast *ray);
t_raycast	raycast_loop_start(t_raycast *ray, int x);

#endif
