/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:50:54 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:50:56 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void	free_map(t_data *data, int line)
{
	int		i;

	i = 0;
	while (i < line)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
}

void	free_tex(t_data *data)
{
	if (data->north.load == true)
		mlx_destroy_image(data->mlx_ptr, data->north.img);
	if (data->south.load == true)
		mlx_destroy_image(data->mlx_ptr, data->south.img);
	if (data->east.load == true)
		mlx_destroy_image(data->mlx_ptr, data->east.img);
	if (data->west.load == true)
		mlx_destroy_image(data->mlx_ptr, data->west.img);
	if (data->sprite.load == true)
		mlx_destroy_image(data->mlx_ptr, data->sprite.img);
	if (data->display.load == true)
		mlx_destroy_image(data->mlx_ptr, data->display.img);
}

int		exit_game(t_data *data)
{
	if (data->map.load == true)
		free_map(data, data->map.height);
	free_tex(data);
	if (data->depth_buffer)
		free(data->depth_buffer);
	if (data->win.load == true)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}
