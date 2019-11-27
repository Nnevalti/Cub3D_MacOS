/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                           :+:      :+:    :+:   */
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
#include <math.h>
# include <stdio.h>

enum	e_bool
{
	false,
	true
};

typedef struct	s_win
{
	int			height;
	int			width;
}				t_win;

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
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct	s_ray
{
	t_coord		dir;
	int			mapX;
	int			mapY;
	t_coord		delta_dist;
	t_coord		side_dist;
	int			stepX;
	int			stepY;
}				t_ray;

typedef struct	s_key
{
	int		up;
	int		down;
	int		left;
	int		right;
}				t_key;

typedef struct	s_img
{
	char	*file;
	void	*img_ptr;
	char	*addr;
	int		height;
	int		width;
	int		*endian;
	int		*size_line;
	int		*bits_per_pixel;
}				t_img;

typedef struct	s_tex
{
	t_img		*N;
	t_img		*S;
	t_img		*W;
	t_img		*O;
	int			RGB;

}				t_tex;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_win		*win;
	int			map[24][24];
	t_key		*key;
	t_player	*player;
	t_ray		*ray;
	t_coord		cam;
	t_tex		*tex;
}				t_data;

int				exit_game(t_data *data);
int				init(char **av, t_data *data);
void			init_mlx(t_data *data);
void			init_map(t_data *data);
void			init_player(t_data *data);
void			init_win (char *line, t_data *data);
int				move_player(t_data *data);
int				key_pressed(int key, t_data *data);
int				key_released(int key, t_data *data);
void			draw_line(int x, int start, int end, int color, t_data *data);
void			init_tex(t_data *data);

#endif
