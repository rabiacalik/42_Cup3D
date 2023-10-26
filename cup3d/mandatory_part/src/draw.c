#include "cub3d.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (y < 0 || y > SCREEN_HEIGH)
        return ;
    if (x < 0 || x > SCREEN_WIDTH)
        return ;
    if (!data->addr)
        return ;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}


size_t	get_texture_color(t_data *texture, int pixel_x, int pixel_y)
{
	return (*(size_t *)((texture->addr + (pixel_y * texture->line_length)
			+ (pixel_x * texture->bits_per_pixel / 8))));
}

static void fill_image(int x, t_cub3d *game, t_raycast *ray)
{
    size_t y;
    t_data *tmp;

    y = -1;
    tmp = game->texture.xpm[ray->draw.wall];

    while (++y < SCREEN_HEIGH)
    {
        if (y < (size_t)ray->draw.draw_wall.x)
            my_mlx_pixel_put(game->image, x, y, ray->draw.color);//neydu belirsiz image burada işleniyor!!!!
        
        else if (y < (size_t)ray->draw.draw_wall.y)
        {
            ray->draw.texture.y = (int)ray->draw.texpos & (64 - 1);
            ray->draw.texpos += ray->draw.step;
            ray->draw.color = get_texture_color(tmp, ray->draw.texture.x, ray->draw.texture.y);
            my_mlx_pixel_put(game->image, x, y, ray->draw.color);
        }
        else
            my_mlx_pixel_put(game->image, x, y, game->texture.bot);
    }
}

void draw_vertical(int x, t_cub3d *game, t_raycast *ray)
{
    ray->draw.wall_x -= floor(ray->draw.wall_x); // sayıyı yakın degerine yuvarladık
    ray->draw.texture.x = (int)(ray->draw.wall_x * (double)(64));

    if (ray->wall_direction == 0 && ray->dir.x > 0)
        ray->draw.texture.x = 64 - ray->draw.texture.x -1;

    if (ray->wall_direction == 1 && ray->dir.y < 0)
         ray->draw.texture.x = 64 - ray->draw.texture.x -1;

    ray->draw.step = 1.0 * 64 / ray->draw.line_heigth;
    ray->draw.texpos = (ray->draw.draw_wall.x - SCREEN_HEIGH / 2 + ray->draw.line_heigth / 2) * ray->draw.step;

    fill_image(x, game, ray);
}