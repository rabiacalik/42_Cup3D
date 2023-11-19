/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgenerate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <mgencali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:20:03 by rcalik            #+#    #+#             */
/*   Updated: 2023/11/15 13:48:51 by mgencali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <fcntl.h>

int	fill_map_spaces(char **map, int xlen, int i)
{
	int		j;
	char	*tmp;

	while (map[++i])
	{
		tmp = ft_calloc(xlen + 1, 1);
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr("10NSE W", map[i][j]))
				return (0);
			tmp[j] = map[i][j];
		}
		while (++j < xlen)
			tmp = ft_gnl_strjoin(tmp, " ");
		free(map[i]);
		map[i] = tmp;
	}
	return (1);
}

char	*get_map_text(int fd)
{
	char	*str;
	char	*check;

	check = NULL;
	str = NULL;
	while (1)
	{
		if (check)
			free(check);
		check = get_next_line(fd);
		if (ft_strncmp(check, "\n", 1))
			break ;
	}
	str = 0;
	while (1)
	{
		str = ft_gnl_strjoin(str, check);
		free(check);
		check = get_next_line(fd);
		if (!check)
			break ;
	}
	return (str);
}

char	**get_map(t_cub3d *game, int fd)
{
	size_t	tmp;
	char	**map;
	char	*text;
	char	*check;

	text = get_map_text(fd);
	check = ft_strnstr(text, "\n\n", ft_strlen(text));
	if (check)
	{
		free(text);
		return (NULL);
	}
	map = ft_split(text, '\n');
	free(text);
	game->map->y = 0;
	game->map->x = 0;
	while (map[game->map->y])
	{
		tmp = ft_strlen(map[game->map->y]);
		if (game->map->x < tmp)
			game->map->x = tmp + 1;
		game->map->y++;
	}
	return (map);
}

int	load_sprites(int fd, t_cub3d *game)
{
	char	*line;
	int		ret;

	ret = 0;
	line = 0;
	while (1)
	{
		line = get_next_line(fd);
		ret++;
		if (import_xpm(game, line))
			return (0);
		free(line);
		if (game->texture.bot && game->texture.top)
			break ;
	}
	return (ret);
}

int	map_generate(t_cub3d *game, char *file)
{
	int	fd;

	if (ft_strlen(file) < 5 || ft_strrcmp(file, ".cub") != 0)
		return (!printf("Wrong file format: correct file format: file.cub\n"));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (!printf("File Not Found :%s\n", file));
	if (!load_sprites(fd, game))
		return (0);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (0);
	game->map->map = get_map(game, fd);
	if (!game->map->map)
		return (!printf("Some Error Accuired.\n"));
	if (!fill_map_spaces(game->map->map, game->map->x, -1))
		return (!printf("Unsupported character detected.\n"));
	if (!map_check(game->map->map))
		return (!printf("Map & Player must be covered by wall(s)\n"));
	close(fd);
	return (1);
}
