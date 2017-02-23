/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:50 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/23 10:36:51 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	set_primary_ray(t_env *env, t_ray *ray, int j, int i)
{
	t_vector	null_vector;

	ray->dir.x = ((double)2 * (((double)j + 0.5) /
				(double)env->width) - (double)1)
		* env->scale * env->image_aspect_ratio;
	ray->dir.y = ((double)1 - (double)2 * (((double)i + 0.5) /
				(double)env->height)) * env->scale;
	ray->dir.z = -1;
	ray->dir = product_matrix4x4(env->select->c->matrix, ray->dir);
	normalize_vec(&ray->dir);
	ft_bzero(&null_vector, sizeof(t_vector));
	ray->org = product_vec_matrix(env->select->c->matrix,
			null_vector);
}

static int	get_intersection(t_env *env, t_ray *ray, t_obj **tmp)
{
	double		t;
	t_list		*tmp_list;

	ray->t = 2000000;
	t = 0;
	tmp_list = env->list;
	while (tmp_list)
	{
		if (((t_obj*)(tmp_list->content))->func_obj(
					*((t_obj*)(tmp_list->content)), ray, &t))
		{
			if (ray->t > t && t > ZERO)
			{
				ray->t = t;
				*tmp = (t_obj*)(tmp_list->content);
			}
		}
		tmp_list = tmp_list->next;
	}
	if (*tmp)
		return (1);
	return (0);
}

int				raycast(t_env *env, t_ray ray, t_color *color, int depth)
{
	t_obj		*tmp;
	double		t;
	t_surface	s;

	t = 0;
	tmp = NULL;
	if (get_intersection(env, &ray, &tmp))
	{
		s = get_surface_caracter(ray, tmp);
		set_color_coeff(env, s, tmp, &t);
		color->red += (unsigned char)(ft_dtrim(0, 255 - color->red,
					((double)tmp->color.red * t * pow(0.5, depth))));
		color->green += (unsigned char)(ft_dtrim(0, 255 - color->green,
					((double)tmp->color.green * t * pow(0.5, depth))));
		color->blue += (unsigned char)(ft_dtrim(0, 255 - color->blue,
					((double)tmp->color.blue * t * pow(0.5, depth))));
		if (depth < 1 && tmp->reflection)
			raycast(env, get_reflection(s, ray), color, depth + 1);
		return (1);
	}
	return (0);
}

void		*raytracing(void *params)
{
	int			index;
	t_limit		l;
	t_env		*env;
	t_color		color;

	env = (t_env*)(params);
	l = ft_limit_thread(env->nb_t);
	while (++l.y < l.max_y)
	{
		l.x = l.tmp_x;
		while (++l.x < l.max_x)
		{
			ft_memset(&color, 0, sizeof(color));
			index = (l.y * WIN_HEIGHT + l.x);
			set_primary_ray(env, env->tab_ray + index, l.x, l.y);
			if (raycast(env, *(env->tab_ray + index), &color, 0))
				mlx_put_pixel_to_image(env, l.x, l.y, color);
			else
				mlx_put_pixel_to_image(env, l.x, l.y, split_color(
							mlx_get_color_value(env->mlx, 0x001A3134)));
		}
	}
	return (NULL);
}
