/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:49:54 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:49:57 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void		error_msg(t_data *data, char *msg, t_bool dis_line)
{
	int		i;

	i = 0;
	write(1, "\nError : ", 9);
	while (msg[i])
		write(1, &msg[i++], 1);
	if (data->file_line > 0 && dis_line == true)
	{
		write(1, " at line : ", 11);
		ft_putnbr_fd(data->file_line, 1);
	}
	write(1, "\n", 1);
	exit_game(data);
}

void		check_init(t_data *data)
{
	if (data->win.load == false)
		error_msg(data, "Windows resolution is missing", false);
	else if (data->north.load == false || data->south.load == false ||
	data->east.load == false || data->west.load == false ||
	data->sprite.load == false)
		error_msg(data, "Missing texture path", false);
	else if (data->floor.load == false || data->ceilling.load == false)
		error_msg(data, "Missing RGB value", false);
	else if (data->map.load == true && data->player.load == false)
		error_msg(data, "Player position is missing or invalid", false);
}
