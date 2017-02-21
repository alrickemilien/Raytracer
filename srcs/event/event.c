/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:44:44 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:44:45 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void			ft_put_pos_select(t_env *env)
{
	char		*str;

	str = NULL;
	if (env->select->c)
	{
		recycle(&str, ft_itoa((env->select->c->num) + 1));
		mlx_string_put(env->mlx, env->win, 45, 50, B, str);
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
	init_thread(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int				red_cross(void *param)
{
	t_env		*env;

	env = (t_env*)param;
	end_program(env);
	return (0);
}

int				key_press(int keycode, t_env *env)
{
	t_list		*list;

	list = env->list;
	if (keycode == KEY_PAD_SUB || keycode == KEY_PAD_ADD)
	{
		if ((env->k > 0.1) && (keycode == KEY_PAD_SUB))
			env->k -= 0.1;
		else
			env->k += 0.1;
		init_thread(*env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	}
	if (keycode == KEY_ESC)
		end_program(env);
	if (keycode == KEY_OPEN_BRACKET || keycode == KEY_CLOSE_BRACKET)
		switch_cam(env, keycode);
	if (env->select->o || env->select->c)
		ft_put_pos_select(env);
	return (0);
}
