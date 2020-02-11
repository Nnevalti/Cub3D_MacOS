#include "../include/Cub3D.h"

int			is_path(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char		*find_path(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (is_path(line[i], "./-_") || ft_isalnum(line[i]))
			return (&line[i]);
		i++;
	}
	return (NULL);
}

void		init_tex(t_data *data, t_tex *tex, char *path)
{
	int i;

	i = 0;
	while (path[i])
	{
		if (path[i] == 32 || (path[i] >= 9 && path[i] <= 13))
		{
			path[i] = '\0';
			break;
		}
		i++;
	}
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
	tex->load = true;
}


void		init_color(t_data *data, char *line, t_color *color)
{
	int		i;

	i = 0;
	// check_rgb(data, line);

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
	{
		exit_game(data);
	}

}
