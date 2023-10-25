#include "cub3d.h"

void finish_game(t_cup3d *game)
{
	exit(mlx_destroy_window(game->mlx, game->win));
}

void get_screen(t_cup3d *game)
{
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->image->img, 0, 0);
}

int basic_loop(t_cup3d *game)
{
	if (move(game))
		get_screen(game);
	return (0);
}

int key_up(int keycode, t_cup3d *game)
{
	if (keycode == KEY_ESC)
		finish_game(game);
	
	else if (keycode == KEY_W)
		game->key.key_w = 0;
	else if (keycode == KEY_A)
		game->key.key_a = 0;
	else if (keycode == KEY_S)
		game->key.key_s = 0;
	else if (keycode == KEY_D)
		game->key.key_d = 0;
		
	else if (keycode == KEY_LEFT)
		game->key.key_left = 0;
	else if (keycode == KEY_RIGHT)
		game->key.key_right = 0;
	
	return (1);
}

int key_down(int keycode, t_cup3d *game)
{
	if (keycode == KEY_ESC)
		finish_game(game);
	
	else if (keycode == KEY_W)
		game->key.key_w = 1;
	else if (keycode == KEY_A)
		game->key.key_a = 1;
	else if (keycode == KEY_S)
		game->key.key_s = 1;
	else if (keycode == KEY_D)
		game->key.key_d = 1;
		
	else if (keycode == KEY_LEFT)
		game->key.key_left = 1;
	else if (keycode == KEY_RIGHT)
		game->key.key_right = 1;
	
	return (1);
}
