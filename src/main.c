/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:48:05 by vdescham          #+#    #+#             */
/*   Updated: 2019/11/26 11:41:48 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Cub3D.h"

int		game(t_data *data)
{
	int		x;
	int		hit;
	int		side;
	int		line_height;
	double	perp_wall_dist;
	int		draw_start;
	int		draw_end;
	int		color;

	x = 0;
	move_player(data);
	while (x < data->win->width)
	{
		// ray position and direction
		data->cam.x = 2 * x / (double)data->win->width - 1;
		data->ray->dir.x = data->player->dir.x
		+ data->player->plane.x * data->cam.x;
		data->ray->dir.y = data->player->dir.y
		+ data->player->plane.y * data->cam.x;

		//which box we're in
		data->ray->mapX = (int)data->player->pos.x;
		data->ray->mapY = (int)data->player->pos.y;

		// distance to the next box in x or y
		data->ray->delta_dist.x = fabs(1 / data->ray->dir.x);
		data->ray->delta_dist.y = fabs(1 / data->ray->dir.y);

		hit = 0;
		if (data->ray->dir.x < 0)
		{
			data->ray->stepX = -1;
			data->ray->side_dist.x = (data->player->pos.x - data->ray->mapX)
			* data->ray->delta_dist.x;
		}
		else
		{
			data->ray->stepX = 1;
			data->ray->side_dist.x = (data->ray->mapX + 1.0 -
			data->player->pos.x) * data->ray->delta_dist.x;
		}
		if (data->ray->dir.y < 0)
		{
			data->ray->stepY = -1;
			data->ray->side_dist.y = (data->player->pos.y - data->ray->mapY)
			* data->ray->delta_dist.y;
		}
		else
		{
			data->ray->stepY = 1;
			data->ray->side_dist.y = (data->ray->mapY + 1.0 -
			data->player->pos.y) * data->ray->delta_dist.y;
		}
		while (hit == 0)
		{
			if (data->ray->side_dist.x < data->ray->side_dist.y)
			{
				data->ray->side_dist.x += data->ray->delta_dist.x;
				data->ray->mapX += data->ray->stepX;
				side = 0;
			}
			else
			{
				data->ray->side_dist.y += data->ray->delta_dist.y;
				data->ray->mapY += data->ray->stepY;
				side = 1;
			}
			if (data->map[data->ray->mapX][data->ray->mapY] > 0)
				hit = 1;
		}
		if (side == 0)
		{
			perp_wall_dist = (data->ray->mapX - data->player->pos.x
							+ (1 - data->ray->stepX) / 2) / data->ray->dir.x;
		}
		else
		{
			perp_wall_dist = (data->ray->mapY - data->player->pos.y
							+ (1 - data->ray->stepY) / 2) / data->ray->dir.y;
		}
		line_height = (int)(data->win->height / perp_wall_dist);
		draw_start = -line_height / 2 + data->win->height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + data->win->height / 2;
		if (draw_end >= data->win->height)
			draw_end = data->win->height - 1;
		switch (data->map[data->ray->mapX][data->ray->mapY])
		{
			case 1: color = 0xB37339; break;
			case 2: color = 0xF8C71C; break;
			case 3: color = 0xA15CD4; break;
			case 4: color = 0xDB2732; break;
			default : color = 0xFFFF00; break;
		}
		// if (side == 1)
		// 	color = color / 2;
		draw_line(x, draw_start, draw_end, color, data);
		x++;
	}
	return (0);
}

int		move_player(t_data *data)
{
	//move forward if no wall in front of you
    if (data->key->up == 1)
    {
      if(data->map[(int)(data->player->pos.x + data->player->dir.x * data->player->move_speed)][(int)(data->player->pos.y)] == false) data->player->pos.x += data->player->dir.x * data->player->move_speed;
      if(data->map[(int)(data->player->pos.x)][(int)(data->player->pos.y + data->player->dir.y * data->player->move_speed)] == false) data->player->pos.y += data->player->dir.y * data->player->move_speed;
    }
    //move backwards if no wall behind you
    if (data->key->down == 1)
    {
      if(data->map[(int)(data->player->pos.x - data->player->dir.x * data->player->move_speed)][(int)(data->player->pos.y)] == false) data->player->pos.x -= data->player->dir.x * data->player->move_speed;
      if(data->map[(int)(data->player->pos.x)][(int)(data->player->pos.y - data->player->dir.y * data->player->move_speed)] == false) data->player->pos.y -= data->player->dir.y * data->player->move_speed;
    }
    //rotate to the right
    if (data->key->right == 1)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX =  data->player->dir.x;
       data->player->dir.x =  data->player->dir.x * cos(-data->player->rot_speed) -  data->player->dir.y * sin(-data->player->rot_speed);
       data->player->dir.y = oldDirX * sin(-data->player->rot_speed) +  data->player->dir.y * cos(-data->player->rot_speed);
      double oldPlaneX =  data->player->plane.x;
      data->player->plane.x = data->player->plane.x * cos(-data->player->rot_speed) - data->player->plane.y * sin(-data->player->rot_speed);
      data->player->plane.y = oldPlaneX * sin(-data->player->rot_speed) + data->player->plane.y * cos(-data->player->rot_speed);
    }
    //rotate to the left
    if (data->key->left == 1)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX =  data->player->dir.x;
      data->player->dir.x =  data->player->dir.x * cos(data->player->rot_speed) - data->player->dir.y * sin(data->player->rot_speed);
       data->player->dir.y = oldDirX * sin(data->player->rot_speed) + data->player->dir.y * cos(data->player->rot_speed);
      double oldPlaneX = data->player->plane.x;
      data->player->plane.x = data->player->plane.x * cos(data->player->rot_speed) - data->player->plane.y * sin(data->player->rot_speed);
      data->player->plane.y = oldPlaneX * sin(data->player->rot_speed) + data->player->plane.y * cos(data->player->rot_speed);
    }
	return (0);
}

int		main(int ac, char **av)
{
	t_data		*data;

	(void)ac;
	data = malloc(sizeof(t_data));
	data->ray = malloc(sizeof(t_ray));
	init(av, data);
	game(data);
	mlx_do_key_autorepeatoff(data->mlx_ptr);
	mlx_hook(data->win_ptr, 2, 0, key_pressed, data);
	mlx_hook(data->win_ptr, 3, 0, key_released, data);
	mlx_hook(data->win_ptr, 17, 0, exit_game, data);
	mlx_loop_hook(data->mlx_ptr, game, data);
	mlx_loop(data->mlx_ptr);
}
