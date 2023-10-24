
#include "cub3d.h"

void init_keyboard_events(t_cup3d *game)
{
    game->key.key_w = 0;
    game->key.key_a = 0;
    game->key.key_s = 0;
    game->key.key_d = 0;
    game->key.key_up = 0;
    game->key.key_down = 0;
    game->key.key_left = 0;
    game->key.key_right = 0;
}

int init_image(t_cup3d *game)
{
    game->image = malloc(sizeof(t_data));
    ////// malloc kontrol !!!!!!!
    game->image->img = mlx_new_image(game->mlx, 1920, 1080);
    game->image->addr = mlx_get_data_addr(game->image->img, &game->image->bits_per_pixel, &game->image->line_length, &game->image->endian);

    if (!(game->image->img) && !(game->image->addr))
        return (0);

    return (1);
}

int initialize(t_cup3d *game, char **argv)
{
    game->mlx = mlx_init();
    if(!game->mlx)
        return (0);
    
    if(map_creat_and_controll(game, argv[1]))
        return (0);

    game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGH, "cup3d");
    if (!game->win)
        return (0);
    
    init_keyboard_events(game);

    if (!init_player(game))
        return (0);

    if(!init_image(game))
        return (0);

    return (1);
}