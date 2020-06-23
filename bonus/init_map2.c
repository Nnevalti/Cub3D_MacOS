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

void	check_border(t_data *data)
{
	int i;
	int j;

	i = data->map.height - 1;
	j = 0;
	while (j < data->map.width)
	{
		if (data->map.map[0][j] == 0)
			error_msg(data, "Map is invalid", false);
		else if (data->map.map[i][j] == 0)
			error_msg(data, "Map is invalid", false);
		j++;
	}
	i = 0;
	j = data->map.width - 1;
	while (i < data->map.height)
	{
		if (data->map.map[i][0] == 0)
			error_msg(data, "Map is invalid", false);
		else if (data->map.map[i][j] == 0)
			error_msg(data, "Map is invalid", false);
		i++;
	}
}

void	check_cell(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.map[i][j] == 0)
			{
				if (i > 0 && data->map.map[i - 1][j] == -1)
					error_msg(data, "Map is invalid", true);
				if (j > 0 && data->map.map[i][j - 1] == -1)
					error_msg(data, "Map is invalid", true);
				if (i < data->map.height - 1 && data->map.map[i + 1][j] == -1)
					error_msg(data, "Map is invalid", true);
				if (j < data->map.width - 1 && data->map.map[i][j + 1] == -1)
					error_msg(data, "Map is invalid", true);
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_data *data)
{
	check_border(data);
	check_cell(data);
}
