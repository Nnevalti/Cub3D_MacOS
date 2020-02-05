#include "../include/Cub3D.h"

void init_raycasting(t_data *data)
{
	data->ray.dir.x = data->player.dir.x
	+ data->player.plane.x * data->cam.x;
	data->ray.dir.y = data->player.dir.y
	+ data->player.plane.y * data->cam.x;

	data->ray.mapX = (int)data->player.pos.x;
	data->ray.mapY = (int)data->player.pos.y;

	data->ray.delta_dist.x = fabs(1 / data->ray.dir.x);
	data->ray.delta_dist.y = fabs(1 / data->ray.dir.y);

}

void ray_step(t_data *data)
{
	if (data->ray.dir.x < 0)
	{
		data->ray.stepX = -1;
		data->ray.side_dist.x = (data->player.pos.x - data->ray.mapX)
		* data->ray.delta_dist.x;
	}
	else
	{
		data->ray.stepX = 1;
		data->ray.side_dist.x = (data->ray.mapX + 1.0 -
		data->player.pos.x) * data->ray.delta_dist.x;
	}
	if (data->ray.dir.y < 0)
	{
		data->ray.stepY = -1;
		data->ray.side_dist.y = (data->player.pos.y - data->ray.mapY)
		* data->ray.delta_dist.y;
	}
	else
	{
		data->ray.stepY = 1;
		data->ray.side_dist.y = (data->ray.mapY + 1.0 -
		data->player.pos.y) * data->ray.delta_dist.y;
	}
}

void ray_hit(t_data *data)
{
			while (data->ray.hit == 0)
			{
				if (data->ray.side_dist.x < data->ray.side_dist.y)
				{
					data->ray.side_dist.x += data->ray.delta_dist.x;
					data->ray.mapX += data->ray.stepX;
					data->ray.side = data->ray.dir.x > 0 ? N : S;
				}
				else
				{
					data->ray.side_dist.y += data->ray.delta_dist.y;
					data->ray.mapY += data->ray.stepY;
					data->ray.side = data->ray.dir.y > 0 ? E : O;
				}
				if (data->map[data->ray.mapX][data->ray.mapY] > 0)
					data->ray.hit = 1;
			}
}

void wall_height(t_data *data) {
	if (data->ray.side == 0 || data->ray.side == 1)
	{
		data->ray.wall_dist = (data->ray.mapX - data->player.pos.x
						+ (1 - data->ray.stepX) / 2) / data->ray.dir.x;
	}
	else
	{
		data->ray.wall_dist = (data->ray.mapY - data->player.pos.y
						+ (1 - data->ray.stepY) / 2) / data->ray.dir.y;
	}
	data->ray.line_height = (int)(data->win.height / data->ray.wall_dist);
	data->ray.wall_start = -data->ray.line_height / 2 + data->win.height / 2;
	data->ray.wall_end = data->ray.line_height / 2 + data->win.height / 2;
}

void wall_x(t_data *data) {
	if (data->ray.side == 0 || data->ray.side == 1)
		data->ray.wall_x = data->player.pos.y + data->ray.wall_dist * data->ray.dir.y;
	else
		data->ray.wall_x = data->player.pos.x + data->ray.wall_dist * data->ray.dir.x;
	data->ray.wall_x -= floor(data->ray.wall_x);
}

void	raycast(t_data *data)
{
	int		x;

	x = 0;
	while (x < data->win.width)
	{
		data->cam.x = 2 * x / (double)data->win.width - 1;
		data->ray.hit = 0;
		init_raycasting(data);
		ray_step(data);
		ray_hit(data);
		wall_height(data);
		wall_x(data);
		draw_tex(x, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->display.img, 0, 0);
}

int		game(t_data *data)
{
	if (move_player(data))
		raycast(data);
	return(0);
}
