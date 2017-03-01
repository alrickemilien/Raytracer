/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:55 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/01 14:45:56 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

double			shadow(t_env *env, t_ray ray, double norme)
{
	double		t;
	t_list		*tmp_list;
	int			ret;
	t_list		*inter;

	t = 0;
	ray.t = norme;
	normalize_vec(&ray.dir);
	tmp_list = env->list;
	while (tmp_list)
	{
		if ((ret = ((t_obj*)(tmp_list->content))->func_obj(
					*((t_obj*)(tmp_list->content)), &ray, &t, &inter)))
		{
			if (t <= norme && t >= 0)
				return (((t_obj*)(tmp_list->content))->transparent);
		}
		tmp_list = tmp_list->next;
	}
	return (1);
}
