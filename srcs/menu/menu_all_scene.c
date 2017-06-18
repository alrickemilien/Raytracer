/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_all_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:08:44 by salibert          #+#    #+#             */
/*   Updated: 2017/05/06 13:44:20 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "menu.h"
#include "init.h"
#include "parser.h"

static void		data_picture(t_menu *menu, t_env *env, t_data_draw *data)
{
	env->msaa = 0;
	raytracing((void*)env);
	data->picture = env->image;
	draw_menu(*data, menu->page);
	close(env->fd);
}

static void		data_while(t_data_draw *data,
				t_list *tmp, t_env *env, t_menu *menu)
{
	while (tmp)
	{
		free_list(&env->list, &env->camera, &env->light, env);
		data = (t_data_draw*)(tmp->content);
		ft_bzero(env->tab_ray, sizeof(t_ray) * 600 * 400);
		if ((env->fd = open(data->path, O_RDWR)) == -1)
		{
			tmp = tmp->next;
			continue;
		}
		if (!parser(env) || !init_default_camera(env))
		{
			data->error = 1;
			data->picture = menu->error;
			draw_menu(*data, menu->page);
			tmp = tmp->next;
			close(env->fd);
			continue;
		}
		data_picture(menu, env, data);
		tmp = tmp->next;
	}
}

void			ray_draw_data(t_menu *menu, t_env *env)
{
	t_list		*tmp;
	t_data_draw	*data;

	tmp = menu->button;
	data = (t_data_draw*)(tmp->content);
	draw_menu(*data, menu->page);
	tmp = menu->button->next;
	data_while(data, tmp, env, menu);
	free_image(env->addr_mlx, &env->image, env->image->addr_img);
	ft_bzero(env->tab_ray, sizeof(t_ray) * 600 * 400);
	free_list(&env->list, &env->camera, &env->light, env);
	ft_bzero(env->select, sizeof(t_select));
}
