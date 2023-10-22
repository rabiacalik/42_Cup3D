
#include "cub3d.h"

char *get_map_text(int map_file)
{
    char *str;
    char *check;

    check = 0;
    while (1) //bastaki \n leri atlar
    {
        if (check)
            free(check);
        
        check = get_next_line(map_file);
        if (ft_strncmp(check, "\n", 1))
            break;
    }

    str = 0;
    while (1)
    {
        str = ft_strjoin(str, check);
        free(check);
        check = get_next_line(map_file);
        if (!check)
            break;
    }
    return (str); //haritayi tek dizi olarak döner
}

char **get_map(t_cup3d *game, int map_file)
{
    size_t tmp;
    char **map;
    char *text_map;
    char *check;

    text_map = get_map_text(map_file);
    // devam ediyor ..   
}

int map_sprites_loading(int fd, t_cup3d *game)
{
    char *line;
    int i;

    i = 0;
    line = 0;

    while (1)
    {
        line = get_next_line(fd);
        i++;

        if (map_xpm_to_image(game, line))
            return (0);
        
        free(line);

        //bot ve top degerleri de atanmissa buradaki is bitmistir
        if (game->texture.bot && game->texture.top)
            break;
    }
    return (i);
}

int map_creat_and_controll(t_cup3d *game, char *map_file)
{
    int fd;

    game->map = malloc(sizeof(t_map)); // kontrol yapilmali !!!

    if (ft_strlen(map_file) < 5 || ft_strrcmp(map_file, ".cup") != 0)
        return (!printf("Error : Wrong file format : Correct file format : map_file.cup\n"));
    
    fd = open(map_file, O_RDONLY);
    if (fd < 0)
        return (!printf("Error : File not found : %s\n", map_file));

    if (!map_sprites_loading(fd, game))
        return (!printf("Error : There was a problem loading map images\n"));
    
    game->map->map = get_map(game, map_file);

    // devam ediyor...


}