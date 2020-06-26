#include "../include/Cub3D.h"

void draw_lifebar(t_data *data)
{
	int 	size;
	int		width;
	int		i;
	int		j;
	int		x;
	int		y;
	int		color;

	width = data->win.width / 2;
	x = data->win.width / 4;
	y = data->win.height - 50;
	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < width)
		{
			if (j < data->player.life)
				color = 0x009933;
			else
				color = 0xCC0000;
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
