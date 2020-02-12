#include "../include/Cub3D.h"

void		init_error(t_data *data)
{
	data->error.file = false;
	data->error.win = false;
	data->error.mlx = false;
	data->error.tex = false;
	data->error.rgb = false;
	data->error.map = false;

	data->win.load = false;
	data->north.load = false;
	data->south.load = false;
	data->east.load = false;
	data->west.load = false;
	data->sprite.load = false;
	data->floor.load = false;
	data->ceilling.load = false;
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
		ft_putstr_fd("Error\nWindows resolution is missing or wrong, on line : ", 1);
		ft_putnbr_fd(data->file_line, 1);
		ft_putstr_fd("\n", 1);
		exit(0);
	}
	if (data->error.mlx == true)
		ft_putstr_fd("Error\nAnd it seem like it's MLX fault...\n", 1);
	if (data->error.tex == true)
	{
		ft_putstr_fd("Error\nOne or multiple textures path missing or wrong\n", 1);
	}
	if (data->error.rgb == true)
	{
		ft_putstr_fd("Error\nColor is invalid on line : ", 1);
		ft_putnbr_fd(data->file_line, 1);
		ft_putstr_fd("\n", 1);
	}
	if (data->error.map == true)
	{
		ft_putstr_fd("Error\nMap is invalid (must be at the end of file and surround by wall)\n", 1);
	}
	return ;
}

void	check_rgb(t_data *data, char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (ft_isspace(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	else
	{
		data->error.rgb = true;
		exit_game(data);
	}
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	else
	{
		data->error.rgb = true;
		exit_game(data);
	}
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] != '\0')
	{
		data->error.rgb = true;
		exit_game(data);
	}

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
	data->sprite.load == false ||
	data->win.load == false ||
	data->floor.load == false ||
	data->ceilling.load == false)
	{
		data->error.tex = true;
		exit_game(data);
	}
}
