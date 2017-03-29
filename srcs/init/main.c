/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:38 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/29 16:50:04 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "init.h"
#include "parser.h"
#include "menu.h"

static	void ft_objdel_s(t_list **obj, void *addr_mlx)
{
	t_obj	*tmp_obj;
	t_list	*list;
	t_list	*tmp_list;

	list = *obj;
	while (list)
	{
		if ((tmp_obj = (t_obj*)(list->content)))
		{
			if (tmp_obj->texture)
			{
				mlx_destroy_image(addr_mlx, tmp_obj->texture->image);
				free(tmp_obj->texture);
			}
			if (tmp_obj->csg)
			{
				ft_objdel_s(&tmp_obj->csg, addr_mlx);
				printf("%d\n", tmp_obj->type);
			}
			if (tmp_obj->matrix)
				free(tmp_obj->matrix);
			tmp_list = list;
			list = list->next;
			free(tmp_list->content);
			tmp_list->content = NULL;
			free(tmp_list);
		}
	}
	*obj = NULL;
}


static void	ft_lstdel_s(t_list **alst)
{
	t_list *list1;
	t_list *list2;

	list1 = *alst;
	while (list1)
	{
		list2 = list1->next;
		free(list1->content);
		list1->content = NULL;
		free(list1);
		list1 = list2;
	}
	*alst = NULL;
}

static void del_camera(void *data, size_t size)
{
	t_camera *tmp;

	(void)size;
	tmp = (t_camera*)data;
	if (tmp->matrix)
		free(tmp->matrix);
	free(data);
}
static void	free_list(t_list **obj, t_list **camera, t_list **t_3, t_env *env)
{
		ft_objdel_s(obj, env->addr_mlx);
		ft_lstdel(camera, &del_camera);
		ft_lstdel_s(t_3);
}

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
		free_list(&env->list, &env->camera, &env->light, env);
		data = (t_data_draw*)(tmp->content);
		if ((env->fd = open(data->path, O_RDWR)) == -1)
		{
			tmp = tmp->next;
			continue;
		}
		if (!parser(env))
		{
			free_list(&env->list, &env->camera, &env->light, env);
			ft_bzero(env->tab_ray, sizeof(t_ray) * 600 * 400);
			draw_menu(*data, menu->page);
			tmp = tmp->next;
			continue;
		}
		if (!env->camera)
			init_default_camera(env);
		else
			sort_camera(env);
		printf("list %lu\n", sizeof(t_env));
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