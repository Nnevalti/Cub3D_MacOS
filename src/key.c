#include "../include/Cub3D.h"

int		key_pressed(int key, t_data *data)
{
	if (key == 53)
		exit_game(data);
	else if (key == 13)
		data->key.up = true;
	else if (key == 1)
		data->key.down = true;
	else if (key == 124)
		data->key.r_right = true;
	else if (key == 123)
		data->key.r_left = true;
	else if (key == 0)
		data->key.left = true;
	else if (key == 2)
		data->key.right = true;
	else if (key == 257)
		data->player.move_speed = 0.12;
	else if (key == 8)
		BMP_create(data, "screenshot_c.bmp");
	return (0);
}

int		key_released(int key, t_data *data)
{
	if (key == 13)
		data->key.up = false;
	else if (key == 1)
		data->key.down = false;
	else if (key == 124)
		data->key.r_right = false;
	else if (key == 123)
		data->key.r_left = false;
	else if (key == 0)
		data->key.left = false;
	else if (key == 2)
		data->key.right = false;
	else if (key == 257)
		data->player.move_speed = 0.08;
	return (0);
}
