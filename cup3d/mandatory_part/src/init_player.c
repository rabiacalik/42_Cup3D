#include "cub3d.h"

/*
			N
		   +1
			*
			*
  W -1 * * * * * * +1 E
			*
			*
		   -1
		    S
*/

void	init_player_plane(t_cup3d *game, char c)
{
	//// neden yamuk baktırıyoruz !!!!!!!!!! plane neeeğğ
	if (c == 'N')
	{
		game->player->plane.x = FOV;
		game->player->plane.y = 0;
	}

	else if (c == 'S')
	{
		game->player->plane.x = -FOV;
		game->player->plane.y = 0;
	}

	else if (c == 'E')
	{
		game->player->plane.x = 0;
		game->player->plane.y = FOV;
	}

	else if (c == 'W')
	{
		game->player->plane.x = 0;
		game->player->plane.y = -FOV;
	}
}

void    init_player_dir(t_cup3d *game, char c)
{
	if (c == 'N')
	{
		game->player->dir.x = 0;
		game->player->dir.y = 1;
	}

	else if (c == 'S')
	{
		game->player->dir.x = 0;
		game->player->dir.y = -1;
	}

	else if (c == 'E')
	{
		game->player->dir.x = 1;
		game->player->dir.y = 0;
	}

	else if (c == 'W')
	{
		game->player->dir.x = -1;
		game->player->dir.y = 0;
	}
}

int init_player(t_cup3d *game)
{
	int i;
	int j;

	i = -1;
	game->map->player_counter = 0;
	game->player = malloc(sizeof(t_character));
	// malloc kontrol !!!!!

	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (ft_strchr("NSEW", game->map->map[i][j]))
			{
				// karakterin pozisyonu bulundugu kareye ortalanır
				game->player->pos.x = (double)j + 0.5; //neden !!!!
				game->player->pos.y = (double)i + 0.5;

				game->map->player_counter++;

				init_player_dir(game, game->map->map[i][j]);
				init_pleyer_plane(game, game->map->map[i][j]);          
			}
		}
	}
	if (game->map->player_counter == 1)
		return (1);
	return (!printf("Error : A character must appear on the map\n"));
	
}
