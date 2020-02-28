#include "../include/Cub3D.h"

void		init_load(t_data *data)
{
	data->bmp_index = 0;
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

void		error_msg(t_data *data, char *msg, t_bool aff_line)
{
	int		i;

	i = 0;
	write(1, "Error\n", 6);
	while (msg[i])
		write(1, &msg[i++], 1);
	if (data->file_line > 0 && aff_line == true)
	{
		write(1, " at line : ", 11);
		ft_putnbr_fd(data->file_line, 1);
	}
	write(1, "\n", 1);
	exit_game(data);
}

void	check_init(t_data *data)
{
 	if (data->win.load == false)
		error_msg(data, "Windows resolution is missing", false);
	else if (data->north.load == false || data->south.load == false ||
	data->east.load == false || data->west.load == false ||
	data->sprite.load == false)
		error_msg(data, "Missing texture path", false);
	else if (data->floor.load == false || data->ceilling.load == false)
		error_msg(data, "Missing RGB value", false);
	else if (data->map.load == true && data->player.load == false)
		error_msg(data, "Player position missing in Map", false);
}
