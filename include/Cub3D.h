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
# include <math.h>
# include <stdio.h>

typedef enum	e_bool
{
				false,
				true
}				t_bool;

typedef enum	e_side
{
				N,
				S,
				E,
				O
}				t_side;

typedef struct	s_win
{
	int			height;
	int			width;
	t_bool		load;
}				t_win;

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_key
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		r_left;
	int		r_right;
}				t_key;

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
	t_bool		hit;
	t_side		side;
	double		wall_dist;
	int			line_height;
	int			wall_start;
	int			wall_end;
	double		wall_x;
}				t_ray;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	t_bool		load;
}				t_color;

typedef struct	s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		height;
	int		width;
	int		endian;
	int		s_line;
	t_bool	load;
}				t_tex;

typedef struct	s_error
{
	t_bool		file;
	t_bool		mlx;
	t_bool		win;
	t_bool		tex;
	t_bool		rgb;
	t_bool		map;

}				t_error;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_error		error;
	t_win		win;
	int			file_line;
	// int			map[24][24];
	int			**map;

	t_key		key;

	t_player	player;

	t_coord		cam;
	t_ray		ray;

	t_tex		display;
	t_color		floor;
	t_color		ceilling;
	// t_tex		sky;
	// t_tex		ground;
	t_tex		north;
	t_tex		south;
	t_tex		west;
	t_tex		east;
	t_tex		sprite;


}				t_data;

int				check_file(char *file);
void			init_error(t_data *data);
void			check_error(t_data *data);
void			check_rgb(t_data *data, char *line);
void			init_tex(t_data *data, t_tex *tex, char *path);
char			*find_path(char *line);

void			init_map(t_data *data, char *line, int fd);
void			init_player(t_data *data, int h, int w, char dir);

int				ft_isspace(char c);
void			check_init(t_data *data);

t_data			init_data(char **av, int fd);
void			init_win(char *line, t_data *data);

void			init_color(t_data *data, char *line, t_color *color);

void			raycast(t_data *data);
int				game(t_data *data);
void			draw_tex(int x, t_data *data);
void 			draw_minimap(t_data *data, int width, int height, int size);
void			draw_square(t_data *data, int x, int y, int size, int color);
int				key_pressed(int key, t_data *data);
int				key_released(int key, t_data *data);
int				move_player(t_data *data);
void			BMP_create(t_data	*data, char	*filename);
int				exit_game(t_data *data);

#endif
