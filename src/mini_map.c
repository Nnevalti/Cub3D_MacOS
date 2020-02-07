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
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_data *data, int width, int height)
{
	int		i;
	int		j;
	int		size;

	size = 3;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i == (int)data->player.pos.x && j == (int)data->player.pos.y)
				draw_square(data, j * size + 20, i * size + 20, size, 0x66CC0000);
			else if (data->map[i][j] == 0)
				draw_square(data, j * size + 20, i * size + 20, size, 0xAACCCCCC);
			else if (data->map[i][j] == 1)
				draw_square(data, j * size + 20, i * size + 20, size, 0x66000000);
			else if (data->map[i][j] == 2)
				draw_square(data, j * size + 20, i * size + 20, size, 0xAA009933);
			j++;
		}
		i++;
	}
}
