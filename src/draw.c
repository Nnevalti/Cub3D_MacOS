#include "../include/Cub3D.h"

void	draw_line(int x, int start, int end, int color, t_data *data)
{
	int		y;

	y = 0;
	while (y < start)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xbbeaf2);
		y++;
	}
	while (start <= end)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, start, color);
		start++;
	}
	y = end;
	while (y <= data->win.height - 1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x535151);
		y++;
	}
}
