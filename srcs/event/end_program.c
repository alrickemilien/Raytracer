/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:44:37 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:44:41 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	end_program(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	if (env->tab_ray)
		free(env->tab_ray);
	if (env->tab_str_object)
		free_tab(&env->tab_str_object, NBR_OBJECT);
	if (env->tab_str_description)
		free_tab(&env->tab_str_description, NBR_DESCRIPTION);
	if (env->light)
		free(env->light);
	if (env->select)
		free(env->select);
	ft_lstdel(&env->camera, &free_data);
	free(env);
	exit(0);
}
