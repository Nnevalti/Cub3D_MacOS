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

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <time.h>
# include <stdio.h>

# define MINIMAP_SIZE 3
# define MINIMAP_OFFSET 20


typedef enum	e_bool
{
				false,
				true
}				t_bool;

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_error
{
	t_bool		file;
	t_bool		mlx;
	t_bool		win;
	t_bool		tex;
	t_bool		loadtex;
	t_bool		rgb;
	t_bool		loadrgb;
	t_bool		map;
	t_bool		player;
	t_bool		loadplayer;

}				t_error;

typedef struct	s_win
{
	int			height;
	int			width;
	t_bool		load;
}				t_win;

typedef enum	e_side
{
				N,
				S,
				E,
				W
}				t_side;

typedef struct	s_player
{
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	double		move_speed;
	double		rot_speed;
	t_bool		load;
	int			life;
	int			lifebar_size;
	t_bool		has_key;
	t_bool		is_shooting;
}				t_player;

typedef struct s_ennemy
{
	int		life;
	int		damage;
}				t_ennemy;

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

typedef struct	s_sprite
{
	t_coord		pos;
	double		distance;
	int			sprite_x;
	int			size;
	int			start_x;
	int			end_x;
	int			start_y;
	int			end_y;
	t_tex		texture;
	t_bool		is_alive;
}				t_sprite;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	t_bool		load;
}				t_color;

typedef struct	s_map
{
	int			**map;
	int			height;
	int			width;
	t_bool		load;
}				t_map;

typedef struct	s_key
{
	t_bool		up;
	t_bool		down;
	t_bool		left;
	t_bool		right;
	t_bool		r_left;
	t_bool		r_right;
	t_bool		shoot;
}				t_key;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_error		error;
	t_win		win;
	int			file_line;
	t_map		map;

	t_key		key;

	t_player	player;

	t_coord		cam;
	t_ray		ray;
	t_ray		gun;

	t_tex		display;
	t_color		floor;
	t_color		ceilling;
	t_tex		sky;
	t_tex		north;
	t_tex		south;
	t_tex		west;
	t_tex		east;
	t_tex		sprite;
	t_tex		sprite2;
	t_tex		sprite3;
	t_tex		sprite4;
	t_tex		sprite5;
	t_tex		sprite6;
	t_tex		sprite7;
	t_tex		sprite8;
	t_coord		portal;
	t_bool		success;
	t_bool		omg;
	t_bool		gameover;
	int			timer;
	char		*sec;

	double		*depth_buffer;
	t_sprite	*spr;
	int			nb_sprites;

	time_t		t1;
	time_t		t2;
}				t_data;

int				line_parse(t_data *data, char *line, int fd);
void			line_parse_bis(t_data *data, char *line);
void			init_load(t_data *data);
t_data			init_data(int ac, char **av);
void			init_win(char *line, t_data *data);
void			init_tex(t_data *data, t_tex *tex, char *path);
char			*find_path(char *line);
void			init_color(t_data *data, char *line, t_color *color);
void			init_map(t_data *data, char *line, int fd);
void			malloc_map(t_data *data);
void			free_map(t_data *data, int line);
void			init_player(t_data *data, int h, int w, char dir);
void			init_sprites(t_data *data);

void			draw_tex(int x, t_data *data);
void			draw_rgb(t_data *data, t_color *color, int y, int x);
void			draw_line_sprite(t_data *data, int index, int i);
void			draw_sprites(t_data *data);
t_color			get_sprite_rgb(t_data *data, int index, int i, int j);
void 			draw_minimap(t_data *data);
void			draw_lifebar(t_data *data);
void			interact(t_data *data, int cell_x, int cell_y);
void			draw_timer(t_data *data, t_bool raycast);
void 			draw_cursor(t_data *data);

void			shoot(t_data *data);

int				key_pressed(int key, t_data *data);
int				key_released(int key, t_data *data);
int				move_player(t_data *data);
void			r_left(t_data *data);
void			r_right(t_data *data);

void			check_init(t_data *data);
void			check_map(t_data *data);
void			error_msg(t_data *data, char *msg, t_bool dis_line);

char			*ft_itoa(int n);
int				ft_isspace(char c);
int				is_charset(char c, char *charset);
int				is_map(char *line);
int				ft_strlen_nospace(char *s1);
char			*ft_strdup_nospace(char *s1);

void			raycast(t_data *data);
void			bmp_create(t_data	*data, char	*filename);
int				exit_game(t_data *data);



#endif
