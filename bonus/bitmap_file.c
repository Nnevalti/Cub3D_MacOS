#include "../include/Cub3D.h"

void	number_to_mem(char *dest, int nb, int nb_bytes)
{
	int		shift;
	int		i;

	i = nb_bytes - 1;
	shift = (nb_bytes > 1) ? (nb_bytes - 1) * 8 : 0;
	while (shift > 0)
	{
		dest[i] = (nb >> shift) & 0xFF;
		shift -= 8;
		i--;
	}
	dest[i] = nb & 0xFF;
}

void	write_bmp_header(t_data *data, int fd)
{
	char	header[54];
	int		nb_pixels;

	nb_pixels = data->win.height * data->win.width * 4;
	header[0] = 'B';
	header[1] = 'M';
	number_to_mem(&header[2], 54 + nb_pixels, 4);
	number_to_mem(&header[6], 0, 4);
	number_to_mem(&header[10], 54, 4);
	number_to_mem(&header[14], 40, 4);
	number_to_mem(&header[18], data->win.width, 4);
	number_to_mem(&header[22], data->win.height, 4);
	number_to_mem(&header[26], 1, 2);
	number_to_mem(&header[28], data->display.bpp, 2);
	number_to_mem(&header[30], 0, 4);
	number_to_mem(&header[34], nb_pixels, 4);
	number_to_mem(&header[38], 0, 16);
	write(fd, header, 54);
}

void	BMP_create(t_data	*data, char	*filename)
{
	int		fd;
	int		i;
	int		j;
	int		img_size;

	img_size = data->win.height * data->win.width;
	fd = open(filename, O_CREAT | O_WRONLY, 0777);
	write_bmp_header(data, fd);
	i = data->win.height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < data->win.width)
		{
			write(fd, &(data->display.addr[(j * data->display.bpp >> 3) + data->display.s_line * i]), 1);
			write(fd, &(data->display.addr[(j * data->display.bpp >> 3) + 1 + data->display.s_line * i]), 1);
			write(fd, &(data->display.addr[(j * data->display.bpp >> 3) + 2 + data->display.s_line * i]), 1);
			write(fd, &(data->display.addr[(j * data->display.bpp >> 3) + 3 + data->display.s_line * i]), 1);
			j++;
		}
		i--;
	}
	data->bmp_index++;
	close(fd);
}
