#include "../include/header.h"

int		exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	//free(data);
	exit (0);
}
