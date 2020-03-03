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
	int			fd;

	(void)ac;
	if (!(av[1]) || ft_strcmp((av[1] + ft_strlen(av[1]) - 4), ".cub")
		|| (fd = open(av[1], O_RDONLY)) == -1)
		error_msg(&data, "Configuration file missing or doesn't exist", false);
	init_load(&data);
	data = init_data(av, fd);
	raycast(&data);
	if (av[2] && !(ft_strcmp((av[2]), "--save")))
	{
		bmp_create(&data, "screenshot.bmp");
		exit_game(&data);
	}
	mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
	mlx_hook(data.win_ptr, 3, 0, key_released, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_game, &data);
	mlx_loop_hook(data.mlx_ptr, game, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
