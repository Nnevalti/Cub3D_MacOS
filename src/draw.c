#include "../include/Cub3D.h"

void	draw_tex(int x, int start, int end, t_data *data)
{
	int		y;
	int		texy;
	double	step;

	y = 0;
	while (y < (start < 0 ? 0 : start))
	{
		data->display.addr[(x * data->display.bpp >> 3) + y * data->display.s_line] = 0xFF;
		data->display.addr[(x * data->display.bpp >> 3) + 1 + y * data->display.s_line] = 0x99;
		data->display.addr[(x * data->display.bpp >> 3) + 2 + y * data->display.s_line] = 0x00;
		y++;
	}
	while (y < (end >= data->win.height ? data->win.height - 1 : end))
	{
		// (u, v) = (wall_x, (y - start) / line_height (0 < u,v < 1)
		data->display.addr[(x * data->display.bpp >> 3) + y * data->display.s_line] = data->north.addr[(int)(data->ray.wall_x * data->north.width) * (data->north.bpp >> 3) + (int)((y - start * 1.0) / data->ray.line_height * data->north.height) * data->north.s_line];

		data->display.addr[(x * data->display.bpp >> 3) + 1 + y * data->display.s_line] = data->north.addr[(int)(data->ray.wall_x * data->north.width) * (data->north.bpp >> 3) + 1 + (int)((y - start * 1.0) / data->ray.line_height * data->north.height) * data->north.s_line];

		data->display.addr[(x * data->display.bpp >> 3) + 2 + y * data->display.s_line] = data->north.addr[(int)(data->ray.wall_x * data->north.width) * (data->north.bpp >> 3) + 2 + (int)((y - start * 1.0) / data->ray.line_height * data->north.height) * data->north.s_line];
		y++;
	}
	while (y < data->win.height)
	{
		data->display.addr[(x * data->display.bpp >> 3) + y * data->display.s_line] = 0x33;
		data->display.addr[(x * data->display.bpp >> 3) + 1 + y * data->display.s_line] = 0x33;
		data->display.addr[(x * data->display.bpp >> 3) + 2 + y * data->display.s_line] = 0x66;
		y++;
	}
}
