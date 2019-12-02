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

int		main(int ac, char **av)
{
	t_data		data;

	(void)ac;
	data = init(av);
	mlx_do_key_autorepeatoff(data.mlx_ptr);
	mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
	mlx_hook(data.win_ptr, 3, 0, key_released, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_game, &data);
	// mlx_loop_hook(data.mlx_ptr, game, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
