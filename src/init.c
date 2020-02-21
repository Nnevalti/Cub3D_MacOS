#include "../include/Cub3D.h"

void		init_win (char *line, t_data *data)
{
	int		i;

	i = 1;
	data->win.width = ft_atoi(&(line[i]));
	data->win.width = (data->win.width > 2560) ? 2560 : data->win.width;
	i++;
	while (ft_isdigit(line[i]))
		i++;
	data->win.height = ft_atoi(&(line[i]));
	while (ft_isdigit(line[i]) || ft_isspace(line[i]))
		i++;
	if (line[i] != '\0')
	{
		data->error.win = true;
		exit_game(data);
	}

	data->win.height = (data->win.height > 1440) ? 1440 : data->win.height;
	if (data->win.width < 100 || data->win.height < 100)
	{
		data->error.win = true;
		exit_game(data);
	}

	if ((data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.width, data->win.height, "Cub3D")))
		data->win.load = true;
}

void		init_player(t_data *data, int h, int w, char dir)
{
	data->player.pos.x = w;
	data->player.pos.y = h;
	if (dir == 'N')
	{
		data->player.dir.x = -1;
		data->player.dir.y = 0;
		data->player.plane.x = 0;
		data->player.plane.y = 0.66;
	}
	else if (dir == 'S')
	{
		data->player.dir.x = 1;
		data->player.dir.y = 0;
		data->player.plane.x = 0;
		data->player.plane.y = -0.66;
	}
	else if (dir == 'E')
	{
		data->player.dir.x = 0;
		data->player.dir.y = 1;
		data->player.plane.x = 0.66;
		data->player.plane.y = 0;
	}
	else if (dir == 'O')
	{
		data->player.dir.x = 0;
		data->player.dir.y = -1;
		data->player.plane.x = -0.66;
		data->player.plane.y = 0;
	}
	else
		exit_game(data);

	data->player.move_speed = 0.2;
	data->player.rot_speed = 0.15;
}

void		init_display(t_data *data)
{
	if (!(data->display.img = mlx_new_image(data->mlx_ptr, data->win.width, data->win.height)))
		exit_game(data);
	if (!(data->display.addr = mlx_get_data_addr(data->display.img, &data->display.bpp, &data->display.s_line, &data->display.endian)))
		exit_game(data);
}

int			line_parse(t_data *data, char *line, int fd)
{
	if (line[0] == 'R')
		init_win(line, data);
	if (line[0] == 'N' && line[1] == 'O')
		init_tex(data, &data->north, find_path(&line[3]));
	if ((line[0] == 'S' && line[1] == 'O'))
		init_tex(data, &data->south, find_path(&line[3]));
	if ((line[0] == 'W' && line[1] == 'E'))
		init_tex(data, &data->west, find_path(&line[3]));
	if ((line[0] == 'E' && line[1] == 'A'))
		init_tex(data, &data->east, find_path(&line[3]));
	if (line[0] == 'S')
		init_tex(data, &data->sprite, find_path(&line[2]));
	if (line[0] == 'F')
		init_color(data, &line[1], &data->floor);
	if (line[0] == 'C')
		init_color(data, &line[1], &data->ceilling);
	if (line[0] == '1')
	{
		init_map(data, line, fd);
		return (0);
	}
	return (1);
}
t_data		init_data(char **av, int fd)
{
	t_data		data;
	char		*line;

	data.file_line = 0;
	data.mlx_ptr = mlx_init();
	while (get_next_line(fd, &line) == 1)
	{
		data.file_line++;
		if (line_parse(&data, line, fd))
			free(line);
	}
	// system("leaks Cub3D");
	check_init(&data);
	init_display(&data);
	return (data);
}
