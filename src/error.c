#include "../include/Cub3D.h"

void		init_error(t_data *data)
{
	data->error.file = false;
	data->error.win = false;
	data->error.mlx = false;
	data->error.tex = false;
	data->error.rgb = false;
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

// void	check_textures(t_data *data)
// {
// 	if (!(data->north.path) || !(data->south.path) || !(data->east.path) || !(data->west.path) || !(data->sprite.path))
// 	{
// 		data->error.tex = true;
// 		exit_game(data);
// 	}
// 	if (!(data->floor.r) || !(data->floor.g) || !(data->floor.b)
// 		|| !(data->ceilling.r) || !(data->ceilling.g) || !(data->ceilling.b))
// 	{
// 		data->error.rgb = true;
// 		exit_game(data);
// 	}
// 	return ;
// }
