/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:46:15 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/01 17:21:18 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun_struct.h"

static int			set_bitmapfileheader(int fd, t_image *image)
{
	unsigned char	*header;
	unsigned char	*tmp;
	int				len;

	if (!(header = (unsigned char*)malloc(14)))
		return (0);
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
	if ((len = write(fd, header, 14)) < 0)
	{
		free(header);
		return (0);
	}
	free(header);
	return (1);
}

static int			set_bitmapinfoheader(int fd, t_image *image)
{
	unsigned char	*header;
	unsigned int	n;

	if (!(header = (unsigned char*)malloc(40)))
		return (0);
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
	if (write(fd, header, 40) < 0)
	{
		free(header);
		return (0);
	}
	free(header);
	return (1);
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
		line = y * image->sizeline;
		x = 0;
		while (x < image->width)
		{
			colonne = x * image->bpp;
			bitmap[i] = image->data[line + colonne];
			bitmap[i + 1] = image->data[line + colonne + 1];
			bitmap[i + 2] = image->data[line + colonne + 2];
			i += 3;
			x++;
		}
		y--;
	}
}

static int			set_bitmapdata(int fd, t_image *image)
{
	char			*bitmap;
	int				len;

	len = image->width * image->height * 3;
	while (len % 4)
		len++;
	if (!(bitmap = (char*)malloc(sizeof(char) * len)))
		return (0);
	ft_bzero(bitmap, sizeof(char) * len);
	data_to_bitmap(bitmap, image, 0);
	if (write(fd, bitmap, len) < 0)
	{
		free(bitmap);
		return (0);
	}
	free(bitmap);
	return (1);
}

void				ft_bitmap(t_image *image)
{
	int				fd;

	fd = open("screenshot.bmp", O_RDWR | O_CREAT
			| O_NONBLOCK, S_IRUSR | S_IWUSR);
	if (fd < 0 
		|| !set_bitmapfileheader(fd, image)
		|| !set_bitmapinfoheader(fd, image)
		|| !set_bitmapdata(fd, image))
	{
		ft_putendl_fd("error appeared creating the screenshot", 2);
		return ;
	}
	if (close(fd) < 0)
	{
		ft_putendl_fd("error appeared creating the screenshot", 2);
		return ;
	}
	ft_putendl("screenshot.bmp has been created");
}
