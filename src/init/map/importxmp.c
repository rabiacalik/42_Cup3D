/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   importxmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:31:53 by ekaymaz           #+#    #+#             */
/*   Updated: 2023/10/08 11:32:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	belirli bir indexteki bir xpm dosyasını yüklemek ve bu dosyadan elde edilen görüntü ve veri
	adresini oyun yapısına kaydetmektir.

	mlx_get_data_addr = verilen imege nin verisinin adresini almak için kullanılır.
	mlx_xpm_file_to_image = xpm dosyasından bir image oluşturur
*/
static int	load(int i, t_cub3d *game, char *line)
{
	int		size;
	char	*sprite;
	t_data	*tmp;

	size = 64;
	game->texture.xpm[i] = malloc(sizeof(t_data));
	tmp = game->texture.xpm[i];
	sprite = ft_strndup(&line[3], ft_strlen(&line[3]) - 1);
	tmp->img = mlx_xpm_file_to_image(game->mlx, sprite, &size, &size);
	tmp->addr = mlx_get_data_addr(tmp->img,
			&(tmp->bits_per_pixel), &(tmp->line_length), &(tmp->endian));
	if (!(tmp->img) || !(tmp->addr))
		return (0);
	if (sprite)
		free(sprite);
	return (1);
}

//* 0xffffff == 255, 255, 255 == 16777215 beyaz
/*
	color rengimizin kırmızı yeşil mavi değerlerinin birleştirilmesiyle oluşturuluyor
	eğer satır F ile başlıyorsa color bot ile ilişkilendirilir (botton = zemin)
	değilse color top ile ilişkilendirilir (tavan)
*/
static int	getcolor(t_cub3d *game, char *line)
{
	char	**rgb;
	int		color;

	rgb = 0;
	rgb = ft_split(line, ',');
	color = \
	(ft_atoi(&rgb[0][2]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
	if (!ft_strncmp(line, "F ", 2))
		game->texture.bot = color;
	else
		game->texture.top = color;
	color = 0;
	while (rgb[color])
		free(rgb[color++]);
	free(rgb);
	return (0);
}

/*
	harita ve görüntü dosyalarını yüklemek

	satır başında yeni satır varsa sıfır dönüyor
	
	No - North - kuzey görüntüsü yükleniyor
	So - South - güney görüntüsü yükleniyor
	We - West - batı görüntüsü yükleniyor
	Ea - East - doğu görüntüsü yükleniyor
	F veya C renk degerleri alınıyor tavan-zemin
*/
int	importxpm(t_cub3d *game, char *line)
{
	if (!ft_strncmp(line, "\n", 1))
		return (0);
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (!load(0, game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		if (!load(1, game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		if (!load(2, game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		if (!load(3, game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (getcolor(game, line));
	return (0);
}
