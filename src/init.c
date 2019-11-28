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

void	init_map(t_data *data)
{
	int		i;
	int		j;

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

void init_tex(t_data *data)
{
	data->north.img_ptr = mlx_xpm_file_to_image (data->mlx_ptr, "../textures/bluestone.xpm", &data->win.width, &data->win.height);
	// data->tex.N.img_ptr = mlx_new_image(data->mlx_ptr, data->win.width, data->win.height);
	// data->tex.N.addr = mlx_get_data_addr(data->tex.N.img_ptr, data->tex.N.bits_per_pixel, data->tex.N.size_line, data->tex.N.endian);
}

t_data		init(char **av)
{
	t_data		data;
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
	data.win.height = 384;
	data.win.width = 512;
	init_mlx(&data);
	init_map(&data);
	init_player(&data);
	// init_tex(data);
	return (data);
}
