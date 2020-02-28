#include "../include/Cub3D.h"

void		fill_map(t_data *data, char *map)
{
	int		i;
	int		h;
	int		w;

	i = 0;
	h = 0;
	data->nb_sprites = 0;
	while (h < data->map.height)
	{
		w = 0;
		while (w < data->map.width)
		{
			if (is_charset(map[i], "012"))
			{
				data->map.map[h][w] = map[i] - '0';
				if (map[i] == '2')
					data->nb_sprites++;
				i++;
			}
			else if (is_charset(map[i], "NSEW"))
			{
				init_player(data, h, w, map[i]);
				data->map.map[h][w] = 0;
				i++;
			}
			else if (is_charset(map[i], "\n\0"))
				data->map.map[h][w] = -1;
			else
				error_msg(data, "Map is invalid", true);
			w++;
		}
		if (map[i] != '\0')
			i++;
		h++;
	}
}

void		malloc_map(t_data *data)
{
	int		h;

	h = 0;
	if (!(data->map.map = (int **)malloc(data->map.height * sizeof(int *))))
		exit_game(data);
	while (h < data->map.height)
		if(!(data->map.map[h++] = malloc(data->map.width * sizeof(int))))
			exit_game(data);
}

int			row_check(t_data *data, char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (str[i++] != '1')
			return (true);
	return (false);
}

int			column_check(t_data *data, char **map, int i, int j)
{
	int		min;

	min = ft_strlen(map[i - 1]) < ft_strlen(map[i + 1])
		? ft_strlen(map[i - 1]) : ft_strlen(map[i + 1]);
	if ((j == 0 || (j >= min && j < ft_strlen(map[i]))) &&
		map[i][j] != '1')
		return (false);
	return (true);
}

void		check_map(t_data *data, char **map)
{
	int		i;
	int		j;

	if (row_check(data, map[0])
		|| row_check(data, map[data->map.height - 1]))
		error_msg(data, "Map is invalid", true);
	i = 1;
	while (i < data->map.height - 1)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (!(column_check(data, map, i, j)))
				error_msg(data, "Map is invalid", true);
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map[0]);
	free(map[i]);
	free(map);
}

void		init_sprites(t_data *data)
{
	int		i;
	int		j;
	int		index;

	if (!(data->sprites = malloc(data->nb_sprites * sizeof(t_sprite))))
		exit_game(data);
	index = 0;
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.map[i][j] == 2)
			{
				data->sprites[index].texture = data->sprite;
				data->sprites[index].pos.y = i;
				data->sprites[index].pos.x = j;
				index++;
			}
			j++;
		}
		i++;
	}
}

void		create_map(t_data *data, int fd, char *line)
{
	char	*map;
	char	*tmp;
	char	*tmp2;

	data->map.height = 1;
	data->map.width = 0;
	map = ft_strdup_nospace(line);
	free(line);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strjoin(map, "\n");
		tmp2 = ft_strdup_nospace(line);
		if (tmp2[0] == '\0')
			error_msg(data, "Empty line in map", false);
		data->map.width = ft_strlen(tmp2) > data->map.width
			? ft_strlen(tmp2) : data->map.width;
		free(map);
		map = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		free(line);
		data->map.height++;
	}
	free(line);
	malloc_map(data);
	fill_map(data, map);
	init_sprites(data);
	check_map(data, ft_split(map, '\n'));
	data->map.load = true;
	free(map);
}

void		init_map(t_data *data, char *line, int fd)
{
	check_init(data);
	create_map(data, fd, line);
}
