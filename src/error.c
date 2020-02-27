#include "../include/Cub3D.h"

void		init_error(t_data *data)
{
	data->error.file = false;
	data->error.win = false;
	data->error.mlx = false;
	data->error.tex = false;
	data->error.loadtex = false;
	data->error.rgb = false;
	data->error.loadrgb = false;
	data->error.map = false;
	data->error.player = false;
	data->error.loadplayer = false;
}

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

void	check_error(t_data *data)
{
	if (data->error.file == true)
		ft_putstr_fd("Error\nConfiguration file missing or doesn't exist\n", 1);
	else if (data->error.player == true)
		ft_putstr_fd("Error\nPlayer initialised twice\n", 1);
	else if (data->error.loadplayer == true)
		ft_putstr_fd("Error\nMissing player position in map\n", 1);
	else if (data->error.win == true)
		ft_putstr_fd("Error\nWindows resolution is missing or wrong.\n", 1);
	else if (data->error.mlx == true)
		ft_putstr_fd("Error\nAnd it seem like it's MLX fault...\n", 1);
	else if (data->error.tex == true)
	{
		ft_putstr_fd("Error\nTextures path wrong at line : ", 1);
		ft_putnbr_fd(data->file_line, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (data->error.loadtex == true)
		ft_putstr_fd("Error\nA texture path is missing\n", 1);
	else if (data->error.rgb == true)
	{
		ft_putstr_fd("Error\nColor is invalid on line : ", 1);
		ft_putnbr_fd(data->file_line, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (data->error.loadrgb == true)
		ft_putstr_fd("Error\nA color is missing\n", 1);
	else if (data->error.map == true)
	{
		ft_putstr_fd("Error\nMap is invalid at line : ", 1);
		ft_putnbr_fd(data->file_line, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	check_init(t_data *data)
{
 	if (data->win.load == false)
	{
		data->error.win = true;
		exit_game(data);
	}
	else if (data->north.load == false || data->south.load == false ||
	data->east.load == false || data->west.load == false ||
	data->sprite.load == false)
	{
		data->error.loadtex = true;
		exit_game(data);
	}
	else if (data->floor.load == false || data->ceilling.load == false)
	{
		data->error.loadrgb = true;
		exit_game(data);
	}
	else if (data->map.load == true && data->player.load == false)
	{
		data->error.loadplayer = true;
		exit_game(data);
	}
}
