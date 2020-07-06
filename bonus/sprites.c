/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:51:24 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:51:26 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void	compute_distances(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_sprites)
	{
		data->spr[i].distance =
			pow(data->player.pos.x - data->spr[i].pos.x, 2)
			+ pow(data->player.pos.y - data->spr[i].pos.y, 2);
		i++;
	}
}

void	sort_sprites(t_data *data)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < data->nb_sprites)
	{
		j = 0;
		while (j < data->nb_sprites - i - 1)
		{
			if (data->spr[i].distance < data->spr[i + 1].distance)
			{
				tmp = data->spr[i];
				data->spr[i] = data->spr[i + 1];
				data->spr[i + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprite(t_data *data, int index, t_coord transform)
{
	int		i;

	data->spr[index].start_x = data->spr[index].sprite_x
	- data->spr[index].size / 2;
	data->spr[index].end_x = data->spr[index].sprite_x
	+ data->spr[index].size / 2;
	i = (data->spr[index].start_x < 0) ? 0 : data->spr[index].start_x;
	while (i <= (data->spr[index].end_x >= data->win.width ?
	data->win.width - 1 : data->spr[index].end_x))
	{
		if (transform.y > 0 && i > 0
			&& transform.y < data->depth_buffer[i])
			draw_line_sprite(data, index, i);
		i++;
	}
}

void	set_sprites_data(t_data *data)
{
	t_coord			sprite_pos;
	double			det;
	int				index;
	t_coord			transform;

	index = 0;
	while (index < data->nb_sprites)
	{
		if (data->spr[index].is_alive)
		{
			sprite_pos.x = data->spr[index].pos.x + 0.5 - data->player.pos.x;
			sprite_pos.y = data->spr[index].pos.y + 0.5 - data->player.pos.y;
			det = 1.0 / (data->player.plane.x * data->player.dir.y
				- data->player.dir.x * data->player.plane.y);
			transform.x = det * (data->player.dir.y * sprite_pos.x
				- data->player.dir.x * sprite_pos.y);
			transform.y = det * (-data->player.plane.y * sprite_pos.x
				+ data->player.plane.x * sprite_pos.y);
			data->spr[index].sprite_x = (int)((data->win.width / 2) *
				(1 + transform.x / transform.y));
			data->spr[index].size = abs((int)(data->win.height / transform.y));
			draw_sprite(data, index, transform);
		}
		index++;
	}
}

void	draw_sprites(t_data *data)
{
	compute_distances(data);
	sort_sprites(data);
	set_sprites_data(data);
}
