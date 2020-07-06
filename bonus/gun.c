/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:47:52 by vdescham          #+#    #+#             */
/*   Updated: 2020/07/02 16:47:53 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void	gun_step(t_data *data)
{
	if (data->gun.dir.x < 0)
	{
		data->gun.stepX = -1;
		data->gun.side_dist.x = (data->player.pos.x - data->gun.mapX)
		* data->gun.delta_dist.x;
	}
	else
	{
		data->gun.stepX = 1;
		data->gun.side_dist.x = (data->gun.mapX + 1.0 -
		data->player.pos.x) * data->gun.delta_dist.x;
	}
	if (data->gun.dir.y < 0)
	{
		data->gun.stepY = -1;
		data->gun.side_dist.y = (data->player.pos.y - data->gun.mapY)
		* data->gun.delta_dist.y;
	}
	else
	{
		data->gun.stepY = 1;
		data->gun.side_dist.y = (data->gun.mapY + 1.0 -
		data->player.pos.y) * data->gun.delta_dist.y;
	}
}

void	calc_gun_hit(t_data *data)
{
	if (data->gun.side_dist.x < data->gun.side_dist.y)
	{
		data->gun.side_dist.x += data->gun.delta_dist.x;
		data->gun.mapX += data->gun.stepX;
	}
	else
	{
		data->gun.side_dist.y += data->gun.delta_dist.y;
		data->gun.mapY += data->gun.stepY;
	}
}

void	ennemy_sound(int ennemy)
{
	if (ennemy == 9)
		system("afplay Musics/death.mp3 &");
	if (ennemy == 8)
		system("afplay Musics/wilhem.mp3 -r 2 &");
	if (ennemy == 3 || ennemy == 4)
		system("afplay Musics/stupid.mp3 &");
	if (ennemy == 2)
		system("afplay Musics/barrel.mp3 &");
	if (ennemy == 4 || ennemy == 5)
		system("afplay Musics/off.mp3 &");
	if (ennemy == 6)
		system("afplay Musics/done.mp3 -v 3 &");
}

void	gun_hit(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < 5)
	{
		calc_gun_hit(data);
		j = 0;
		while (j < data->nb_sprites)
		{
			if (data->gun.mapX == (int)data->spr[j].pos.x
				&& data->gun.mapY == (int)data->spr[j].pos.y)
			{
				data->gun.hit = true;
				data->spr[j].is_alive = false;
				ennemy_sound(data->map.map[data->gun.mapY][data->gun.mapX]);
				data->map.map[data->gun.mapY][data->gun.mapX] = 0;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	shoot(t_data *data)
{
	int		x;

	x = data->win.width / 2;
	data->cam.x = 2 * x / (double)data->win.width - 1;
	data->gun.hit = false;
	data->gun.dir.x = data->player.dir.x
	+ data->player.plane.x * data->cam.x;
	data->gun.dir.y = data->player.dir.y
	+ data->player.plane.y * data->cam.x;
	data->gun.mapX = (int)data->player.pos.x;
	data->gun.mapY = (int)data->player.pos.y;
	data->gun.delta_dist.x = fabs(1 / data->gun.dir.x);
	data->gun.delta_dist.y = fabs(1 / data->gun.dir.y);
	gun_step(data);
	gun_hit(data);
	data->player.is_shooting = true;
}
