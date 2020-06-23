#include "../include/Cub3D.h"

void		set_dir(t_data *data, int x, int y)
{
	data->player.dir.x = x;
	data->player.dir.y = y;
}

void		set_plane(t_data *data, double x, double y)
{
	data->player.plane.x = x;
	data->player.plane.y = y;
}

void		init_player(t_data *data, int h, int w, char dir)
{
	if (data->player.load == true)
		error_msg(data, "Player initialised twice", false);
	if (dir == 'N')
	{
		set_dir(data, 0, -1);
		set_plane(data, 0.66, 0);
	}
	else if (dir == 'S')
	{
		set_dir(data, 0, 1);
		set_plane(data, -0.66, 0);
	}
	else if (dir == 'E')
	{
		set_dir(data, 1, 0);
		set_plane(data, 0, 0.66);
	}
	else if (dir == 'W')
	{
		set_dir(data, -1, 0);
		set_plane(data, 0, -0.66);
	}
	data->player.pos.x = w;
	data->player.pos.y = h;
	data->player.move_speed = 0.05;
	data->player.rot_speed = 0.08;
	data->player.load = true;
}
