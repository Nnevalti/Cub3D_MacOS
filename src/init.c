#include "../include/Cub3D.h"

int			g_map[24][24] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,2,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

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
	i++;
	while (ft_isdigit(line[i]))
		i++;
	data->win.height = ft_atoi(&(line[i]));
	init_mlx(data);
}

void		init_map(t_data *data, char *line, int fd)
{
	int		i;
	int		j;
	// char	*map;
	// int		width;
	// int		height;
	//
	// width = 0;
	// height = 1;
	// while (line[i])
	// {
	// 	if (ft_isdigit(line[i]) || line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'O')
	// 		width++;
	// 	i++;
	// }
	// map = ft_strdup(line);
	// free(line);
	// while (get_next_line(fd, &line) == 1)
	// {
	// 	// printf ("%s\n\n", map);
	// 	// // map = ft_strjoin(map, line);
	// 	// height++;
	// 	// free(line);
	// }

	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			data->map[i][j] = g_map[i][j];
			j++;
		}
		i++;
	}
}

void		init_player(t_data *data)
{
	data->player.pos.x = 22;
	data->player.pos.y = 12;
	data->player.dir.x = -1;
	data->player.dir.y = 0;
	data->player.plane.x = 0;
	data->player.plane.y = 0.66;
	data->player.move_speed = 0.2;
	data->player.rot_speed = 0.15;
}

void		init_tex(void *mlx_ptr, t_tex *tex, char *path)
{
	if (!(tex->img = mlx_xpm_file_to_image (mlx_ptr, path, &tex->width, &tex->height)))
		return ;
	if (!(tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->s_line, &tex->endian)))
	return ;
}

void		init_display(t_data *data)
{
	if (!(data->display.img = mlx_new_image(data->mlx_ptr, data->win.width, data->win.height)))
		return ;
	if (!(data->display.addr = mlx_get_data_addr(data->display.img, &data->display.bpp, &data->display.s_line, &data->display.endian)))
		return ;
}

void		init_color(char *line, t_color *color)
{
	int		i;

	i = 0;
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
	printf("r: %d, g: %d, b: %d\n", color->r, color->g, color->b);
}

t_data		init(char **av)
{
	t_data		data;
	int		fd;
	char	*line;

	if (!(av[1]) || (fd = open(av[1], O_RDONLY)) == -1)
		exit_game(&data);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'R')
			init_win(line, &data);
		if (line[0] == 'N' && line[1] == 'O')
			init_tex(data.mlx_ptr, &data.north, ft_strstr(line, "./"));
		if ((line[0] == 'S' && line[1] == 'O'))
			init_tex(data.mlx_ptr, &data.south, ft_strstr(line, "./"));
		if ((line[0] == 'W' && line[1] == 'E'))
			init_tex(data.mlx_ptr, &data.west, ft_strstr(line, "./"));
		if ((line[0] == 'E' && line[1] == 'A'))
			init_tex(data.mlx_ptr, &data.east, ft_strstr(line, "./"));
		if (line[0] == 'S')
			init_tex(data.mlx_ptr, &data.sprite, ft_strstr(line, "./"));
		if (line[0] == 'F')
			init_color(&line[2], &data.floor);
		if (line[0] == 'C')
			init_color(&line[2], &data.ceilling);
		// if (line[0] == '1')
		init_map(&data, line, fd);
		free(line);
	}
	init_tex(data.mlx_ptr, &data.sky, "textures/sky_1.xpm");
	init_player(&data);
	init_display(&data);
	return (data);
}
