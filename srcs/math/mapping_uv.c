#include "vector.h"

t_color		mlx_put_xpm(int u, int v, t_image texture)
{
	t_color color;
	int tmp;

	if (u >= texture.width && v >= texture.height)
	{
		u = (u >= texture.width ? texture.width - 1 : u);
		v = (v >= texture.height ? texture.height - 1 : v);
	}
	tmp = (u * (texture.bpp)) + (v * texture.sizeline);
	color.blue = (unsigned char)(texture.data[tmp]);
	color.green = (unsigned char)(texture.data[tmp + 1]);
	color.red = (unsigned char)(texture.data[tmp + 2]);
	return (color);
}

static t_color mapping_plan(t_image texture, t_surface s, double zoom)
{
	double v;
	double u;
	double tmp;
	double div;
	t_color color;

	u = s.intersection.x * zoom;
	v = -s.intersection.z * zoom;

	tmp = v / texture.height;
	div = floor(v / texture.height);
	v = (tmp - div) * texture.height;
	tmp = u / texture.width;
	div = floor(tmp);
	u = (tmp - div) * texture.height;
	color = mlx_put_xpm((int)u, (int)v, texture);
	return(color);
}

static t_color	mapping_sphere(t_image texture, t_surface s, double zoom)
{
	double v;
	double u;
	t_color color;

	normalize_vec(&s.intersection);
	u = (0.5 + atan2(s.intersection.z, s.intersection.x) / (M_PI + M_PI)) * (double)texture.width * zoom;
	v = (0.5 - asin(s.intersection.y) / M_PI) * (double)texture.height * zoom;
	color = mlx_put_xpm((int)u, (int)v, texture);
	return (color);
}

t_color			mapping(t_obj obj, t_surface s)
{

	if (obj.etat == SPHERE)
		return (mapping_sphere(*(obj.texture), s, obj.resize_texture));
	else
		return (mapping_plan(*(obj.texture), s, obj.resize_texture));
}
