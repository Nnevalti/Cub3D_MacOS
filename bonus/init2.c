/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:51:02 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:51:04 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void	set_dir(t_data *data, int x, int y)
{
	data->player.dir.x = x;
	data->player.dir.y = y;
}

void	set_plane(t_data *data, double x, double y)
{
	data->player.plane.x = x;
	data->player.plane.y = y;
}

void	init_player(t_data *data, int h, int w, char dir)
{
	if (data->player.load == true)
		error_msg(data, "Player initialised twice", false);
	if (dir == 'N' || dir == 'S')
	{
		set_dir(data, 0, dir == 'N' ? -1 : 1);
		set_plane(data, dir == 'N' ? 0.66 : -0.66, 0);
	}
	else if (dir == 'E')
	{
		set_dir(data, 1, 0);
		set_plane(data, 0, 0.66);
	}
	else if (dir == 'W')
	{
		set_dir(data, -1, 0);
		set_plane(data, 0, -0.66);
	}
	data->player.pos.x = w;
	data->player.pos.y = h;
	data->player.move_speed = 0.05;
	data->player.rot_speed = 0.05;
	data->player.load = true;
	data->player.lifebar_size = data->win.width / 2;
	data->player.life = 100;
	data->player.has_key = false;
}

t_tex	set_tex(t_data *data, int cell)
{
	if (data->sprite2.load && cell == 3)
		return (data->sprite2);
	else if (data->sprite3.load && cell == 4)
		return (data->sprite3);
	else if (data->sprite4.load && cell == 5)
		return (data->sprite4);
	else if (data->sprite5.load && cell == 6)
		return (data->sprite5);
	else if (data->sprite6.load && cell == 7)
		return (data->sprite6);
	else if (data->sprite7.load && cell == 8)
		return (data->sprite7);
	else if (data->sprite8.load && cell == 9)
		return (data->sprite8);
	else
		return (data->sprite);
	exit_game(data);
}

void	init_sprites(t_data *data)
{
	int		i;
	int		j;
	int		index;

	if (!(data->spr = malloc(data->nb_sprites * sizeof(t_sprite))))
		exit_game(data);
	index = 0;
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.map[i][j] >= 2 && data->map.map[i][j] <= 9)
			{
				data->spr[index].texture = set_tex(data, data->map.map[i][j]);
				data->spr[index].pos.y = i;
				data->spr[index].pos.x = j;
				data->spr[index].is_alive = true;
				index++;
			}
			j++;
		}
		i++;
	}
}
