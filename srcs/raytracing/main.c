/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:38 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/22 17:12:31 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	init_env_values(t_env *env)
{
	env->camera = NULL;
	env->list = NULL;
	env->k = 0.2;
	env->nbr_cam = 0;
	env->lock = 0;
	env->fov = M_PI_4;
	env->scale = tan(M_PI_4 * 0.5);
	env->width = WIN_WIDTH;
	env->height = WIN_HEIGHT;
	env->select = (t_select*)malloc(sizeof(t_select));
	env->select->o = NULL;
	env->light = NULL;
	env->tab_ray = (t_ray*)malloc(sizeof(t_ray) * env->width * env->height);
	env->image_aspect_ratio = env->width / env->height;
	env->win = mlx_new_window(env->mlx, WIN_WIDTH, WIN_HEIGHT, "RTv1");
	env->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	env->data = mlx_get_data_addr(env->img,
			&(env->bpp), &(env->sizeline), &(env->endian));
	set_vec(&env->cursor, 0, 0, 0);
	init_tab_str_object(env);
	init_tab_function_object(env);
	init_tab_str_description(env);
	init_tab_function_description(env);
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
	return (parse_error(USAGE));
	if (!(env = (t_env*)malloc(sizeof(t_env))))
	error(env, "error malloc in main");
	env->mlx = mlx_init();
	init_env_values(env);
	if ((env->fd = open(av[1], O_RDWR)) == -1)
	error(env, INVALID_FILE);
	if (!parser(env))
	end_program(env);
	if (!env->camera)
	init_default_camera(env);
	else
	sort_camera(env);
	init_thread(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_hook(env->win, 2, 1L << 0 | 1 << 1, &key_press, env);
	mlx_hook(env->win, 17, 0L, &red_cross, env);
	mlx_loop(env->mlx);
	return (0);
}
