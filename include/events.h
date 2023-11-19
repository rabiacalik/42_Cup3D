/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:18:38 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 10:37:59 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "cub3d.h"

int		keydown(int keycode, t_cub3d *game);
int		keyup(int keycode, t_cub3d *game);
int		basic_loop(t_cub3d *game);
int		init_event(t_cub3d *game);
void	set_pos(t_cub3d *game, double newposx, double newposy, char mod);
void	turn(t_cub3d *game);

int		retmove(t_cub3d *game);
int		move(t_cub3d *game);
int		finish(t_cub3d *game);

#endif
