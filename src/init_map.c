#include "../include/Cub3D.h"

void		affich_map(t_data *data, int **map)
{
	int		i;
	int		j;

	printf("map array\n");
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			printf("%d", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

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
			if (map[i] == '0' || map[i] == '1' || map[i] == '2'|| map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map[i] == 'W')
			{
				if (ft_isdigit(map[i]))
					data->map.map[h][w] = map[i] - '0';
				else if (ft_isalpha(map[i]))
				{
					init_player(data, h, w, map[i]);
					data->map.map[h][w] = 0;
				}
				if (map[i] == '2')
					data->nb_sprites++;
				i++;
			}
			else if (map[i] == '\n' || map[i] == '\0')
				data->map.map[h][w] = -1;
			else
			{
				data->error.map = true;
				exit_game(data);
			}
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
	{
		data->error.map = true;
		exit_game(data);
	}
	while (h < data->map.height)
	{
		if(!(data->map.map[h] = malloc(data->map.width * sizeof(int))))
		{
			data->error.map = true;
			exit_game(data);
		}
		h++;
	}
}

int			line_check(t_data *data, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (true);
		i++;
	}
	return (false);
}

int			left_check(t_data *data, char **map)
{
	int		h;

	h = 0;
	while (h < data->map.height)
	{
		if (map[h][0] != '1')
			return (true);
		h++;
	}
	return (false);
}

// int			right_check(t_data *data, char **map)
// {
// 	int		i;
//
// 	i = 1;
// 	while (map[i])
// 	{
// 		if (ft_strlen(map[i]) == ft_strlen(map[i - 1]))
// 		i++;
// 	}
// }

void		check_map(t_data *data, char **map)
{
	if (line_check(data, map[0])
		|| line_check(data, map[data->map.height - 1])
		|| left_check(data, map))
	{
		data->error.map = true;
		exit_game(data);
	}
	// || right_check(data, map)
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
		free(map);
		tmp2 = ft_strdup_nospace(line);
		data->map.width = ft_strlen(tmp2) > data->map.width
			? ft_strlen(tmp2) : data->map.width;
		free(line);
		map = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		data->map.height++;
	}
	free(line);
	malloc_map(data);
	fill_map(data, map);
	init_sprites(data);
	// check_map(data, ft_split(map, '\n'));
	data->map.load = true;
	free(map);
}

void		init_map(t_data *data, char *line, int fd)
{
	check_init(data);
	create_map(data, fd, line);
	// affich_map(data, data->map.map);
}
