/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:44:37 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/25 14:28:12 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	end_program(t_env *env)
{
	mlx_destroy_image(env->addr_mlx, env->image->image);
	mlx_destroy_window(env->addr_mlx, env->addr_win);
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
