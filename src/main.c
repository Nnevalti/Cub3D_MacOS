/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:48:05 by vdescham          #+#    #+#             */
/*   Updated: 2019/11/26 11:41:48 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/header.h"

void game(t_data *data)
{

	mlx_key_hook(data->mlx->win_ptr, key_pressed, data);
	mlx_loop(data->mlx->mlx_ptr);
}

int		key_pressed(int key, t_data *data)
{
	if (key == 53)
	{
		exit_game(data);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_data		*data;

	(void)ac;
	data = malloc(sizeof(t_data));
	data->ray = malloc(sizeof(t_coord));
	init(av[1], data);
	game(data);
}
