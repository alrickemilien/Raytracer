/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:53:24 by salibert          #+#    #+#             */
/*   Updated: 2017/05/06 09:19:06 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parser.h"
#include "init.h"
#include "menu.h"

void			ft_put_pos_select(t_env *env)
{
	char		*str;

	str = NULL;
	if (env->select->c)
	{
		recycle(&str, ft_itoa((env->select->c->num) + 1));
		mlx_string_put(env->addr_mlx, env->addr_win, 45, 50, B, str);
	}
	recycle(&str, NULL);
}

static void		select_index_camera(t_env *env, int keycode, int *i)
{
	if (keycode == KEY_OPEN_BRACKET)
	{
		if (env->select->c->num == 0)
			*i = env->nbr_cam;
		else
			*i = env->select->c->num - 1;
	}
	if (keycode == KEY_CLOSE_BRACKET)
	{
		if (env->select->c->num == env->nbr_cam)
			*i = 0;
		else
			*i = env->select->c->num + 1;
	}
}

static int		switch_cam(t_env *env, int keycode)
{
	int			i;
	t_camera	*cam;
	t_list		*tmp;

	if (!env->camera)
		return (0);
	tmp = (t_list*)(env->camera);
	i = 0;
	select_index_camera(env, keycode, &i);
	while (tmp)
	{
		cam = (t_camera*)(tmp->content);
		if (cam->num == i)
			env->select->c = cam;
		tmp = tmp->next;
	}
	env->tab_env = init_data_tab_thread((void*)env, sizeof(t_env), 8);
	thread(env->tab_thread, raytracing, env->tab_env, sizeof(t_env));
	mlx_put_image_to_window(
		env->addr_mlx, env->addr_win, env->image->addr_img, 0, 0);
	return (0);
}

static void		reset(int keycode, t_menu *menu)
{
	t_env *env;

	env = menu->env;
	if (keycode == KEY_R)
		env->reset ? reset_scene(menu, env->reset) : reset_menu(menu);
	if (keycode == KEY_S && env->etat)
		ft_bitmap(env->image, env->reset);
	if (keycode == KEY_Q && env->etat)
	{
		env->sepia = !env->sepia ? 1 : 0;
		set_sepia(env, env->image);
	}
}

int				key_press(int key, t_menu *menu)
{
	t_env		*env;

	env = menu->env;
	if ((key == KEY_PAD_SUB || key == KEY_PAD_ADD) && env->etat)
	{
		if ((env->k > 0.1) && (key == KEY_PAD_SUB))
			env->k -= 0.1;
		else
			env->k += 0.1;
		env->tab_env = init_data_tab_thread((void*)env, sizeof(t_env), 8);
		thread(env->tab_thread, raytracing, env->tab_env, sizeof(t_env));
		mlx_put_image_to_window(
			env->addr_mlx, env->addr_win, env->image->addr_img, 0, 0);
	}
	if ((key == KEY_ESC) && (env->etat))
		end_scene(menu, env->addr_mlx, env->addr_win);
	else if ((key == KEY_ESC) && !(env->etat))
		end_menu(menu, menu->addr_mlx, menu->addr_win, menu->page->addr_img);
	if ((key == KEY_OPEN_BRACKET || key == KEY_CLOSE_BRACKET) && (env->etat))
		switch_cam(env, key);
	reset(key, menu);
	return (0);
}
