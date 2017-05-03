#include "rtv1.h"
#include "parser.h"
#include "init.h"
#include "menu.h"

static void			wb(int index, t_image *image, t_image *tmp)
{
	t_color			color;

	color.red = image->data[index + 2];
	color.green = image->data[index + 1];
	color.blue = image->data[index];
	color.red = (unsigned char)(ft_dtrim(0, 255, (color.red * 0.393)
					+ (color.green * 0.769) + (color.blue * 0.189)));
	color.green = (unsigned char)(ft_dtrim(0, 255, (color.red * 0.349)
					+ (color.green * 0.686) + (color.blue * 0.168)));
	color.blue = (unsigned char)(ft_dtrim(0, 255, (color.red * 0.272)
				+ (color.green * 0.534) + (color.blue * 0.131)));
	tmp->data[index] = color.blue;
	tmp->data[index + 1] = color.green;
	tmp->data[index + 2] = color.red;
}

void				set_sepia(t_env *env, t_image *image)
{
	int				x;
	int				y;
	int				index;
	t_image			*tmp;

	tmp = init_image(env->addr_mlx, WIN_WIDTH, WIN_HEIGHT);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			index = (x * image->bpp) + (y * image->sizeline);
			wb(index, image, tmp);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(
			env->addr_mlx, env->addr_win, tmp->addr_img, 0, 0);
}
