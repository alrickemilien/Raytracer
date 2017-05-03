#include "rtv1.h"
#include "parser.h"
#include "init.h"
#include "menu.h"



static t_color		wb(t_color color)
{
	t_color	new_color;

	new_color.red = (unsigned char)(ft_dtrim(0, 255, (color.red * 0.393) +
				(color.green * 0.769) + (color.blue * 0.189)));
	new_color.green = (unsigned char)(ft_dtrim(0, 255, (color.red * 0.349) +
				(color.green * 0.686) + (color.blue * 0.168)));
	new_color.blue = (unsigned char)(ft_dtrim(0, 255, (color.red * 0.272) +
				(color.green * 0.534) + (color.blue * 0.131)));
	return (new_color);
}

void		set_sepia(t_env *env, t_image *image)
{
	int				x;
	int				y;
	int				index;
	char	*data;
	void		*test;
	t_color		color;

	data = image->data;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			index = (x * image->bpp) + (y * image->sizeline);
			color.red = data[index+2];
			color.green = data[index+1];
			color.blue = data[index];
			color = wb(color);
			data[index] = color.blue;
			data[index+1] = color.green;
			data[index+2] = color.red;
			x++;
		}
		ft_putnbr(y);
		write(1, "\n", 1);
		y++;
	}
	test = mlx_new_window(env->addr_mlx, WIN_WIDTH, WIN_HEIGHT, "test");
	mlx_put_image_to_window(
			env->addr_mlx, test, image->addr_img, 0, 0);
}
