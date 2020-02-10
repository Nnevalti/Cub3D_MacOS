#include "../include/Cub3D.h"

void		init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.width, data->win.height, "Cub3D");
}


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
	data->win.height = (data->win.height > 1440) ? 1440 : data->win.height;
	if (data->win.width < 100 || data->win.height < 100)
	{
		data->error.win = true;
		exit_game(data);
	}
	init_mlx(data);
}
//
// void		init_display(t_data *data)
// {
// 	if (!(data->display.img = mlx_new_image(data->mlx_ptr, data->win.width, data->win.height)))
// 		exit_game(data);
// 	if (!(data->display.addr = mlx_get_data_addr(data->display.img, &data->display.bpp, &data->display.s_line, &data->display.endian)))
// 		exit_game(data);
// }
//
// void		init_map(t_data *data, char *line, int fd)
// {
// 	int		i;
// 	int		j;
// 	int		width;
// 	int		height;
// 	int		h;
// 	int		w;
// 	char	*map;
//
// 	i = 0;
// 	width = 0;
// 	height = 1;
// 	while (line[i])
// 	{
// 		if (line[i] == '0' || line[i] == '1' || line[i] == '2'|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'O')
// 		{
// 			width++;
// 			i++;
// 		}
// 		else if (line[i] == ' ')
// 			i++;
// 		else
// 			exit_game(data);
// 	}
// 	map = ft_strdup(line);
//
// 	while (get_next_line(fd, &line) == 1)
// 	{
// 		// map = ft_strjoin(map, "\n");
// 		map = ft_strjoin(map, line);
// 		height++;
// 		free(line);
// 	}
// 	data->mapsize.width = width;
// 	data->mapsize.height = height;
// 	data->map = malloc(height * sizeof(char *));
// 	data->*map = malloc(width * sizeof(char));
//
// 	i = 0;
// 	h = 0;
// 	while (map[i] && h < height)
// 	{
// 		w = 0;
// 		while (map[i] && w < width)
// 		{
// 			if (ft_isdigit(map[i]))
// 			{
// 				data->map[h][w] = ft_atoi(map[i]);
// 				w++;
// 			}
// 			else if (ft_isalpha(map[i]))
// 			{
// 				init_player(data, h, w, map[i]);
// 				w++;
// 			}
// 			i++;
// 		}
// 		h++;
// 	}
// }

void		init_player(t_data *data, int h, int w, char dir)
{
	data->player.pos.x = w;
	data->player.pos.y = h;
	if (dir == 'N')
	{
		data->player.dir.x = 0;
		data->player.dir.y = -1;
	}
	else if (dir == 'S')
	{
		data->player.dir.x = 0;
		data->player.dir.y = +1;
	}
	else if (dir == 'E')
	{
		data->player.dir.x = +1;
		data->player.dir.y = 0;
	}
	else if (dir == 'W')
	{
		data->player.dir.x = -1;
		data->player.dir.y = 0;
	}
	else
		exit_game(data);
	data->player.plane.x = 0;
	data->player.plane.y = 0.66;
	data->player.move_speed = 0.2;
	data->player.rot_speed = 0.15;
}

t_data		init_data(char **av, int fd)
{
	t_data		data;
	char		*line;

	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'R')
			init_win(line, &data);
		else if (line[0] == 'N' && line[1] == 'O')
			init_tex(&data, &data.north, ft_strstr(line, "./"));
		else if ((line[0] == 'S' && line[1] == 'O'))
			init_tex(&data, &data.south, ft_strstr(line, "./"));
		else if ((line[0] == 'W' && line[1] == 'E'))
			init_tex(&data, &data.west, ft_strstr(line, "./"));
		else if ((line[0] == 'E' && line[1] == 'A'))
			init_tex(&data, &data.east, ft_strstr(line, "./"));
		// else if (line[0] == 'S')
		// 	init_tex(&data, &data.sprite, ft_strstr(line, "./"));
		else if (line[0] == 'F')
			init_color(&data, &line[1], &data.floor);
		else if (line[0] == 'C')
			init_color(&data, &line[1], &data.ceilling);
		// else if (line[0] == '1')
		// 	init_map(&data, line, fd);
		free(line);
	}
	// init_display(&data);
	return (data);
}
