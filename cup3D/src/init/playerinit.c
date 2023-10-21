/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:32:15 by ekaymaz           #+#    #+#             */
/*   Updated: 2023/10/09 15:35:40 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	setplane fonksiyonu, bir t_cub3d yapısı içindeki player öğesinin plane 
	özelliğini ayarlamak için kullanılan bir fonksiyondur. Bu özellik, 
	oyuncunun bakış açısına (kuzey, güney, batı veya doğu) bağlı olarak belirlenir. 
	Fonksiyon, karakter d parametresine göre belirli bir yöne bakış açısına sahip 
	olan plane özelliğini ayarlar.
*/
void	setplane(t_cub3d *game, char d)
{
	if (d == 'N')
	{
		game->player->plane.x = FOV;
		game->player->plane.y = 0;
	}
	else if (d == 'S')
	{
		game->player->plane.x = -FOV;
		game->player->plane.y = 0;
	}
	else if (d == 'W')
	{
		game->player->plane.x = 0;
		game->player->plane.y = -FOV;
	}
	else if (d == 'E')
	{
		game->player->plane.x = 0;
		game->player->plane.y = FOV;
	}
}

/*
	Bu fonksiyon, bir t_cub3d yapısı içindeki player öğesinin dir 
	özelliğini ayarlamak için kullanılır. Bu özellik, oyuncunun başlangıçta
	hangi yöne bakacağını belirler. Fonksiyon, karakter c parametresine göre
	belirli bir yöne bakış açısına sahip olan dir özelliğini ayarlar ve ardından 
	setplane fonksiyonunu çağırarak oyuncunun bakış açısına uygun plane özelliğini ayarlar.
*/
void	getplayerdir(t_cub3d *game, char c)
{
	if (c == 'N')
	{
		game->player->dir.x = 0;
		game->player->dir.y = -1;
	}
	else if (c == 'S')
	{
		game->player->dir.x = 0;
		game->player->dir.y = 1;
	}
	else if (c == 'W')
	{
		game->player->dir.x = -1;
		game->player->dir.y = 0;
	}
	else if (c == 'E')
	{
		game->player->dir.x = 1;
		game->player->dir.y = 0;
	}
	setplane(game, c);
}

/*
	Oyuncu karakterinin başlangıç pozisyonunu belirle.
	Oyuncu karakterinin başlangıç bakış açısını belirle.
	Haritada sadece bir oyuncu olup olmadığını kontrol et.
	Oyuncu karakterini oluşturulan başlangıç değerleriyle doldur.
*/
int	initialize_player(t_cub3d *game)
{
	int	i;
	int	j;

	i = -1;
	game->player = malloc(sizeof(t_character));
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (ft_strchr("NSEW", game->map->map[i][j]))
			{
				game->player->pos.x = (double)j + 0.5; // neden
				game->player->pos.y = (double)i + 0.5;
				game->map->player_count++;
				getplayerdir(game, game->map->map[i][j]);
			}
		}
	}
	if (game->map->player_count == 1)
		return (1);
	return (!printf("Too much player\n"));
}
