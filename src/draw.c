#include "../include/Cub3D.h"

void draw_wall(t_tex *display, t_tex *tex, t_ray *ray, int y, int x) {
	// (u, v) = (wall_x, (y - start) / line_height (0 < u,v < 1)
	display->addr[(x * display->bpp >> 3) + y * display->s_line] = tex->addr[(int)(ray->wall_x * tex->width) * (tex->bpp >> 3) + (int)((y - ray->wall_start * 1.0) / ray->line_height * tex->height) * tex->s_line];

	display->addr[(x * display->bpp >> 3) + 1 + y * display->s_line] = tex->addr[(int)(ray->wall_x * tex->width) * (tex->bpp >> 3) + 1 + (int)((y - ray->wall_start * 1.0) / ray->line_height * tex->height) * tex->s_line];

	display->addr[(x * display->bpp >> 3) + 2 + y * display->s_line] = tex->addr[(int)(ray->wall_x * tex->width) * (tex->bpp >> 3) + 2 + (int)((y - ray->wall_start * 1.0) / ray->line_height * tex->height) * tex->s_line];
	y++;
}

void draw_sky(t_tex *display, t_tex *tex, int y, int x) {
	display->addr[(x * display->bpp >> 3) + y * display->s_line] = tex->addr[(x % tex->width) * (display->bpp >> 3) + (y % tex->height) * tex->s_line];

	display->addr[(x * display->bpp >> 3) + 1 + y * display->s_line] = tex->addr[(x % tex->width) * (display->bpp >> 3) + (y % tex->height) * tex->s_line];

	display->addr[(x * display->bpp >> 3) + 2 + y * display->s_line] = tex->addr[(x % tex->width) * (display->bpp >> 3) + (y % tex->height) * tex->s_line];
}

void	draw_tex(int x, t_data *data)
{
	int		y;
	int		texy;
	double	step;

	y = 0;
	while (y < (data->ray.wall_start < 0 ? 0 : data->ray.wall_start))
	{
		draw_sky(&data->display, &data->sky, y, x);
		y++;
	}
	while (y < (data->ray.wall_end >= data->win.height ? data->win.height - 1 : data->ray.wall_end))
	{
		if (data->ray.side == N)
			draw_wall(&data->display, &data->north, &data->ray, y, x);
		else if (data->ray.side == S)
			draw_wall(&data->display, &data->south, &data->ray, y, x);
		else if (data->ray.side == E)
			draw_wall(&data->display, &data->east, &data->ray, y, x);
		else if (data->ray.side == O)
			draw_wall(&data->display, &data->west, &data->ray, y, x);

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
