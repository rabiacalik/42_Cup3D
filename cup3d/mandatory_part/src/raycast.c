#include "cub3d.h"

// rayy in pos, dir, plane degerleri playera göre atandi
t_raycast init_raycast(t_cub3d *game)
{
	t_raycast ray;

	ray.pos.x = game->player->pos.x; //ray in mevcut konumu
	ray.pos.y = game->player->pos.y;

	ray.plane.x = game->player->plane.x;
	ray.plane.y = game->player->plane.y;

	ray.dir.x = game->player->dir.x;
	ray.dir.y = game->player->dir.y;

	return (ray);
}

double double_abs(double n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

// static olması şart mıydı !!!!!!
static t_raycast *set_side_dist(t_raycast *ray)
{
	if (ray->dir.x < 0) // buralara tekrar bak anlamadın !!!!
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	}

	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->delta_dist.y = (ray->map.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->side_dist.y;
	}
	return (ray);
}

t_raycast raycast_loop_start(t_raycast *ray, int x)
{
	double camera;

	camera = 2 * x / (double)SCREEN_WIDTH - 1; //neden !!!!!!!

	ray->dir.x = ray->dir.x + ray->plane.x * camera;
	ray->dir.y = ray->dir.y + ray->plane.y * camera;

	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;

	ray->delta_dist.x = double_abs(1 / ray->dir.x);
	ray->delta_dist.y = double_abs(1 / ray->dir.y);

	ray = set_side_dist(ray);

	ray->wall_flag = 0;
	
	return (*ray);
}

t_raycast come_here_ray(t_cub3d *game, t_raycast *ray)
{
	while (ray->wall_flag == 0)
	{
		if (ray->side_dist.x += ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->wall_direction = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->wall_direction = 1;
		}

		if (!game->map->map[(int)ray->map.y]) // int ekledim
			break;
		else if (game->map->map[(int)ray->map.y][(int)ray->map.x] == '1')
			ray->wall_flag = 1;
	}
	return (*ray);
}

double get_perpendicular_dist(t_raycast *ray)
{
	if (ray->wall_direction == 0)
		return (ray->side_dist.x - ray->delta_dist.x);
	else
		return (ray->side_dist.y - ray->delta_dist.y);
}

t_raycast set_wall(t_cub3d *game, t_raycast *ray)
{
	if (ray->wall_direction == 0)
	{
		ray->draw.wall_x = game->player->pos.y + ray->draw.perpendicular_wall_dist * ray->dir.y;
		if (ray->map.x < game->player->pos.x)
			ray->draw.wall = 3;
		else
			ray->draw.wall = 2;
	}
	else
	{	
		ray->draw.wall_x = game->player->pos.x + ray->draw.perpendicular_wall_dist * ray->dir.x;
		if (ray->map.y < game->player->pos.y)
			ray->draw.wall = 1;
		else
			ray->draw.wall = 0;
	}
	return (*ray);
}

t_raycast get_wall_length(t_cub3d *game, t_raycast *ray)
{

	ray->draw.perpendicular_wall_dist = get_perpendicular_dist(ray);
	ray->draw.line_heigth = (int)(SCREEN_HEIGH / ray->draw.perpendicular_wall_dist); ///!!
	ray->draw.draw_wall.x = -ray->draw.line_heigth / 2 + SCREEN_HEIGH / 2;
	if (ray->draw.draw_wall.x < 0)
		ray->draw.draw_wall.x = 0;
	
	ray->draw.draw_wall.y = ray->draw.line_heigth / 2 + SCREEN_HEIGH / 2;
	if (ray->draw.draw_wall.y > SCREEN_HEIGH)
		ray->draw.draw_wall.y = SCREEN_HEIGH;

	*ray = set_wall(game, ray);
	return (*ray);
}

void raycast(t_cub3d *game)
{
	int x;
	t_raycast ray;

	x = -1;
	ray = init_raycast(game);

	while (++x < SCREEN_WIDTH) /// nedennn bu boyut !!!!!!
	{
		ray = raycast_loop_start(&ray, x);
		ray = come_here_ray(game, &ray);
		ray = get_wall_length(game, &ray);
		draw_vertical(x, game, &ray);
	}
	

	// devam ediyor ..
}