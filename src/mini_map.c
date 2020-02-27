#include "../include/Cub3D.h"

void	draw_square(t_data *data, int x, int y, int size, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
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

void	draw_minimap(t_data *data, int size)
{
	int		i;
	int		j;
	int		offset;

	offset = 20;
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (i == (int)data->player.pos.y && j == (int)data->player.pos.x)
				draw_square(data, j * size + offset, i * size + offset,
					size, 0xCC0000);
			else if (data->map.map[i][j] == 0)
				draw_square(data, j * size + offset, i * size + offset,
					size, 0xCCCCCC);
			else if (data->map.map[i][j] == 1)
				draw_square(data, j * size + offset, i * size + offset,
					size, 0x000000);
			else if (data->map.map[i][j] == 2)
				draw_square(data, j * size + offset, i * size + offset,
					size, 0x009933);
			j++;
		}
		i++;
	}
}
