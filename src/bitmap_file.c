#include "../include/Cub3D.h"

void	BMP_header(t_data *data, int fd)
{
	int				file_size;
	unsigned char	bmp[54];

	// file_size = (data->win.height * data->win.width * 3) + 54;
	file_size = 54 + 3 * data->win.width * data->win.height +
		((4 - (data->win.width * 3) % 4) % 4) * data->win.height;
	// bmp signature (2 octets)
	bmp[0] = 'B';
	bmp[1] = 'M';

	//file size (4 octets)
	bmp[2] = (unsigned char)file_size;
	bmp[3] = (unsigned char)file_size >> 8;
	bmp[4] = (unsigned char)file_size >> 16;
	bmp[5] = (unsigned char)file_size >> 24;

	// reserved space must be 0 (2 + 2 octets)
	bmp[6] = 0;
	bmp[7] = 0;
	bmp[8] = 0;
	bmp[9] = 0;

	// offset start of pixel data (54)
	bmp[10] = 54;
	bmp[11] = 0;
	bmp[12] = 0;
	bmp[13] = 0;

	// BM info header size (40)
	bmp[14] = 40;
	bmp[15] = 0;
	bmp[16] = 0;
	bmp[17] = 0;

	// img width
	bmp[18] = (unsigned char)data->win.width;
	bmp[19] = (unsigned char)data->win.width >> 8;
	bmp[20] = (unsigned char)data->win.width >> 16;
	bmp[21] = (unsigned char)data->win.width >> 24;

	// img height
	bmp[22] = (unsigned char)data->win.height;
	bmp[23] = (unsigned char)data->win.height >> 8;
	bmp[24] = (unsigned char)data->win.height >> 16;
	bmp[25] = (unsigned char)data->win.height >> 24;

	// planes ?
	bmp[26] = 1;
	bmp[27] = 0;

	// bpp (rgb : 24) no transparency
	bmp[28] = 24;
	bmp[29] = 0;

	// compression method (no compression)
	bmp[30] = 0;
	bmp[31] = 0;
	bmp[32] = 0;
	bmp[33] = 0;

	// size of pixel in bits
	bmp[34] = (unsigned char)data->win.width * (unsigned char)data->win.height * 3;
	bmp[35] = (unsigned char)data->win.width * (unsigned char)data->win.height * 3 >> 8;
	bmp[36] = (unsigned char)data->win.width * (unsigned char)data->win.height * 3 >> 16;
	bmp[37] = (unsigned char)data->win.width * (unsigned char)data->win.height * 3 >> 24;

	// horizontal resolution - pixels per meter (2835)
	bmp[38] = 0;
    bmp[39] = 0;
    bmp[40] = 0b00110000;
    bmp[41] = 0b10110001;

	// vertical resolution - pixels per meter (2835)
	bmp[42] = 0;
    bmp[43] = 0;
    bmp[44] = 0b00110000;
    bmp[45] = 0b10110001;

	// color palette infos
	bmp[46] = 0;
    bmp[47] = 0;
    bmp[48] = 0;
    bmp[49] = 0;

	// number of important colors
	bmp[50] = 0;
    bmp[51] = 0;
    bmp[52] = 0;
    bmp[53] = 0;
	write(fd, bmp, sizeof(bmp));
	for (int i =0; i < 54; i++)
	{
		printf("%x / ", bmp[i]);
	}
}

void	BMP_create(t_data	*data, char	*filename)
{
	int		fd;
	int		i;
	int		img_size;

	img_size = data->win.height * data->win.width;
	fd = open(filename, O_CREAT | O_WRONLY, 0777);
	BMP_header(data, fd);
	i = 0;
	while (i < img_size)
	{
		write(fd, &(data->display.addr[i * 4]), 1);
		write(fd, &(data->display.addr[i * 4 + 1]), 1);
		write(fd, &(data->display.addr[i * 4 + 2]), 1);
		i++;
	}
	close(fd);
}
