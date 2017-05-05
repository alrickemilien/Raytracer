#include "rtv1.h"
#include "vector.h"
#include "stdio.h"

static int				get_intersection(t_env *env, t_ray *ray, t_obj **tmp)
{
	double				t;
	t_list				*tmp_list;

	ray->t = 2000000;
	t = 0;
	tmp_list = env->list;
	while (tmp_list)
	{
		if (((t_obj*)(tmp_list->content))->func_obj(
					(t_obj*)(tmp_list->content), ray,
					&t, NULL))
		{
			if (ray->t > t && t > ZERO)
			{
				ray->t = t;
				*tmp = ((t_obj*)(tmp_list->content))->pointeur[ray->thread];
			}
		}
		tmp_list = tmp_list->next;
	}
	if (*tmp)
		return (1);
	return (0);
}

static t_color			raycast(t_env *env, t_ray ray, int d, t_obj *tmp)
{
	double				t;
	t_surface			s;
	t_color				c;
	double				lightnorme;

	t = 0;
	c = shining(env->light, &ray, &lightnorme);
	if (!get_intersection(env, &ray, &tmp))
		return (c);
	if (lightnorme > ray.t)
		ft_bzero(&c, sizeof(c));
	s = get_surface_caracter(ray, tmp);
	set_color_coeff(env, s, tmp, &t);
	if ((tmp->etat == SPHERE || tmp->etat == PLAN) && tmp->texture)
		c = add_color(c, mapping(*(tmp), s), t);
	else
		c = add_color(c, tmp->color, t);
	if (d < 4 && (ray.coeff = fresnel(ray, s)) < 1 && tmp->refraction > 1)
		c = add_color(c, raycast(env, get_refraction(s, ray), d + 1, NULL),
					1 - ray.coeff);
	if (d < 4 && tmp->reflection)
		c = add_color(c,
				scolor(raycast(env, get_reflection(s, ray), d + 1, NULL),
				s.reflection), ray.coeff);
	return (c);
}

static t_color			get_ray_color(t_env *env, int x, int y)
{
	int					index;

	index = (y * WIN_HEIGHT + x);
	set_primary_ray(env, env->tab_ray + index, x, y);
	return (raycast(env, *(env->tab_ray + index), 0, NULL));
}

static t_color			get_ray_color_msa(t_env *env, int x, int y, int i)
{
	t_color				color[4];
	double				ty;
	double				tx;
	int					index;

	ty = (double)y - 0.25;
	i = 0;
	while (ty <= (double)y + 0.5)
	{
		tx = (double)x - 0.25;
		while (tx <= (double)x + 0.5)
		{
			index = (y * WIN_HEIGHT + x);
			set_primary_ray(env, env->tab_ray + index, tx, ty);
			color[i] = raycast(env, *(env->tab_ray + index), 0, NULL);
			i++;
			tx += 0.5;
		}
		ty += 0.5;
	}
	return (moyenne(color, 4));
}

void					*raytracing(void *params)
{
	int					index;
	t_limit				l;
	t_env				*e;
	t_color				color;

	e = (t_env*)(params);
	set_vignette_dimensions(e, &l);
	while (++l.y < l.max_y)
	{
		l.x = l.tmp_x;
		while (++l.x < l.max_x)
		{
			if (e->msaa)
				color = get_ray_color_msa(e, l.x, l.y, 0);
			else
				color = get_ray_color(e, l.x, l.y);
			index = (l.x * (e->image->bpp)) + (l.y * e->image->sizeline);
			e->image->data[index] = color.blue;
			e->image->data[index + 1] = color.green;
			e->image->data[index + 2] = color.red;
		}
	}
	return (NULL);
}
