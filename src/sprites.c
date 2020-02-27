#include "../include/Cub3D.h"

void	compute_distances(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_sprites)
	{
		data->sprites[i].distance =
			pow(data->pos[0] - data->sprites[i].pos[0], 2)
			+ pow(data->pos[1] - data->sprites[i].pos[1], 2);
		i++;
	}
}

void	sort_sprites(t_data *data)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < data->nb_sprites)
	{
		j = 0;
		while (j < data->nb_sprites - i - 1)
		{
			if (data->sprites[i].distance < data->sprites[i + 1].distance)
			{
				tmp = data->sprites[i];
				data->sprites[i] = data->sprites[i + 1];
				data->sprites[i + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	draw_line_sprite(t_data *data, t_spritedata data, int i,
	int bbox_x[2])
{
	int		bbox_y[2];
	int		j;
	int		color;

	bbox_y[0] = data->scr_height / 2 - data.sprite_size / 2;
	bbox_y[1] = data->scr_height / 2 + data.sprite_size / 2;
	j = (bbox_y[0] < 0) ? 0 : bbox_y[0];
	while (j < (bbox_y[1] >= data->scr_height
		? data->scr_height - 1 : bbox_y[1]))
	{
		color = get_tex_color(data->sprites[data.index].texture,
			((i - bbox_x[0]) * 1.0) / (bbox_x[1] - bbox_x[0]),
			((j - bbox_y[0]) * 1.0) / (bbox_y[1] - bbox_y[0]));
		if (color != 0)
			set_screen_pixel(data->screen, i, j, color);
		j++;
	}
}

void	draw_sprite(t_data *data, t_spritedata data)
{
	int		bbox_x[2];
	int		i;

	bbox_x[0] = data.sprite_x - data.sprite_size / 2;
	bbox_x[1] = data.sprite_x + data.sprite_size / 2;
	i = (bbox_x[0] < 0) ? 0 : bbox_x[0];
	while (i <= (bbox_x[1] >= data->scr_width ?
		data->scr_width - 1 : bbox_x[1]))
	{
		if (data.transform[1] > 0 && i > 0
			&& data.transform[1] < data->depth_buffer[i])
			draw_line_sprite(data, data, i, bbox_x);
		i++;
	}
}

void	draw_sprites(t_data *data)
{
	t_spritedata	data;
	double			sprite_pos[2];
	double			det;

	compute_distances(data);
	sort_sprites(data);
	data.index = 0;
	while (data.index < data->nb_sprites)
	{
		sprite_pos[0] = data->sprites[data.index].pos[0] + 0.5 - data->pos[0];
		sprite_pos[1] = data->sprites[data.index].pos[1] + 0.5 - data->pos[1];
		det = 1.0 / (data->cam_plane[0] * data->dir[1]
			- data->dir[0] * data->cam_plane[1]);
		data.transform[0] = det * (data->dir[1] * sprite_pos[0]
			- data->dir[0] * sprite_pos[1]);
		data.transform[1] = det * (-data->cam_plane[1] * sprite_pos[0]
			+ data->cam_plane[0] * sprite_pos[1]);
		data.sprite_x = (int)((data->scr_width / 2) *
			(1 + data.transform[0] / data.transform[1]));
		data.sprite_size = abs((int)(data->scr_height / data.transform[1]));
		draw_sprite(data, data);
		data.index++;
	}
}
