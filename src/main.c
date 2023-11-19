/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:26:12 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 15:46:57 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_cub3d	*game;

	if (argc != 2)
		return (printf("error: please run with single map: ./cub3d eg.cub\n"));
	game = malloc(sizeof(t_cub3d));
	if (!game)
		return (printf("Some error occured.\n"));
	if (!initialize(game, argv))
	{
		cleaner(game);
		return (printf("Some error occured.\n"));
	}
	mlx_loop(game->mlx);
	map_cleaner(game);
	cleaner(game);
	return (0);
}
