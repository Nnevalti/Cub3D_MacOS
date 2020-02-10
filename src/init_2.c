#include "../include/Cub3D.h"

void		init_tex(t_data *data, t_tex *tex, char *path)
{
	if (!(tex->img = mlx_xpm_file_to_image (data->mlx_ptr, path, &tex->width, &tex->height)))
	{
		data->error.tex = true;
		exit_game(data);
	}
	if (!(tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->s_line, &tex->endian)))
	{
		data->error.mlx = true;
		exit_game(data);
	}
}


void		init_color(t_data *data, char *line, t_color *color)
{
	int		i;

	i = 0;
	color->r = ft_atoi(&(line[i]));
	while (ft_isdigit(line[i]))
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	color->g = ft_atoi(&(line[i]));
	while (ft_isdigit(line[i]))
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	color->b = ft_atoi(&(line[i]));
	if (color->b < 0 || color->b > 255
		|| color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255)
		exit_game(data);
}
