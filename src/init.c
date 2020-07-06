/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:50:04 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:50:06 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void		init_load(t_data *data)
{
	data->win.load = false;
	data->north.load = false;
	data->south.load = false;
	data->east.load = false;
	data->west.load = false;
	data->sprite.load = false;
	data->floor.load = false;
	data->ceilling.load = false;
	data->player.load = false;
	data->map.load = false;
}

void		init_win(char *line, t_data *data)
{
	int		i;

	i = 0;
	data->win.width = ft_atoi(&(line[i]));
	data->win.width = (data->win.width > 2560) ? 2560 : data->win.width;
	while (ft_isspace(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		i++;
	data->win.height = ft_atoi(&(line[i]));
	data->win.height = (data->win.height > 1440) ? 1440 : data->win.height;
	while (ft_isdigit(line[i]) || ft_isspace(line[i]))
		i++;
	if (data->win.load == true || line[i] != '\0'
		|| data->win.width < 100 || data->win.height < 100)
		error_msg(data, "Windows resolution is invalid", true);
	if ((data->win_ptr = mlx_new_window(data->mlx_ptr,
		data->win.width, data->win.height, "Cub3D")))
	{
		data->win.load = true;
		data->depth_buffer = malloc(data->win.width * sizeof(double));
	}
}

void		init_display(t_data *data)
{
	if (!(data->display.img = mlx_new_image(data->mlx_ptr,
		data->win.width, data->win.height))
		|| !(data->display.addr = mlx_get_data_addr(data->display.img,
			&data->display.bpp, &data->display.s_line, &data->display.endian)))
		exit_game(data);
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
	if (line[0] == 'S' && line[1] == ' ')
		init_tex(data, &data->sprite, find_path(&line[2]));
	if (line[0] == 'F')
		init_color(data, &line[1], &data->floor);
	if (line[0] == 'C')
		init_color(data, &line[1], &data->ceilling);
	if (is_map(line))
	{
		check_init(data);
		init_map(data, line, fd);
		return (0);
	}
	return (1);
}

t_data		init_data(int ac, char **av)
{
	t_data		data;
	char		*line;
	int			fd;

	fd = 0;
	if (ac < 2)
		error_msg(&data, "Missing map file", false);
	else if (ft_strcmp((av[1] + ft_strlen(av[1]) - 4), ".cub"))
		error_msg(&data,
			"Incorrect map file : should have extension .cub", false);
	else if ((fd = open(av[1], O_RDONLY)) == -1)
		error_msg(&data, "File does not exist", false);
	init_load(&data);
	data.mlx_ptr = mlx_init();
	data.file_line = 0;
	while (get_next_line(fd, &line) == 1)
	{
		data.file_line++;
		if (line_parse(&data, line, fd))
			free(line);
	}
	free(line);
	check_init(&data);
	init_display(&data);
	return (data);
}
