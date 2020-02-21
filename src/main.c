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

int		check_file(char *file)
{
	int		i;

	i = 0;
	while(file[i])
	{
		if (!(ft_strcmp((file + ft_strlen(file) - 4), ".cub")))
			return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_data		data;
	int			fd;

	(void)ac;
	init_error(&data);
	if (!(av[1]) || !(check_file(av[1]))
		|| (fd = open(av[1], O_RDONLY)) == -1)
	{
		data.error.file = true;
		exit_game(&data);
	}
	data = init_data(av, fd);
	raycast(&data);
	// mlx_do_key_autorepeatoff(data.mlx_ptr);
	mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
	mlx_hook(data.win_ptr, 3, 0, key_released, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_game, &data);
	mlx_loop_hook(data.mlx_ptr, game, &data);
	mlx_loop(data.mlx_ptr);
	// system("leaks Cub3D");
	return (0);
}
