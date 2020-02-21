#include "../include/Cub3D.h"
int		ft_strlen_nospace(char *s1)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s1[i])
	{
		if (ft_isalnum(s1[i]))
			len++;
		i++;
	}
	return (len);
}

char	*ft_strdup_nospace(char *s1)
{
	char	*s2;
	int		len;
	int		i;
	int		j;

	len = ft_strlen_nospace(s1);
	i = 0;
	if (!(s2 = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (ft_isalnum(s1[i]))
		{
			s2[j] = s1[i];
			j++;
		}
		i++;
	}
	s2[j] = '\0';
	return (s2);
}

void		affich_map(int	**map)
{
	int		i;
	int		j;

	printf("map array\n");
	i = 0;
	while (i < 14)
	{
		j = 0;
		while (j < 29)
		{
			printf("%d", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		malloc_w(t_data *data, char *map, int height, int width)
{
	int		i;
	int		width;
	int		h;
	int		w;

	i = 0;
	h = 0;
	w = 0;
	width = 0;
	while (h < height)
	{
		if(!(data->map[h] = malloc(width * sizeof(int))))
		{
			data->error.map = true;
			exit_game(data);
		}
		h++;
	}

	while (map[i] || h < height)
	{
		if (map[i] == '0' || map[i] == '1' || map[i] == '2'|| map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map[i] == 'O')
		{
			w = 0;
			while (w < width)
			{
				if (ft_isdigit(map[(i - width) + w]))
					data->map[h][w] = map[(i - width) + w] - '0';
				else if (ft_isalpha(map[(i - width) + w]))
				{
					init_player(data, h, w, map[(i - width) + w]);
					data->map[h][w] = 0;
				}
				w++;
			}
			width = 0;
			h++;
		}
		else if (map[i] != '\n' && map[i] != '\0')
		{
			data->error.map = true;
			exit_game(data);
		}
		if (map[i] != '\0')
			i++;
	}
}

void		malloc_h(t_data *data, int fd, char *line)
{
	char	*map;
	char	*tmp;
	char	*tmp2;
	int		height;
	int		width_max;

	height = 1;
	width_max = 0;
	map = ft_strdup_nospace(line);
	free(line);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strjoin(map, "\n");
		free(map);
		tmp2 = ft_strdup_nospace(line);
		width_max = ft_strlen(tmp2) > width_max ? ft_strlen(tmp2) : width_max;
		free(line);
		map = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		height++;
	}
	free(line);
	if (!(data->map = (int **)malloc(height * sizeof(int *))))
	{
		data->error.map = true;
		exit_game(data);
	}
	malloc_w(data, map, height, width_max);
	free(map);
}

void		init_map(t_data *data, char *line, int fd)
{
	char	*map;

	check_init(data);
	malloc_h(data, fd, line);
	affich_map(data->map);
	// for (int i = 0; i < 14; i++)
	// 	free(data->map[i]);
	// free(data->map);
}
