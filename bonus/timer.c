/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:43:11 by vdescham          #+#    #+#             */
/*   Updated: 2020/07/02 14:43:14 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void		draw_timer_square(t_data *data, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < 25)
	{
		j = 0;
		while (j < 25)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void		draw_timer(t_data *data, t_bool raycast)
{
	int		x;
	int		y;

	x = data->win.width - 25;
	y = 0;
	data->t2 = time(NULL);
	if ((difftime(data->t2, data->t1) > data->timer || raycast)
		&& !data->success)
	{
		if (difftime(data->t2, data->t1) > data->timer)
			data->player.is_shooting = false;
		data->timer = difftime(data->t2, data->t1);
		data->sec = ft_itoa(data->timer);
		draw_timer_square(data, x, y, 0x000000);
		mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, 0xCCCC00, data->sec);
		free(data->sec);
	}
}
