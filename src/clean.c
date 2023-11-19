/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:37:22 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 14:23:09 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "unistd.h"

void	cleaner(t_cub3d *game)
{
	int	i;

	i = 0;
	if (game)
	{
		if (game->map)
			free(game->map);
		while (i < 4)
		{
			if (game->texture.xpm[i])
				free(game->texture.xpm[i++]);
		}
		if (game->player)
			free(game->player);
		free(game);
	}
}

void	map_cleaner(t_cub3d *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		if (game->map->map)
		{
			while (game->map->map[i])
			{
				free(game->map->map[i]);
				i++;
			}
			free(game->map->map);
		}
		free(game->map);
	}
}
