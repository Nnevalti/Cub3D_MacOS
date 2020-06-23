/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:51:17 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:51:19 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void	r_left(t_data *data)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(-data->player.rot_speed)
	- data->player.dir.y * sin(-data->player.rot_speed);
	data->player.dir.y = old_dir_x * sin(-data->player.rot_speed)
	+ data->player.dir.y * cos(-data->player.rot_speed);
	old_plane_x = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(-data->player.rot_speed)
	- data->player.plane.y * sin(-data->player.rot_speed);
	data->player.plane.y = old_plane_x * sin(-data->player.rot_speed)
	+ data->player.plane.y * cos(-data->player.rot_speed);
}

void	r_right(t_data *data)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(data->player.rot_speed)
	- data->player.dir.y * sin(data->player.rot_speed);
	data->player.dir.y = old_dir_x * sin(data->player.rot_speed)
	+ data->player.dir.y * cos(data->player.rot_speed);
	old_plane_x = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(data->player.rot_speed)
	- data->player.plane.y * sin(data->player.rot_speed);
	data->player.plane.y = old_plane_x * sin(data->player.rot_speed)
	+ data->player.plane.y * cos(data->player.rot_speed);
}
