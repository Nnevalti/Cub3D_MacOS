/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:51:11 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:51:12 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		error_msg(data, "Textures path is wrong", true);
	if (!(tex->addr = mlx_get_data_addr(tex->img,
		&tex->bpp, &tex->s_line, &tex->endian)))
		error_msg(data, "MLX don't work for tex", false);
	tex->load = true;
}

void		check_rgb(t_data *data, char *rgb)
{
	int		i;

	i = 0;
	while (rgb[i])
	{
		if (!is_charset(rgb[i], "0123456789,"))
			error_msg(data, "RGB values are wrong", true);
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
	color->b = ft_atoi(&(rgb[i]));
	while (ft_isdigit(rgb[i]))
		i++;
	if (color->b < 0 || color->b > 255 || color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255 || rgb[i] != '\0')
		error_msg(data, "RGB values are wrong", true);
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
