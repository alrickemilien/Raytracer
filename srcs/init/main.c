/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:38 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/30 14:23:17 by salibert         ###   ########.fr       */
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
	env->image = init_image(menu->addr_mlx, 400, 200);
	env->tab_ray = (t_ray*)malloc(sizeof(t_ray) * 400 * 600);
	env->image_aspect_ratio = 400 / 200;
	env->nb_thread = 9;
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
		if (!parser(env))
		{

			draw_menu(*data, menu->page);
			tmp = tmp->next;
			continue;
		}
		if (!env->camera)
			init_default_camera(env);
		else
			sort_camera(env);
		raytracing((void*)env);
		data->picture = env->image;
		draw_menu(*data, menu->page);
		tmp = tmp->next;
		close(env->fd);
	}
	free_list(&env->list, &env->camera, &env->light, env);
}

void init_scene(t_env *env, char *path)
{
	env->addr_mlx = mlx_init();
	if (!(env->image = init_image(env->addr_mlx, WIN_WIDTH, WIN_HEIGHT)))
		merror();
	env->tab_ray = (t_ray*)malloc(sizeof(t_ray) * 1000 * 1000);
	env->image_aspect_ratio = 1000 / 1000;
	env->addr_win = mlx_new_window(env->addr_mlx, WIN_WIDTH, WIN_HEIGHT, "RT");
	env->tab_thread = init_thread(8);
	env->nb_thread = 0;
	env->fd = open(path, O_RDWR);
	if (!parser(env))
		exit(0);
	if (!env->camera)
		init_default_camera(env);
	else
		sort_camera(env);
	env->tab_env = init_data_tab_thread((void*)env, (sizeof(t_env)), 8);
	thread(env->tab_thread, &raytracing, env->tab_env, sizeof(t_env));
	mlx_put_image_to_window(env->addr_mlx, env->addr_win, env->image->image, 0, 0);
	free_list(&env->list, &env->camera, &env->light, env);
	mlx_loop(env->addr_mlx);
}

int		main()
{
	t_env	*env;
	t_menu	*menu;

	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		error(env, "error malloc in main");
	init_env(env);
	if (!(menu = creat_menu()))
		merror();
	ray_draw_data(menu, env);
	menu->env = env;
	mlx_put_image_to_window(menu->addr_mlx, menu->addr_win, menu->page->image, 0, 0);
//	mlx_hook(env->addr_win, 2, 1L << 0 | 1 << 1, &key_press, env);
	mlx_hook(menu->addr_win, 2, 1L << 0 | 1 << 1, &key_press, env);
	mlx_mouse_hook(menu->addr_win, ft_mouse, menu);
//	mlx_hook(env->addr_win, 17, 0L, &red_cross, env);
	mlx_loop(menu->addr_mlx);
	return (0);
}