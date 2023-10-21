/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:37:49 by ekaymaz           #+#    #+#             */
/*   Updated: 2023/10/11 17:15:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	finish(t_cub3d *game) //neden exit ve return var
{
	exit(mlx_destroy_window(game->mlx, game->win));
	return (1);
}
