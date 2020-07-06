/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:47:36 by vdescham          #+#    #+#             */
/*   Updated: 2020/07/02 16:47:38 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void	draw_horizontal(t_data *data, int color)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	x = (data->win.width / 2) - 10;
	y = (data->win.height / 2) - 2;
	while (++i < 2)
	{
		j = -1;
		while (++j < 20)
		{
			data->display.addr[(x + j) * (data->display.bpp >> 3) + (y + i)
				* data->display.s_line] = color & 0xFF;
			data->display.addr[(x + j) * (data->display.bpp >> 3) + (y + i)
				* data->display.s_line + 1] = (color >> 8) & 0xFF;
			data->display.addr[(x + j) * (data->display.bpp >> 3) + (y + i)
				* data->display.s_line + 2] = (color >> 16) & 0xFF;
		}
	}
}

void	draw_vertical(t_data *data, int color)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	x = (data->win.width / 2) - 2;
	y = (data->win.height / 2) - 10;
	while (++i < 20)
	{
		j = -1;
		while (++j < 2)
		{
			data->display.addr[(x + j) * (data->display.bpp >> 3) + (y + i)
				* data->display.s_line] = color & 0xFF;
			data->display.addr[(x + j) * (data->display.bpp >> 3) + (y + i)
				* data->display.s_line + 1] = (color >> 8) & 0xFF;
			data->display.addr[(x + j) * (data->display.bpp >> 3) + (y + i)
				* data->display.s_line + 2] = (color >> 16) & 0xFF;
		}
	}
}

void	draw_cursor(t_data *data)
{
	int	color;

	color = data->key.shoot == true ? 0xCCCCCC : 0x000000;
	draw_horizontal(data, color);
	draw_vertical(data, color);
}
