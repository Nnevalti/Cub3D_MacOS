#include "../include/Cub3D.h"

void up(t_data *data) {
	if(data->map[(int)(data->player.pos.x + data->player.dir.x * data->player.move_speed)][(int)(data->player.pos.y)] == false) data->player.pos.x += data->player.dir.x * data->player.move_speed;
	if(data->map[(int)(data->player.pos.x)][(int)(data->player.pos.y + data->player.dir.y * data->player.move_speed)] == false) data->player.pos.y += data->player.dir.y * data->player.move_speed;
}

void down(t_data *data) {
	if(data->map[(int)(data->player.pos.x - data->player.dir.x * data->player.move_speed)][(int)(data->player.pos.y)] == false) data->player.pos.x -= data->player.dir.x * data->player.move_speed;
	if(data->map[(int)(data->player.pos.x)][(int)(data->player.pos.y - data->player.dir.y * data->player.move_speed)] == false) data->player.pos.y -= data->player.dir.y * data->player.move_speed;
}

void right(t_data *data) {
	double oldDirX =  data->player.dir.x;
	 data->player.dir.x =  data->player.dir.x * cos(-data->player.rot_speed) -  data->player.dir.y * sin(-data->player.rot_speed);
	 data->player.dir.y = oldDirX * sin(-data->player.rot_speed) +  data->player.dir.y * cos(-data->player.rot_speed);
	double oldPlaneX =  data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(-data->player.rot_speed) - data->player.plane.y * sin(-data->player.rot_speed);
	data->player.plane.y = oldPlaneX * sin(-data->player.rot_speed) + data->player.plane.y * cos(-data->player.rot_speed);
}

void left(t_data *data) {
	double oldDirX =  data->player.dir.x;
	data->player.dir.x =  data->player.dir.x * cos(data->player.rot_speed) - data->player.dir.y * sin(data->player.rot_speed);
	 data->player.dir.y = oldDirX * sin(data->player.rot_speed) + data->player.dir.y * cos(data->player.rot_speed);
	double oldPlaneX = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(data->player.rot_speed) - data->player.plane.y * sin(data->player.rot_speed);
	data->player.plane.y = oldPlaneX * sin(data->player.rot_speed) + data->player.plane.y * cos(data->player.rot_speed);
}

int		move_player(t_data *data)
{
	if (data->key.up == 1)
		up(data);
	if (data->key.down == 1)
		down(data);
	if (data->key.right == 1)
		right(data);
	if (data->key.left == 1)
		left(data);
	return (0);
}
