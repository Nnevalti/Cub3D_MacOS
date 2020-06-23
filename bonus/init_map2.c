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

void	malloc_map(t_data *data)
{
	int		h;

	h = 0;
	if (!(data->map.map = (int **)malloc(data->map.height * sizeof(int *))))
		exit_game(data);
	while (h < data->map.height)
		if (!(data->map.map[h++] = malloc(data->map.width * sizeof(int))))
			exit_game(data);
}

int		row_check(t_data *data, char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (str[i++] != '1')
			return (true);
	return (false);
}

int		column_check(t_data *data, char **map, int i, int j)
{
	int		min;

	min = ft_strlen(map[i - 1]) < ft_strlen(map[i + 1])
		? ft_strlen(map[i - 1]) : ft_strlen(map[i + 1]);
	if ((j == 0 || (j >= min && j < ft_strlen(map[i]))) &&
		map[i][j] != '1')
		return (false);
	return (true);
}

void	check_map(t_data *data, char **map)
{
	int		i;
	int		j;

	if (row_check(data, map[0])
		|| row_check(data, map[data->map.height - 1]))
		error_msg(data, "Map is invalid", true);
	i = 1;
	while (i < data->map.height - 1)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (!(column_check(data, map, i, j)))
				error_msg(data, "Map is invalid", true);
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map[0]);
	free(map[i]);
	free(map);
}
