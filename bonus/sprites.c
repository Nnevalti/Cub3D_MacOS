#include "../include/Cub3D.h"

void	compute_distances(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_sprites)
	{
		data->sprites[i].distance =
			pow(data->player.pos.x - data->sprites[i].pos.x, 2)
			+ pow(data->player.pos.y - data->sprites[i].pos.y, 2);
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

void	draw_line_sprite(t_data *data, int index, int i, int sprite_size, int start_x, int end_x)
{
	int		start_y;
	int		end_y;
	int		j;
	t_color	color;
	t_tex	tex;

	start_y = data->win.height / 2 - sprite_size / 2;
	end_y = data->win.height / 2 + sprite_size / 2;
	j = (start_y < 0) ? 0 : start_y;
	while (j < (end_y >= data->win.height
		? data->win.height - 1 : end_y))
	{
		tex = data->sprites[index].texture;
		color.r = tex.addr[(int)((i - start_x) * 1.0 / (end_x - start_x) * tex.width) * (tex.bpp >> 3)
				+ (int)((j - start_y * 1.0) / sprite_size
				* tex.height) * tex.s_line + (tex.endian ? 0 : 2)];
		color.g = tex.addr[(int)((i - start_x) * 1.0 / (end_x - start_x) * tex.width) * (tex.bpp >> 3)
				+ (int)((j - start_y * 1.0) / sprite_size
				* tex.height) * tex.s_line + 1];
		color.b = tex.addr[(int)((i - start_x) * 1.0 / (end_x - start_x) * tex.width) * (tex.bpp >> 3)
				+ (int)((j - start_y * 1.0) / sprite_size
				* tex.height) * tex.s_line + (tex.endian ? 2 : 0)];
		if (color.r != 0 || color.g != 0 || color.b != 0)
			draw_rgb(data, &color, j, i);
		j++;
	}
}

void	draw_sprite(t_data *data, int index, int sprite_x, int sprite_size, t_coord transform)
{
	int		start_x;
	int		end_x;
	int		i;

	start_x = sprite_x - sprite_size / 2;
	end_x = sprite_x + sprite_size / 2;
	i = (start_x < 0) ? 0 : start_x;
	while (i <= (end_x >= data->win.width ?
		data->win.width - 1 : end_x))
	{
		if (transform.y > 0 && i > 0
			&& transform.y < data->depth_buffer[i])
			draw_line_sprite(data, index, i, sprite_size, start_x, end_x);
		i++;
	}
}

void	draw_sprites(t_data *data)
{
	t_coord			sprite_pos;
	double			det;
	int				index;
	t_coord			transform;
	int				sprite_x;
	int				sprite_size;

	compute_distances(data);
	sort_sprites(data);
	index = 0;
	while (index < data->nb_sprites)
	{
		sprite_pos.x = data->sprites[index].pos.x + 0.5 - data->player.pos.x;
		sprite_pos.y = data->sprites[index].pos.y + 0.5 - data->player.pos.y;
		det = 1.0 / (data->player.plane.x * data->player.dir.y
			- data->player.dir.x * data->player.plane.y);
		transform.x = det * (data->player.dir.y * sprite_pos.x
			- data->player.dir.x * sprite_pos.y);
		transform.y = det * (-data->player.plane.y * sprite_pos.x
			+ data->player.plane.x * sprite_pos.y);
		sprite_x = (int)((data->win.width / 2) *
			(1 + transform.x / transform.y));
		sprite_size = abs((int)(data->win.height / transform.y));
		draw_sprite(data, index, sprite_x, sprite_size, transform);
		index++;
	}
}
