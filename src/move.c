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

void	up(t_data *data)
{
	if (data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x
		+ data->player.dir.x * data->player.move_speed)] != 1)
		data->player.pos.x += data->player.dir.x * data->player.move_speed;
	if (data->map.map[(int)(data->player.pos.y + data->player.dir.y
		* data->player.move_speed)][(int)(data->player.pos.x)] != 1)
		data->player.pos.y += data->player.dir.y * data->player.move_speed;
}

void	down(t_data *data)
{
	if (data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x
		- data->player.dir.x * data->player.move_speed)] != 1)
		data->player.pos.x -= data->player.dir.x * data->player.move_speed;
	if (data->map.map[(int)(data->player.pos.y - data->player.dir.y
		* data->player.move_speed)][(int)(data->player.pos.x)] != 1)
		data->player.pos.y -= data->player.dir.y * data->player.move_speed;
}

void	right(t_data *data)
{
	if (data->map.map[(int)data->player.pos.y][(int)(data->player.pos.x
		+ data->player.plane.x * data->player.move_speed)] != 1)
		data->player.pos.x += data->player.plane.x
		* data->player.move_speed;
	if (data->map.map[(int)(data->player.pos.y + data->player.plane.y
		* data->player.move_speed)][(int)data->player.pos.x] != 1)
		data->player.pos.y += data->player.plane.y
		* data->player.move_speed;
}

void	left(t_data *data)
{
	if (data->map.map[(int)data->player.pos.y][(int)(data->player.pos.x
		- data->player.plane.x * data->player.move_speed)] != 1)
		data->player.pos.x -= data->player.plane.x
		* data->player.move_speed;
	if (data->map.map[(int)(data->player.pos.y - data->player.plane.y
		* data->player.move_speed)][(int)data->player.pos.x] != 1)
		data->player.pos.y -= data->player.plane.y
		* data->player.move_speed;
}

int		move_player(t_data *data)
{
	if (data->key.up == true)
		up(data);
	if (data->key.down == true)
		down(data);
	if (data->key.right == true)
		right(data);
	if (data->key.left == true)
		left(data);
	if (data->key.r_right == true)
		r_right(data);
	if (data->key.r_left == true)
		r_left(data);
	if (data->key.up == false && data->key.down == false
		&& data->key.left == false && data->key.right == false
		&& data->key.r_left == false && data->key.r_right == false)
		return (0);
	return (1);
}
