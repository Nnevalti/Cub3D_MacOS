#include "../include/Cub3D.h"

char		*find_path(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (is_charset(line[i], "./-_") || ft_isalnum(line[i]))
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
		if (ft_isspace(path[i]))
		{
			path[i] = '\0';
			break ;
		}
		i++;
	}
	if (!(tex->img = mlx_xpm_file_to_image(data->mlx_ptr,
		path, &tex->width, &tex->height)))
	{
		data->error.tex = true;
		exit_game(data);
	}
	if (!(tex->addr = mlx_get_data_addr(tex->img,
		&tex->bpp, &tex->s_line, &tex->endian)))
	{
		data->error.mlx = true;
		exit_game(data);
	}
	tex->load = true;
}

void		check_rgb(t_data *data, char *rgb)
{
	int		i;

	i = 0;
	while (rgb[i])
	{
		if (!is_charset(rgb[i], "0123456789,"))
		{
			data->error.rgb = true;
			exit_game(data);
		}
		i++;
	}
}

void		get_color(t_data *data, t_color *color, char *rgb)
{
	int		i;

	i = 0;
	color->r = ft_atoi(&(rgb[i]));
	while (ft_isdigit(rgb[i]))
		i++;
	if (rgb[i] == ',')
		i++;
	color->g = ft_atoi(&(rgb[i]));
	while (ft_isdigit(rgb[i]))
		i++;
	if (rgb[i] == ',')
		i++;
	while (ft_isdigit(rgb[i]))
		i++;
	color->b = ft_atoi(&(rgb[i]));
	if (color->b < 0 || color->b > 255 || color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255 || rgb[i] != '\0')
	{
		data->error.rgb = true;
		exit_game(data);
	}
	color->load = true;
}

void		init_color(t_data *data, char *line, t_color *color)
{
	int		i;
	char	*rgb;

	i = 0;
	rgb = ft_strdup_nospace(line);
	check_rgb(data, rgb);
	get_color(data, color, rgb);
	free(rgb);
}
