#include "../include/Cub3D.h"

void		init_error(t_data *data)
{
	data->error.file = false;
	data->error.win = false;
	data->error.mlx = false;
	data->error.tex = false;
	data->error.rgb = false;

	data->win.load = false;
	data->north.load = false;
	data->south.load = false;
	data->east.load = false;
	data->west.load = false;
	data->sprite.load = false;
}

void	check_error(t_data *data)
{
	if (data->error.file == true)
	{
		ft_putstr_fd("Error\nDescription file argument missing or file doesn't exist\n", 1);
		exit(0);
	}
	if (data->error.win == true)
	{
		ft_putstr_fd("Error\nWindows resolution is missing or wrong (must be over 100x100)\n", 1);
		exit(0);
	}
	if (data->error.mlx == true)
	{
		ft_putstr_fd("Error\nAnd it seem like it's MLX fault...\n", 1);

	}
	if (data->error.tex == true)
		ft_putstr_fd("Error\nOne or multiple textures path missing or wrong\n", 1);
	// if (data->error.rgb == true)
	// 	ft_putstr_fd("Error\nOne or multiple rgb value for floor or ceilling missing or wrong (must be between 0 - 255)\n", 1);
	return ;
}

void	check_init(t_data *data)
{
	if (data->win.load == false)
	{
		data->error.win = true;
		exit_game(data);
	}
	else if (data->north.load == false ||
	data->south.load == false ||
	data->east.load == false ||
	data->west.load == false ||
	data->sprite.load == false)
	{
		data->error.tex = true;
		exit_game(data);
	}
}
