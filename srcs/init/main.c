/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:38 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/23 16:21:29 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	*void_dup_tab_thread(const char *params, size_t size, int nb_thread)
{
	char *tab;
	int nb;
	char *data_nb;
	size_t index;
	size_t tmp;

	nb = -1;
	if (!(tab = (char*)ft_memalloc(size * nb_thread)))
		merror();
	while (++nb < nb_thread)
	{
		tmp = size * nb;
		index = -1;
		data_nb = (char*)(&nb);		
		while (++index < 5)
			tab[index + tmp] = data_nb[index];
		--index;
		while (++index < size)
			tab[index + tmp] = params[index];
	}
	return (tab);
}



int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
	return (parse_error(USAGE));
	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		error(env, "error malloc in main");
	env->addr_mlx = mlx_init();
	init_env_values(env);
	if ((env->fd = open(av[1], O_RDWR)) == -1)
		error(env, INVALID_FILE);
	if (!parser(env))
		end_program(env);
	if (!env->camera)
		init_default_camera(env);
	else
		sort_camera(env);
	env->tab_env = void_dup_tab_thread((void*)(env), sizeof(t_env), NB_THREAD);
	thread(env->tab_thread, &raytracing, env->tab_env, sizeof(t_env));
	mlx_put_image_to_window(env->addr_mlx, env->addr_win, env->image->image, 0, 0);
	mlx_hook(env->addr_win, 2, 1L << 0 | 1 << 1, &key_press, env);
	mlx_hook(env->addr_win, 17, 0L, &red_cross, env);
	mlx_loop(env->addr_mlx);
	return (0);
}
