/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:46:15 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:44:31 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			set_bitmapfileheader(int fd, t_image *image)
{
	unsigned char	*header;
	unsigned char	*tmp;
	int				len;

	header = (unsigned char*)malloc(14);
	ft_bzero(header, 14);
	header[0] = 0x42;
	header[1] = 0x4D;
	len = image->width * image->height * 3;
	while (len % 4)
		len++;
	len += 54;
	tmp = (unsigned char*)&len;
	header[2] = tmp[0];
	header[3] = tmp[1];
	header[4] = tmp[2];
	header[5] = tmp[3];
	header[10] = 0x36;
	if ((len = write(fd, header, 14)) == -1)
		ft_putendl_fd("Error creating screenshot", 2);
}

void				set_bitmapinfoheader(int fd, t_image *image)
{
	unsigned char	*header;
	unsigned int	n;

	header = (unsigned char*)malloc(40);
	ft_bzero(header, 40);
	header[0] = 0x28;
	n = image->width;
	ft_write_n_bytes(header, (unsigned char*)&n, 4);
	n = image->height;
	ft_write_n_bytes(header, (unsigned char*)&n, 8);
	header[12] = 0x01;
	header[14] = 0x18;
	n = image->height * image->width * 3;
	ft_write_n_bytes(header, (unsigned char*)&n, 20);
	header[24] = 0xC3;
	header[25] = 0x0E;
	header[28] = 0xC3;
	header[29] = 0x0E;
	write(fd, header, 40);
}

void				data_to_bitmap(char *bitmap, t_image *image, int i)
{
	int				x;
	int				y;
	int				line;
	int				colonne;

	y = image->height - 1;
	while (y >= 0)
	{
		line = y * image->size_line;
		x = 0;
		while (x < image->width)
		{
			colonne = x * image->bpp / 8;
			bitmap[i] = image->data[line + colonne];
			bitmap[i + 1] = image->data[line + colonne + 1];
			bitmap[i + 2] = image->data[line + colonne + 2];
			i += 3;
			x++;
		}
		y--;
	}
}

void				set_bitmapdata(int fd, t_image *image)
{
	char			*bitmap;
	int				len;

	len = image->width * image->height * 3;
	while (len % 4)
		len++;
	if (!(bitmap = (char*)malloc(sizeof(char) * len)))
		error("error alloc in func set_bitmapdata");
	ft_bzero(bitmap, sizeof(char) * len);
	data_to_bitmap(bitmap, image, 0);
	write(fd, bitmap, len);
	free(bitmap);
}

void				ft_bitmap(t_image *image)
{
	int				fd;

	fd = open("screenshot.bmp", O_RDWR | O_CREAT
			| O_NONBLOCK, S_IRUSR | S_IWUSR);
	set_bitmapfileheader(fd, image);
	set_bitmapinfoheader(fd, image);
	set_bitmapdata(fd, image);
	close(fd);
	ft_putendl("screenshot.bmp has been created");
}
