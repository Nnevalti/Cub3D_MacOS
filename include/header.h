/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:57:40 by vdescham          #+#    #+#             */
/*   Updated: 2019/11/26 11:41:46 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../src/libft/libft.h"
# include "mlx.h"
# include <stdio.h>

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct	s_win
{
	int			height;
	int			width;
}				t_win;

typedef struct	s_map
{
	int			map[24][24];
}				t_map;

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_player
{
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	int			rot_angle;
	int			mov_speed;
	int			rot_speed;
}				t_player;

typedef struct	s_ray
{
	t_coord		dir;
	t_coord		side_dist;
	t_coord		delta_dist;
}				t_ray;


typedef struct	s_data
{
	t_mlx		*mlx;
	t_win		*win;
	t_map		*map;
	t_player	*player;
	t_ray		*ray;
	t_coord		*cam;

}				t_data;

int				exit_game(t_data *data);
int				init(char *line, t_data *data);
void			init_mlx(t_data *data);
void			init_map(t_data *data);
void			init_player(t_data *data);
void			init_win (char *line, t_data *data);
int				key_pressed(int key, t_data *data);

#endif
