#include "rtv1.h"
#include "parser.h"
#include "init.h"
#include "menu.h"

static void			set_blue(int *tmpc, t_image *im, int *d, int index)
{
	tmpc[0] = abs(-im->data[index - im->bpp * d[0] - im->sizeline * d[2]]
			- im->data[index - im->sizeline * d[2]]
			- im->data[index + im->bpp * d[1] - im->sizeline * d[2]]
			- im->data[index - im->bpp * d[0]]
			+ 8 * im->data[index]
			- im->data[index + im->bpp * d[1]]
			- im->data[index - im->bpp * d[0] + im->sizeline * d[3]]
			- im->data[index + im->sizeline * d[3]]
			- im->data[index + im->bpp * d[1] + im->sizeline * d[3]]);
}

static void			set_green(int *tmpc, t_image *im, int *d, int index)
{
	tmpc[1] = abs(-im->data[index + 1
			- im->bpp * d[0] - im->sizeline * d[2]]
			- im->data[index + 1 - im->sizeline * d[2]]
			- im->data[index + 1 + im->bpp * d[1] - im->sizeline * d[2]]
			- im->data[index + 1 - im->bpp * d[0]]
			+ 8 * im->data[index + 1]
			- im->data[index + 1 + im->bpp * d[1]]
			- im->data[index + 1 - im->bpp * d[0] + im->sizeline * d[3]]
			- im->data[index + 1 + im->sizeline * d[3]]
			- im->data[index + 1 + im->bpp * d[1] + im->sizeline * d[3]]);
}

static void			set_red(int *tmpc, t_image *im, int *d, int index)
{
	tmpc[2] = abs(-im->data[index + 2 - im->bpp * d[0] - im->sizeline * d[2]]
			- im->data[index + 2 - im->sizeline * d[2]]
			- im->data[index + 2 + im->bpp * d[1] - im->sizeline * d[2]]
			- im->data[index + 2 - im->bpp * d[0]]
			+ 8 * im->data[index + 2]
			- im->data[index + 2 + im->bpp * d[1]]
			- im->data[index + 2 - im->bpp * d[0] + im->sizeline * d[3]]
			- im->data[index + 2 + im->sizeline * d[3]]
			- im->data[index + 2 + im->bpp * d[1] + im->sizeline * d[3]]);
}

static void			wb(int x, int y, t_image *image, t_image *tmp)
{
	int				index;
	int				tmpc[3];
	int				d[4];

	ft_bzero(d, sizeof(int) * 4);
	if (x != 0)
		d[0] = 1;
	if (x != WIN_WIDTH - 1)
		d[1] = 1;
	if (y != 0)
		d[2] = 1;
	if (y != WIN_HEIGHT - 1)
		d[3] = 1;
	index = x * image->bpp + y * image->sizeline;
	set_blue(tmpc, image, d, index);
	set_green(tmpc, image, d, index);
	set_red(tmpc, image, d, index);
	tmp->data[index] = (unsigned char)(ft_trim(0, 255, tmpc[0]));
	tmp->data[index + 1] = (unsigned char)(ft_trim(0, 255, tmpc[1]));
	tmp->data[index + 2] = (unsigned char)(ft_trim(0, 255, tmpc[2]));
}

void				set_rep(t_env *env, t_image *image)
{
	int				x;
	int				y;
	t_image			*tmp;

	if (env->rep)
	{
		tmp = init_image(env->addr_mlx, WIN_WIDTH, WIN_HEIGHT);
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			x = -1;
			while (++x < WIN_WIDTH)
				wb(x, y, image, tmp);
		}
	}
	else
		tmp = image;
	mlx_put_image_to_window(
			env->addr_mlx, env->addr_win, tmp->addr_img, 0, 0);
	if (env->rep)
		free_image(env->addr_mlx, &tmp, tmp->addr_img);
}
