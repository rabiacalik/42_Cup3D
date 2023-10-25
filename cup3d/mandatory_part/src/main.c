
#include "cub3d.h"

int main(int argc, char **argv)
{
    t_cup3d *game;

    if(argc != 2)
        return(printf("Error : Only 2 arguments should be entered : ./cup3d maps/map.cup\n"));

    game = malloc(sizeof(t_cup3d));
    // yer ayirildi mi kontrolü yapilacak !!!!!!!!!

    if(!initialize(game, argv))
        return (0);
    
    // 1L << 1 neeeğğğ !!!!!!!!!
    mlx_hook(game->win, ON_KEY_UP, 1L << 1, key_up, game);
    mlx_hook(game->win, ON_DESTROY, 1L << 0, finish_game, game);
    mlx_hook(game->win, ON_KEY_DOWN, 1L << 0, key_down, game);

    mlx_loop_hook(game->mlx, basic_loop, game);
    mlx_put_image_to_window(game->mlx, game->win, game->image->img, 0, 0);
    get_screen(game); /// neden tekrar gidiyor zaten dongu halinde degil mi !!!

    mlx_loop(game->mlx);
}
