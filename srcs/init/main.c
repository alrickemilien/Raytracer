#include "rtv1.h"
#include "init.h"
#include "parser.h"
#include "menu.h"

void			reset_scene(t_menu *menu, char *path)
{
	t_env		*env;

	env = menu->env;
	free_list(&env->list, &env->camera, &env->light, env);
	env->fd = open(path, O_RDWR);
	if (!parser(env) || !init_default_camera(env))
	{
		close(env->fd);
		env->etat = 0;
		free_list(&env->list, &env->camera, &env->light, env);
		return ;
	}
	env->tab_env = init_data_tab_thread((void*)env, (sizeof(t_env)), 8);
	thread(env->tab_thread, &raytracing, env->tab_env, sizeof(t_env));
	mlx_put_image_to_window(
			env->addr_mlx, env->addr_win, env->image->addr_img, 0, 0);
	mlx_hook(env->addr_win, 2, 1L << 0 | 1 << 1, &key_press, menu);
	mlx_hook(env->addr_win, 17, 0L, &red_cross, menu);
	mlx_loop(env->addr_mlx);
}

void			init_scene(t_menu *menu, char *path)
{
	t_env		*env;

	env = menu->env;
	free_list(&env->list, &env->camera, &env->light, env);
	env->fd = open(path, O_RDWR);
	if (!parser(env) || !init_default_camera(env))
	{
		close(env->fd);
		env->reset = NULL;
		env->etat = 0;
		free_list(&env->list, &env->camera, &env->light, env);
		return ;
	}
	env->addr_win = mlx_new_window(env->addr_mlx, WIN_WIDTH, WIN_HEIGHT, path);
	env->tab_env = init_data_tab_thread((void*)env, (sizeof(t_env)), 8);
	thread(env->tab_thread, &raytracing, env->tab_env, sizeof(t_env));
	mlx_put_image_to_window(
			env->addr_mlx, env->addr_win, env->image->addr_img, 0, 0);
	mlx_hook(env->addr_win, 2, 1L << 0 | 1 << 1, &key_press, menu);
	mlx_hook(env->addr_win, 17, 0L, &red_cross, menu);
	mlx_loop(env->addr_mlx);
}

void			loop_menu(t_menu *menu)
{
	t_env		*env;

	env = menu->env;
	if (!env->image)
		if (!(env->image = init_image(env->addr_mlx, WIN_WIDTH, WIN_HEIGHT)))
			parse_error("malloc_error");
	env->image_aspect_ratio = 1000 / 1000;
	if (!env->tab_thread)
		env->tab_thread = init_thread(8);
	env->nb_thread = 0;
	mlx_hook(menu->addr_win, 2, 1L << 0 | 1 << 1, &key_press, menu);
	mlx_mouse_hook(menu->addr_win, ft_mouse, menu);
	mlx_hook(menu->addr_win, 17, 0L, &red_cross, menu);
	mlx_loop(menu->addr_mlx);
}

int				main(void)
{
	t_menu		*menu;

	if (!(menu = creat_menu()))
		merror();
	if (!(menu->env = (t_env*)ft_memalloc(sizeof(t_env))))
		merror();
	init_env(menu->env);
	ray_draw_data(menu, menu->env);
	mlx_put_image_to_window(
			menu->addr_mlx, menu->addr_win, menu->page->addr_img, 0, 0);
	loop_menu(menu);
	return (0);
}
