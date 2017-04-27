/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:50 by aemilien          #+#    #+#             */
/*   Updated: 2017/04/27 16:27:20 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "vector.h"
#include "stdio.h"

static void	set_primary_ray(t_env *env, t_ray *ray, double j, double i)
{
	t_vector	null_vector;

	ray->dir.x = ((double)2 * ((j + 0.5) /
				(double)env->image->width) - (double)1)
		* env->scale * env->image_aspect_ratio;
	ray->dir.y = ((double)1 - (double)2 * ((i + 0.5) /
				(double)env->image->height)) * env->scale;
	ray->dir.z = -1;
	ray->dir = product_matrix4x4(env->select->c->matrix, ray->dir);
	normalize_vec(&ray->dir);
	ft_bzero(&null_vector, sizeof(t_vector));
	ray->org = product_vec_matrix(env->select->c->matrix,
			null_vector);
	ray->coeff = 1;
	ray->thread = env->nb_thread;
}

static int	get_intersection(t_env *env, t_ray *ray, t_obj **tmp)
{
	double			t;
	t_list			*tmp_list;

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

static t_color	add_color(t_color current, t_color to_add, double t)
{
	current.red += (unsigned char)(ft_dtrim(0, 255 - current.red,
						((double)to_add.red * t)));
	current.green += (unsigned char)(ft_dtrim(0, 255 - current.green,
						((double)to_add.green * t)));
	current.blue += (unsigned char)(ft_dtrim(0, 255 - current.blue,
						((double)to_add.blue * t)));
	return (current);
}

static t_color		shining(t_env *env, t_list *lights, t_ray *ray, double *norme)
{
	double			d;
	t_color			color;
	t_vector		light_vec;
	double			tmp;

	(void)env;
	ft_bzero(&color, sizeof(t_color));
	*norme = 2000000;
	while (lights)
	{
		if (((t_light*)(lights->content))->shining)
		{
			light_vec = vec_diff(((t_light*)(lights->content))->org, ray->org);
			if (light_vec.norme < *norme)
				*norme = light_vec.norme;
			tmp = light_vec.norme;
			normalize_vec(&light_vec);
			if ((d = dot_product(light_vec, ray->dir))>0)
			{
				d = acos(d);
				d = ((t_light*)(lights->content))->intensity * exp(-pow(((d / (0.2 * (1 / tmp)))), 2));
				color.blue += (unsigned char)(ft_dtrim(0, 255 - color.blue, 255 * d * (10 / tmp)));
				color.red += (unsigned char)(ft_dtrim(0, 255 - color.red, 255 * d * (10 / tmp)));
				color.green += (unsigned char)(ft_dtrim(0, 255 - color.green, 255 * d * (10 / tmp)));
			}
		}
		lights = lights->next;
	}
	return (color);
}

static t_color				scale_color(t_color color, double k)
{
	color.red = (unsigned char)((double)color.red * k);
	color.blue = (unsigned char)((double)color.blue * k);
	color.green = (unsigned char)((double)color.green * k);
	return (color);
}

static t_color				raycast(t_env *env, t_ray ray, int depth)
{
	t_obj			*tmp;
	double			t;
	t_surface		s;
	t_color			color;
	t_color			ret;
	double			lightnorme;

	t = 0;
	lightnorme = 0;
	tmp = NULL;
	color = shining(env, env->light, &ray, &lightnorme);
	if (get_intersection(env, &ray, &tmp))
	{
		if (lightnorme > ray.t)
			ft_bzero(&color, sizeof(color));
		s = get_surface_caracter(ray, tmp);
		set_color_coeff(env, s, tmp, &t);
		if ((tmp->etat == SPHERE || tmp->etat == PLAN) && tmp->texture)
			color = add_color(color, mapping(*(tmp), s), t);
		else
			color = add_color(color, tmp->color, t);
		if (depth < 5 && (ray.coeff = fresnel(ray, s)) < 1 && tmp->refraction > 1)
		{
			ret = raycast(env, get_refraction(s, ray), depth + 1);
			color = add_color(color, ret, (1 - ray.coeff));
		}
		if (depth < 5 && tmp->reflection)
		{
//			printf("reflection: %lf\n");
			ret = raycast(env, get_reflection(s, ray), depth + 1);
			color = add_color(color, scale_color(ret, s.reflection), (ray.coeff));
		}
	}
	return (color);
}

t_color		moyenne(t_color *tab, int size)
{
	int			color[3];
	t_color		ret;
	int			i;

	ft_bzero(&color, sizeof(int) * 3);
	i = 0;
	while (i < size)
	{
		color[0] += tab[i].blue;
		color[1] += tab[i].green;
		color[2] += tab[i].red;
		i++;
	}
	ret.blue = (unsigned char)(color[0] / size);
	ret.green = (unsigned char)(color[1] / size);
	ret.red = (unsigned char)(color[2] / size);
	return (ret);
}

void		*raytracing(void *params)
{
	int			index;
	t_limit		l;
	t_env		*env;
	t_color		*color;
	t_color		final_color;
	char		*data;
	int			i;
	double		ty;
	double		tx;

	env = (t_env*)(params);
	color = (t_color*)malloc(sizeof(t_color) * 4);
	if (env->nb_thread == 9)
	{
		l.y = -1;
		l.max_y = 200;
		l.max_x = 400;
		l.tmp_x = -1;
	}
	else
		l = ft_limit_thread(env->nb_thread, env->image->width, env->image->height);
	data = env->image->data;
	while (++l.y < l.max_y)
	{
		l.x = l.tmp_x;
		while (++l.x < l.max_x)
		{
			index = (l.y * WIN_HEIGHT + l.x);
			ty = (double)l.y - 0.25;
			i = 0;
			//printf("%lf\n");
			while ( ty <= (double)l.y + 0.5)
			{
				tx = (double)l.x - 0.25;
				while ( tx <= (double)l.x + 0.5)
				{
					set_primary_ray(env, env->tab_ray + index, tx, ty);
					color[i] = raycast(env, *(env->tab_ray + index), 0);
					i++;
					tx += 0.5;
				}
				ty += 0.5;
			}
			index = (l.x * (env->image->bpp)) + (l.y * env->image->sizeline);
			final_color = moyenne(color, 4);
			data[index] = final_color.blue;
			data[index+1] = final_color.green;
			data[index+2] = final_color.red;
		}
	}
	return (NULL);
}
