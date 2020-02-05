#include "../include/Cub3D.h"

int g_map[24][24] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	init_win (char *line, t_data *data)
{
	int		i;

	i = 1;
	data->win.width = ft_atoi(&(line[i]));
	i++;
	while (ft_isdigit(line[i]))
		i++;
	data->win.height = ft_atoi(&(line[i]));
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.width, data->win.height, "Cub3D");
}

void	init_map(t_data *data, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			data->map[i][j] = g_map[i][j];
			j++;
		}
		i++;
	}
}

void init_player(t_data *data)
{
	data->player.pos.x = 22;
	data->player.pos.y = 12;
	data->player.dir.x = -1;
	data->player.dir.y = 0;
	data->player.plane.x = 0;
	data->player.plane.y = 0.66;
	data->player.move_speed = 0.25;
	data->player.rot_speed = 0.2;
}

void init_tex(void *mlx_ptr, t_tex *tex, char *name)
{
	tex->img = mlx_xpm_file_to_image (mlx_ptr, name, &tex->width, &tex->height);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->s_line, &tex->endian);
}

void init_textures(t_data *data)
{
	init_tex(data->mlx_ptr, &data->north, "./textures/wall_1.xpm");
	init_tex(data->mlx_ptr, &data->south, "./textures/wall_2.xpm");
	init_tex(data->mlx_ptr, &data->east, "./textures/wall_3.xpm");
	init_tex(data->mlx_ptr, &data->west, "./textures/wall_4.xpm");
	init_tex(data->mlx_ptr, &data->sky, "./textures/sky_1.xpm");
	init_tex(data->mlx_ptr, &data->floor, "./textures/floor_1.xpm");
}

void init_display(t_data *data)
{
	data->display.img = mlx_new_image(data->mlx_ptr, data->win.width, data->win.height);
	data->display.addr = mlx_get_data_addr(data->display.img, &data->display.bpp, &data->display.s_line, &data->display.endian);
}

t_data		init(char **av)
{
	t_data		data;

	data.win.height = 540;
	data.win.width = 960;
	init_mlx(&data);
	init_map(&data, 24, 24);
	init_player(&data);
	init_display(&data);
	init_textures(&data);

	// int		i;
	// int		fd;
	// char	*line;
	//
	// fd = open(av[1], O_RDONLY);
	// while (get_next_line(fd, &line) == 1)
	// {
	// 	i = 0;
	// 	if (line[0] == 'R')
	// 		init_win(line, &data);
	// 	// if ((line[0] =='N' && line[1] == 'O'))
	// 	// if ((line[0] == 'S' && line[1] == 'O'))
	// 	// if ((line[0] == 'W' && line[1] == 'E'))
	// 	// if ((line[0] == 'E' && line[1] == 'A'))
	// 	// if (line[0] == 'S')
	// 	// if (line[0] == 'F')
	// 	// if (line[0] == 'C')
	// 	free(line);
	// }
	return (data);
}
