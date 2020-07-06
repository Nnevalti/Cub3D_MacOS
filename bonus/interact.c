/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:59:19 by vdescham          #+#    #+#             */
/*   Updated: 2020/06/30 15:59:23 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

int		get_damage(int ennemy)
{
	if (ennemy == 7)
		return (1);
	if (ennemy == 8)
		return (5);
	if (ennemy == 9)
		return (10);
	return (0);
}

void	key_interact(t_data *data, int cell_x, int cell_y)
{
	int	j;

	j = 0;
	if (cell_x == 3 || cell_y == 3)
	{
		system("afplay Musics/damn.mp3 -v 3 &");
		j = 0;
		while (j < data->nb_sprites)
		{
			if ((int)data->player.pos.x == (int)data->spr[j].pos.x
			&& (int)data->player.pos.y == (int)data->spr[j].pos.y)
			{
				data->spr[j].is_alive = false;
				data->map.map[(int)data->spr[j].pos.y]
				[(int)data->spr[j].pos.x] = 0;
				data->player.has_key = true;
			}
			j++;
		}
	}
}

void	interact(t_data *data, int cell_x, int cell_y)
{
	int	ennemy;

	if ((cell_x >= 7 && cell_x <= 9) || (cell_y >= 7 && cell_y <= 9))
	{
		ennemy = cell_x > cell_y ? cell_x : cell_y;
		data->player.life -= get_damage(ennemy);
		system("afplay ./Musics/oof.mp3 -v 3 &");
	}
	if ((cell_x == 4 || cell_y == 4) && data->player.has_key)
	{
		data->player.pos.x = data->portal.x;
		data->player.pos.y = data->portal.y;
		system("afplay Musics/tp.mp3 &");
	}
	if (cell_x == 6 || cell_y == 6)
		data->success = true;
	key_interact(data, cell_x, cell_y);
}
