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
	if (move_player(data) && data->player.life >= 0
	&& !data->success && data->timer < 60)
	{
		raycast(data);
		draw_timer(data, true);
	}
	else if (data->player.life < 0 || data->timer > 59)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, data->win.width / 2,
			data->win.height / 2, 0xFF0000, "GET REKT");
		if (data->gameover == false)
		{
			system("afplay ./Musics/oof.mp3 -r 0.1 &");
			data->gameover = true;
		}
	}
	else if (data->success)
		mlx_string_put(data->mlx_ptr, data->win_ptr, data->win.width / 2,
			data->win.height / 2, 0xCCCC00, "GG EZ BROOOO");
	if (data->timer < 60)
		draw_timer(data, false);
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
	system("afplay ./Musics/undertale-megalovania.mp3 &");
	data.t1 = time(NULL);
	mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
	mlx_hook(data.win_ptr, 3, 0, key_released, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_game, &data);
	mlx_loop_hook(data.mlx_ptr, game, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
