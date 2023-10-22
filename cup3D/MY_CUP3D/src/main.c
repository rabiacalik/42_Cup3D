
#include "cub3d.h"

int main(int argc, char **argv)
{
    t_cup3d *game;

    if(argc != 2)
    {
        return(printf("error"));
    }

    game = malloc(sizeof(t_cup3d));
    // yer ayirildi mi kontrolü yapilacak !!!!!!!!!

    if(!main_part_two(game, argv))
        return (0);

}

int main_part_two(t_cup3d *game, char **argv)
{
    game->mlx = mlx_init();
    if(!game->mlx)
        return (0);
    
    if(map_creat_and_controll(game, argv[1]))
        return (0);

    return (1);
}