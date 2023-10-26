#include "cub3d.h"

static double  get_distance(double new_pos)
{
    return (new_pos * WALKINGSPEED * WLK);
}

void turn(t_cub3d *game)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = game->player->dir.x;
    old_plane_x = game->player->plane.x;

    if (game->key.key_left)
    {
        game->player->dir.x = game->player->dir.x * cos(-TURNSPEED) - game->player->dir.y * sin(-TURNSPEED);
        game->player->dir.y = old_dir_x           * sin(-TURNSPEED) + game->player->dir.y * cos(-TURNSPEED);

        game->player->plane.x = game->player->plane.x * cos(-TURNSPEED) - game->player->plane.y * sin(-TURNSPEED);
        game->player->plane.y = old_plane_x           * sin(-TURNSPEED) + game->player->plane.y * cos(-TURNSPEED); 
    }
    else
    {
        game->player->dir.x = game->player->dir.x * cos(TURNSPEED) - game->player->dir.y * sin(TURNSPEED);
        game->player->dir.y = old_dir_x           * sin(TURNSPEED) + game->player->dir.y * cos(TURNSPEED);

        game->player->plane.x = game->player->plane.x * cos(TURNSPEED) - game->player->plane.y * sin(TURNSPEED);
        game->player->plane.y = old_plane_x           * sin(TURNSPEED) + game->player->plane.y * cos(TURNSPEED);    
    }
}

void set_pose(t_cub3d *game, double new_pos_x, double new_pos_y, char mod)
{
    double *pos_x;
    double *pos_y;

    pos_x = &(game->player->pos.x);
    pos_y = &(game->player->pos.y);

    if (mod == '-')
    {
        
        if (!(game->map->map[(int)(*pos_y - get_distance(new_pos_y))]))
            return;

        // neden C yi kontrol ediyoruz !!!!!!!!!!!!
        if (ft_strchr("1C", game->map->map[(int)(*pos_y - get_distance(new_pos_y))][(int)(*pos_x - get_distance(new_pos_x))]))
            return;
        
        game->player->pos.x -= new_pos_x * (WALKINGSPEED * WLK); // yukardakine gondermedim !!!dene
        game->player->pos.y -= new_pos_y * (WALKINGSPEED * WLK);
    }

    else if (mod == '+')
    {
        if (!(game->map->map[(int)(*pos_y + get_distance(new_pos_y))]))
            return;

        // neden C yi kontrol ediyoruz !!!!!!!!!!!!
        if (ft_strchr("1C", game->map->map[(int)(*pos_y + get_distance(new_pos_y))][(int)(*pos_x + get_distance(new_pos_x))]))
            return;
        
        game->player->pos.x += new_pos_x * (WALKINGSPEED * WLK);
        game->player->pos.y += new_pos_y * (WALKINGSPEED * WLK);
    }
}

/// gerek var mıydı !!!!!!!!!!!
int ret_move(t_cub3d *game)
{
    if (game->key.key_w || game->key.key_a || game->key.key_s || game->key.key_d || game->key.key_left || game->key.key_right)
        return (1);
    else
        return (0);
}

int move(t_cub3d *game)
{
    if (game->key.key_w) // neden w-s de dir gonderirken, d-a da plane gonderiyoruz !!!!!!
        set_pose(game, game->player->dir.x, game->player->dir.y, '+');

    if (game->key.key_s)
        set_pose(game, game->player->dir.x, game->player->dir.y, '-');

    if (game->key.key_d)
        set_pose(game, game->player->plane.x, game->player->plane.y, '+');

    if (game->key.key_a)
        set_pose(game, game->player->plane.x, game->player->plane.y, '-');
    
    if (game->key.key_left || game->key.key_right)
        turn(game);
    return (ret_move(game));
}
