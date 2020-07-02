/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:50:36 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:50:37 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void	ray_step(t_data *data)
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

void	ray_hit(t_data *data)
{
	while (data->ray.hit == false)
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
			data->ray.side = data->ray.dir.y > 0 ? E : W;
		}
		if (data->map.map[data->ray.mapY][data->ray.mapX] == 1)
			data->ray.hit = true;
	}
}

void	wall_x(t_data *data)
{
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
	if (data->ray.side == 0 || data->ray.side == 1)
		data->ray.wall_x = data->player.pos.y + data->ray.wall_dist
			* data->ray.dir.y;
	else
		data->ray.wall_x = data->player.pos.x + data->ray.wall_dist
			* data->ray.dir.x;
	data->ray.wall_x -= floor(data->ray.wall_x);
}

void	draw_walls(t_data *data)
{
	int		x;

	x = 0;
	while (x < data->win.width)
	{
		data->cam.x = 2 * x / (double)data->win.width - 1;
		data->ray.hit = false;
		data->ray.dir.x = data->player.dir.x
		+ data->player.plane.x * data->cam.x;
		data->ray.dir.y = data->player.dir.y
		+ data->player.plane.y * data->cam.x;
		data->ray.mapX = (int)data->player.pos.x;
		data->ray.mapY = (int)data->player.pos.y;
		data->ray.delta_dist.x = fabs(1 / data->ray.dir.x);
		data->ray.delta_dist.y = fabs(1 / data->ray.dir.y);
		ray_step(data);
		ray_hit(data);
		wall_x(data);
		draw_tex(x, data);
		data->depth_buffer[x] = data->ray.wall_dist;
		x++;
	}
}

void	raycast(t_data *data)
{
	draw_walls(data);
	draw_sprites(data);
	draw_minimap(data);
	draw_lifebar(data);
	draw_cursor(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->display.img, 0, 0);
}
