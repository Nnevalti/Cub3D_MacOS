/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:59:19 by vdescham          #+#    #+#             */
/*   Updated: 2020/06/30 15:59:23 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void	interact_up(t_data *data)
{
	int	cell;

	cellX = data->map.map[(int)(data->player.pos.y)]
		[(int)(data->player.pos.x + data->player.dir.x
			* data->player.move_speed)];
	cellY = data->map.map[(int)(data->player.pos.y
		+ data->player.dir.y* data->player.move_speed)]
		[(int)(data->player.pos.x)];
	if (cellX >= 7 || cellX <= 9 || cellY >= 7 || cellY <= 9)
	{
		damage = cellX ? cellX : cellY;
		data->player.life -= data->player.damage * damage;
		system("afplay ./Musics/oof.mp3 &");
	}
	if (cellX == 8 || cellY == 8)
	{
		data->player.life -= data->player.damage * 5;
		system("afplay ./Musics/oof.mp3 &");
	}
	if (data->map.map[(int)(data->player.pos.y)][x] == 9
		|| data->map.map[y][(int)(data->player.pos.x)] == 9)
	{
		data->player.life -= data->player.damage * 10;
		system("afplay ./Musics/oof.mp3 &");
	}
	if (data->map.map[(int)(data->player.pos.y)][x] == 4
		|| data->map.map[y][(int)(data->player.pos.x)] == 4)
	{
		data->player.pos.x = data->portal.x;
		data->player.pos.y = data->portal.y;
	}
	if (data->map.map[(int)(data->player.pos.y)][x] == 6
		|| data->map.map[y][(int)(data->player.pos.x)] == 6)
		data->success = true;
}

void	interact_down(t_data *data)
{
	if (data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x
		- data->player.dir.x * data->player.move_speed)] == 7
		|| data->map.map[(int)(data->player.pos.y - data->player.dir.y
		* data->player.move_speed)][(int)(data->player.pos.x)] == 7)
	{
		data->player.life -= data->player.damage;
		system("afplay ./Musics/oof.mp3 &");
	}
	if (data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x
		- data->player.dir.x * data->player.move_speed)] == 8
		|| data->map.map[(int)(data->player.pos.y - data->player.dir.y
		* data->player.move_speed)][(int)(data->player.pos.x)] == 8)
	{
		data->player.life -= data->player.damage * 5;
		system("afplay ./Musics/oof.mp3 &");
	}
	if (data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x
		- data->player.dir.x * data->player.move_speed)] == 9
		|| data->map.map[(int)(data->player.pos.y - data->player.dir.y
		* data->player.move_speed)][(int)(data->player.pos.x)] == 9)
	{
		data->player.life -= data->player.damage * 10;
		system("afplay ./Musics/oof.mp3 &");
	}
}

void	interact_right(t_data *data)
{
	if (data->map.map[(int)data->player.pos.y][(int)(data->player.pos.x
		+ data->player.plane.x * data->player.move_speed)] == 7
		|| data->map.map[(int)(data->player.pos.y + data->player.plane.y
		* data->player.move_speed)][(int)data->player.pos.x] == 7)
	{
		data->player.life -= data->player.damage;
		system("afplay ./Musics/oof.mp3 &");
	}
	if (data->map.map[(int)data->player.pos.y][(int)(data->player.pos.x
		+ data->player.plane.x * data->player.move_speed)] == 8
		|| data->map.map[(int)(data->player.pos.y + data->player.plane.y
		* data->player.move_speed)][(int)data->player.pos.x] == 8)
	{
		data->player.life -= data->player.damage * 5;
		system("afplay ./Musics/oof.mp3 &");
	}
	if (data->map.map[(int)data->player.pos.y][(int)(data->player.pos.x
		+ data->player.plane.x * data->player.move_speed)] == 9
		|| data->map.map[(int)(data->player.pos.y + data->player.plane.y
		* data->player.move_speed)][(int)data->player.pos.x] == 9)
	{
		data->player.life -= data->player.damage * 10;
		system("afplay ./Musics/oof.mp3 &");
	}
}

void	interact_left(t_data *data)
{
	if (data->map.map[(int)data->player.pos.y][(int)(data->player.pos.x
		- data->player.plane.x * data->player.move_speed)] == 7
		|| data->map.map[(int)(data->player.pos.y - data->player.plane.y
		* data->player.move_speed)][(int)data->player.pos.x] == 7)
	{
		data->player.life -= data->player.damage;
		system("afplay ./Musics/oof.mp3 &");
	}
	if (data->map.map[(int)data->player.pos.y][(int)(data->player.pos.x
		- data->player.plane.x * data->player.move_speed)] == 8
		|| data->map.map[(int)(data->player.pos.y - data->player.plane.y
		* data->player.move_speed)][(int)data->player.pos.x] == 8)
	{
		data->player.life -= data->player.damage * 5;
		system("afplay ./Musics/oof.mp3 &");
	}
	if (data->map.map[(int)data->player.pos.y][(int)(data->player.pos.x
		- data->player.plane.x * data->player.move_speed)] == 9
		|| data->map.map[(int)(data->player.pos.y - data->player.plane.y
		* data->player.move_speed)][(int)data->player.pos.x] == 9)
	{
		data->player.life -= data->player.damage * 10;
		system("afplay ./Musics/oof.mp3 &");
	}
}
