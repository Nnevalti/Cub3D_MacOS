/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:59:33 by vdescham          #+#    #+#             */
/*   Updated: 2020/06/30 15:59:35 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void		line_parse_bis(t_data *data, char *line)
{
	if (line[1] == '1')
		init_tex(data, &data->sprite, find_path(&line[2]));
	if (line[1] == '2')
		init_tex(data, &data->sprite2, find_path(&line[2]));
	if (line[1] == '3')
		init_tex(data, &data->sprite3, find_path(&line[2]));
	if (line[1] == '4')
		init_tex(data, &data->sprite4, find_path(&line[2]));
	if (line[1] == '5')
		init_tex(data, &data->sprite5, find_path(&line[2]));
	if (line[1] == '6')
		init_tex(data, &data->sprite6, find_path(&line[2]));
	if (line[1] == '7')
		init_tex(data, &data->sprite7, find_path(&line[2]));
	if (line[1] == '8')
		init_tex(data, &data->sprite8, find_path(&line[2]));
}

int			line_parse(t_data *data, char *line, int fd)
{
	if (line[0] == 'R')
		init_win(&line[1], data);
	if (line[0] == 'N' && line[1] == 'O')
		init_tex(data, &data->north, find_path(&line[3]));
	if ((line[0] == 'S' && line[1] == 'O'))
		init_tex(data, &data->south, find_path(&line[3]));
	if ((line[0] == 'W' && line[1] == 'E'))
		init_tex(data, &data->west, find_path(&line[3]));
	if ((line[0] == 'E' && line[1] == 'A'))
		init_tex(data, &data->east, find_path(&line[3]));
	if (line[0] == 'S')
		line_parse_bis(data, line);
	if (line[0] == 'F')
		init_color(data, &line[1], &data->floor);
	if (line[0] == 'C')
		init_tex(data, &data->sky, find_path(&line[2]));
	if (is_map(line))
	{
		check_init(data);
		init_map(data, line, fd);
		return (0);
	}
	return (1);
}
