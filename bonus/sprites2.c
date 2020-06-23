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
