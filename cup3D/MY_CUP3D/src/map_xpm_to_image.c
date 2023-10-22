#include "cub3d.h"

static int map_asign_value(t_cup3d *game, char *line, int i)
{
    int size;
    char *sprite;
    t_data *tmp;

    size = 64;
    
    game->texture.xpm[i] = malloc(sizeof(t_data));
    tmp = game->texture.xpm[i];
    sprite = ft_strndup(&line[3], ft_strlen(&line[3]) - 1);
    // addr ye tekarar bak !!!!!!!!!!
    tmp->img = mlx_xpm_file_to_image(game->mlx, sprite, &size, &size);
    tmp->addr = mlx_get_data_addr(tmp->img, &(tmp->bits_per_pixel), &(tmp->line_length), &(tmp->endian));

    if (!(tmp->img) || !(tmp->addr))
        return (0);
    
    if (sprite)
        free(sprite);
    
    return (1);
}

int get_color(t_cup3d *game, char *line)
{
    char **rgb;
    int color;

    rgb = 0;
    rgb = ft_split(line, ',');
    color = ft_atoi(&rgb[0][2]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]); 

    if (!ft_strncmp(line, "F", 2))
        game->texture.bot = color;
    else
        game->texture.top = color;
    
    color = 0;
    while (rgb[color])
        free(rgb[color++]);
    free(rgb);

    return(0);
}

int map_xpm_to_image(t_cup3d *game, char *line)
{
    if (!ft_strncmp(line, "\n", 1))
        return (0);
    
    if (!ft_strncmp(line, "NO ", 3))
    {
        if (!map_asign_value(game, line, 0))
            return (printf("File Not Found : %s\n", &line[3]));
    }

    else if (!ft_strncmp(line, "SO ", 3))
    {
        if (!map_asign_value(game, line, 1))
            return (printf("File Not Found : %s\n", &line[3]));
    }

    else if (!ft_strncmp(line, "WE ", 3))
    {
        if (!map_asign_value(game, line, 2))
            return (printf("File Not Found : %s\n", &line[3]));
    }

    else if (!ft_strncmp(line, "EA ", 3))
    {
        if (!map_asign_value(game, line, 3))
            return (printf("File Not Found : %s\n", &line[3]));
    }

    else if (!ft_strncmp(line, "F", 2) || !ft_strncmp(line, "C", 2))
        return (get_color(game, line));
        
    return (0);
}
