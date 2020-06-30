/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifebar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:14:50 by vdescham          #+#    #+#             */
/*   Updated: 2020/06/30 16:14:52 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void	draw_lifebar(t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		color;

	i = 0;
	x = data->player.lifebar_size;
	y = data->win.height - 50;
	while (i < 20)
	{
		j = 0;
		while (j < data->win.width / 2)
		{
			color = j < data->player.life ? 0x009933 : 0xCC0000;
			data->display.addr[(x + j) * (data->display.bpp >> 3) + (y + i)
				* data->display.s_line] = color & 0xFF;
			data->display.addr[(x + j) * (data->display.bpp >> 3) + (y + i)
				* data->display.s_line + 1] = (color >> 8) & 0xFF;
			data->display.addr[(x + j) * (data->display.bpp >> 3) + (y + i)
				* data->display.s_line + 2] = (color >> 16) & 0xFF;
			j++;
		}
		i++;
	}
}
