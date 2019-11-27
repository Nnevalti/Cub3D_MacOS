#include "../include/Cub3D.h"

int		exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	// free(data->win);
	// free(data->player);
	// free(data->ray);
	exit (0);
}
