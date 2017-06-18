/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:54:08 by salibert          #+#    #+#             */
/*   Updated: 2017/05/06 09:43:20 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "menu.h"
#include <stdio.h>

int				red_cross(t_menu *menu)
{
	t_env		*env;

	env = menu->env;
	if (env->etat)
		end_scene(menu, env->addr_mlx, env->addr_win);
	else
		end_menu(menu, menu->addr_mlx, menu->addr_win, menu->page->addr_img);
	return (0);
}

static void		scroll_menu(int clic, t_menu *menu)
{
	int			size_scroll;
	int			size_y;

	size_y = menu->page->height;
	size_scroll = 50;
	if (clic == 4)
	{
		if (menu->y_scroll + size_scroll < 0)
			mlx_put_image_to_window(menu->addr_mlx, menu->addr_win,
			menu->page->addr_img, 0, menu->y_scroll += size_scroll);
	}
	else if (clic == 5)
	{
		if (menu->y_scroll - size_scroll >= -(size_y - 1000))
			mlx_put_image_to_window(menu->addr_mlx, menu->addr_win,
			menu->page->addr_img, 0, menu->y_scroll -= size_scroll);
	}
}

static void		select_scene(int x, int y, t_menu *menu)
{
	t_list		*button;
	t_data_draw	*data;
	t_env		*env;

	button = menu->button->next;
	env = menu->env;
	while (button)
	{
		data = (t_data_draw*)(button->content);
		if (data->tmp_x <= x && data->limit_x >= x
		&& (data->tmp_y + menu->y_scroll) <= y
		&& (data->limit_y + menu->y_scroll) >= y
		&& !env->etat)
		{
			env->etat = 1;
			env->reset = data->path;
			init_scene(menu, data->path);
			break ;
		}
		button = button->next;
	}
}

static void		build_scene(int x, int y, t_menu *menu)
{
	t_list		*button;
	t_data_draw	*data;
	char		*tmp;

	button = menu->button->next;
	while (button)
	{
		data = (t_data_draw*)(button->content);
		if (data->tmp_x <= x && data->limit_x >= x
		&& (data->tmp_y + menu->y_scroll) <= y
		&& (data->limit_y + menu->y_scroll) >= y)
		{
			tmp = ft_strjoin("atom ", data->path);
			if(system(tmp) < 0)
				return ;
			ft_strdel(&tmp);
			break ;
		}
		button = button->next;
	}
}

int				ft_mouse(int clic, int x, int y, t_menu *menu)
{
	if (clic == 4 || clic == 5)
		scroll_menu(clic, menu);
	if (clic == 1)
		select_scene(x, y, menu);
	if (clic == 2)
		build_scene(x, y, menu);
	return (1);
}
