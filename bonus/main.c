/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:48:05 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:50:29 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

int		game(t_data *data)
{
	if (move_player(data))
		raycast(data);
	return (0);
}

int		main(int ac, char **av)
{
	t_data		data;

	data = init_data(ac, av);
	raycast(&data);
	if (av[2] && !(ft_strcmp((av[2]), "--save")))
	{
		bmp_create(&data, "screenshots/screenshot.bmp");
		exit_game(&data);
	}
	else if (av[2])
	{
		error_msg(&data,
			"Second argument is invalid : should be --save or none", false);
	}
	mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
	mlx_hook(data.win_ptr, 3, 0, key_released, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_game, &data);
	mlx_loop_hook(data.mlx_ptr, game, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
