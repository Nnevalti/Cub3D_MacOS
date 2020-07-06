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

t_color	get_sprite_rgb(t_data *data, int index, int i, int j)
{
	t_color		color;
	t_tex		tex;

	tex = data->spr[index].texture;
	color.r = tex.addr[(int)((i - data->spr[index].start_x) * 1.0 /
	(data->spr[index].end_x - data->spr[index].start_x) * tex.width)
	* (tex.bpp >> 3) + (int)((j - data->spr[index].start_y * 1.0)
	/ data->spr[index].size
	* tex.height) * tex.s_line + (tex.endian ? 0 : 2)];
	color.g = tex.addr[(int)((i - data->spr[index].start_x) * 1.0 /
	(data->spr[index].end_x - data->spr[index].start_x) * tex.width) *
	(tex.bpp >> 3) + (int)((j - data->spr[index].start_y * 1.0)
	/ data->spr[index].size *
	tex.height) * tex.s_line + 1];
	color.b = tex.addr[(int)((i - data->spr[index].start_x) * 1.0 /
	(data->spr[index].end_x - data->spr[index].start_x) * tex.width) *
	(tex.bpp >> 3) + (int)((j - data->spr[index].start_y * 1.0)
	/ data->spr[index].size *
	tex.height) * tex.s_line + (tex.endian ? 2 : 0)];
	return (color);
}

void	draw_line_sprite(t_data *data, int index, int i)
{
	int		j;
	t_color	color;

	data->spr[index].start_y = data->win.height / 2 - data->spr[index].size / 2;
	data->spr[index].end_y = data->win.height / 2 + data->spr[index].size / 2;
	j = (data->spr[index].start_y < 0) ? 0 : data->spr[index].start_y;
	while (j < (data->spr[index].end_y >= data->win.height
		? data->win.height - 1 : data->spr[index].end_y))
	{
		color = get_sprite_rgb(data, index, i, j);
		if (color.r != 0 || color.g != 0 || color.b != 0)
			draw_rgb(data, &color, j, i);
		j++;
	}
}
