/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:50 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/30 11:07:58 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "vector.h"
#include "stdio.h"

static void	set_primary_ray(t_env *env, t_ray *ray, int j, int i)
{
	t_vector	null_vector;

	ray->dir.x = ((double)2 * (((double)j + 0.5) /
				(double)env->image->width) - (double)1)
		* env->scale * env->image_aspect_ratio;
	ray->dir.y = ((double)1 - (double)2 * (((double)i + 0.5) /
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

static t_color				raycast(t_env *env, t_ray ray, int depth)
{
	t_obj			*tmp;
	double			t;
	t_surface		s;
	t_color			color;
	t_color			ret;

	t = 0;
	tmp = NULL;
	ft_bzero(&color, sizeof(color));
	if (get_intersection(env, &ray, &tmp))
	{
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
			ret = raycast(env, get_reflection(s, ray), depth + 1);
			color = add_color(color, ret, (ray.coeff));
		}
	}
	return (color);
}

void		*raytracing(void *params)
{
	int			index;
	t_limit		l;
	t_env		*env;
	t_color		color;
	char		*data;

	env = (t_env*)(params);
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
			set_primary_ray(env, env->tab_ray + index, l.x, l.y);
			color = raycast(env, *(env->tab_ray + index), 0);
			index = (l.x * (env->image->bpp)) + (l.y * env->image->sizeline);
			data[index] = color.blue;
			data[index + 1] = color.green;
			data[index + 2] = color.red;
		}
	}
	return (NULL);
}
