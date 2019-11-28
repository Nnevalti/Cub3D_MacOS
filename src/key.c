#include "../include/Cub3D.h"

int		key_pressed(int key, t_data *data)
{
	if (key == 53)
		exit_game(data);
	else if (key == 126)
		data->key.up = 1;
	else if (key == 125)
		data->key.down = 1;
	else if (key == 124)
		data->key.right = 1;
	else if (key == 123)
		data->key.left = 1;
	return (0);
}

int		key_released(int key, t_data *data)
{
	if (key == 126)
		data->key.up = 0;
	else if (key == 125)
		data->key.down = 0;
	else if (key == 124)
		data->key.right = 0;
	else if (key == 123)
		data->key.left = 0;
	return (0);
}
