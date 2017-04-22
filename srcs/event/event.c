#include "rtv1.h"
#include "parser.h"
#include "init.h"

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

int				key_press(int keycode, t_menu *menu)
{
	t_env		*env;

	env = menu->env;
	if ((keycode == KEY_PAD_SUB || keycode == KEY_PAD_ADD) && env->etat)
	{
		if ((env->k > 0.1) && (keycode == KEY_PAD_SUB))
			env->k -= 0.1;
		else
			env->k += 0.1;
		free(env->tab_env);
		env->tab_env = init_data_tab_thread((void*)env, sizeof(t_env), 8);
		thread(env->tab_thread, raytracing, env->tab_env, sizeof(t_env));
		mlx_put_image_to_window(
			env->addr_mlx, env->addr_win, env->image->addr_img, 0, 0);
	}
	if ((keycode == KEY_ESC) && (env->etat))
		end_scene(menu, env->addr_mlx, env->addr_win);
	else if ((keycode == KEY_ESC) && !(env->etat))
		end_menu(menu, menu->addr_mlx, menu->addr_win, menu->page->addr_img);
	if ((keycode == KEY_OPEN_BRACKET || keycode == KEY_CLOSE_BRACKET)
		&& (env->etat))
		switch_cam(env, keycode);
	if ((env->select->o || env->select->c) && (env->etat))
		ft_put_pos_select(env);
	return (0);
}
