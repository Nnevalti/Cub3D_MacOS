/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:50:13 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:50:14 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

int		ft_toomuchlines(t_data *data, int h, int w, char cell)
{
	if (is_charset(cell, "012"))
	{
		data->map.map[h][w] = cell - '0';
		if (cell == '2')
			data->nb_sprites++;
		return (1);
	}
	else if (is_charset(cell, "NSEW"))
	{
		init_player(data, h, w, cell);
		data->map.map[h][w] = 0;
		return (1);
	}
	else if (is_charset(cell, "\n\0"))
		data->map.map[h][w] = -1;
	else
		error_msg(data, "Map is invalid", true);
	return (0);
}

void	fill_map(t_data *data, char *map)
{
	int		i;
	int		h;
	int		w;

	i = 0;
	h = 0;
	data->nb_sprites = 0;
	while (h < data->map.height)
	{
		w = 0;
		while (w < data->map.width)
		{
			i += ft_toomuchlines(data, h, w, map[i]);
			w++;
		}
		if (map[i] != '\0')
			i++;
		h++;
	}
}

char	*create_map(t_data *data, int fd, char *line)
{
	char	*map;
	char	*tmp;
	char	*tmp2;

	map = ft_strdup_nospace(line);
	free(line);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strjoin(map, "\n");
		tmp2 = ft_strdup_nospace(line);
		if (tmp2[0] == '\0')
			error_msg(data, "Empty line in map", false);
		data->map.width = ft_strlen(tmp2) > data->map.width
			? ft_strlen(tmp2) : data->map.width;
		free(map);
		map = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		free(line);
		data->map.height++;
	}
	free(line);
	return (map);
}

void	init_map(t_data *data, char *line, int fd)
{
	char	*map;

	data->map.height = 1;
	data->map.width = 0;
	check_init(data);
	map = create_map(data, fd, line);
	malloc_map(data);
	fill_map(data, map);
	init_sprites(data);
	check_map(data, ft_split(map, '\n'));
	data->map.load = true;
	free(map);
}
