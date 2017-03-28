/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:38 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/28 17:51:40 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "init.h"
#include "parser.h"
#include "menu.h"

void	ray_draw_data(t_menu *menu, t_env *env)
{
	t_list *tmp;
	t_data_draw *data;
	
    tmp = menu->button;
	data = (t_data_draw*)(tmp->content);
	draw_menu(*data, menu->page);
    tmp = menu->button->next;
	env->image = init_image(env->addr_mlx, 400, 200);
	env->tab_ray = (t_ray*)malloc(sizeof(t_ray) * 400 * 600);
	env->image_aspect_ratio = 400 / 200;
	while (tmp)
    {
		env->light = NULL;
		env->list = NULL;
		env->camera = NULL;
		data = (t_data_draw*)(tmp->content);
		if ((env->fd = open(data->path, O_RDWR)) == -1)
		{
			tmp = tmp->next;
			continue;
		}
			//error(env, INVALID_FILE);
			printf("%s\n", data->path);
		if (!parser(env))
		{
			env->light = NULL;
			env->list = NULL;
			env->camera = NULL;
			ft_bzero(env->tab_ray, sizeof(t_ray) * 600 * 400);
			draw_menu(*data, menu->page);
			tmp = tmp->next;
			continue;
		}
		if (!env->camera)
			init_default_camera(env);
		else
			sort_camera(env);
		printf("salut\n");
		env->nb_thread = 0;
		raytracing((void*)env);
		data->picture = env->image;

	ft_bzero(env->tab_ray, sizeof(t_ray) * 600 * 400);
		draw_menu(*data, menu->page);
		tmp = tmp->next;
	}
}

int		main()
{
	t_env	*env;
	t_menu	*menu;

	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		error(env, "error malloc in main");
	init_env(env);
	if (!(menu = creat_menu(env->addr_mlx)))
		merror();
	ray_draw_data(menu, env);
	mlx_put_image_to_window(menu->addr_mlx, menu->addr_win, menu->page->image, 0, 0);
	mlx_hook(env->addr_win, 2, 1L << 0 | 1 << 1, &key_press, env);
	mlx_mouse_hook(env->addr_win, ft_mouse, menu);
	mlx_hook(env->addr_win, 17, 0L, &red_cross, env);
	mlx_loop(env->addr_mlx);
	return (0);
}