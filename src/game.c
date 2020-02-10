#include "../include/Cub3D.h"

int		game(t_data *data)
{
	if (move_player(data))
		raycast(data);
	// BMP_create(data, "test.bmp");
	// exit_game(data);
	return(0);
}
