#include "../include/Cub3D.h"

int		exit_game(t_data *data)
{
	check_error(data);
	if (data->win.load == true)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}
