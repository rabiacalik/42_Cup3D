/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:25:57 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 14:40:54 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	finish(t_cub3d *game)
{
	exit(mlx_destroy_window(game->mlx, game->win));
	return (1);
}
