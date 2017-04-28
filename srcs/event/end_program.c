/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:44:37 by aemilien          #+#    #+#             */
/*   Updated: 2017/04/28 08:50:04 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parser.h"

void		end_scene(t_menu *menu, void *addr_mlx, void *addr_win)
{
	t_env	*env;

	env = menu->env;
	mlx_destroy_window(addr_mlx, addr_win);
	ft_bzero(env->tab_ray, sizeof(t_ray) * 1000 * 1000);
	free_list(&env->list, &env->camera, &env->light, env);
	env->reset = NULL;
	env->etat = 0;
}

void		end_menu(t_menu *menu,
					void *addr_mlx,
					void *addr_win,
					void *addr_img)
{
	t_env	*env;

	(void)addr_img;
	env = menu->env;
	if (env->image)
		mlx_destroy_image(env->addr_mlx, env->image->addr_img);
	if (addr_win)
		mlx_destroy_window(addr_mlx, addr_win);
	if (env->tab_ray)
		free(env->tab_ray);
	if (env->tab_str_object)
		free_tab(&env->tab_str_object, NBR_OBJECT);
	if (env->tab_str_description)
		free_tab(&env->tab_str_description, NBR_DESCRIPTION);
	if (env->select)
		free(env->select);
	free_list(&env->list, &env->camera, &env->light, env);
	free(env);
	exit(0);
}
