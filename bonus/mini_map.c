/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:27:11 by vdescham          #+#    #+#             */
/*   Updated: 2020/06/23 16:27:15 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void	draw_square(t_data *data, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < MINIMAP_SIZE)
	{
		j = 0;
		while (j < MINIMAP_SIZE)
		{
			data->display.addr[(x + j) * (data->display.bpp >> 3)
			+ (y + i) * data->display.s_line] = color & 0xFF;
			data->display.addr[(x + j) * (data->display.bpp >> 3)
			+ (y + i) * data->display.s_line + 1] = (color >> 8) & 0xFF;
			data->display.addr[(x + j) * (data->display.bpp >> 3)
			+ (y + i) * data->display.s_line + 2] = (color >> 16) & 0xFF;
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			x = j * MINIMAP_SIZE + MINIMAP_OFFSET;
			y = i * MINIMAP_SIZE + MINIMAP_OFFSET;
			if (i == (int)data->player.pos.y && j == (int)data->player.pos.x)
				draw_square(data, x, y, 0xCC0000);
			else if (data->map.map[i][j] == 0)
				draw_square(data, x, y, 0xCCCCCC);
			else if (data->map.map[i][j] == 1)
				draw_square(data, x, y, 0x000000);
			else if (data->map.map[i][j] >= 2 && data->map.map[i][j] <= 9)
				draw_square(data, x, y, 0x009933);
			j++;
		}
		i++;
	}
}
