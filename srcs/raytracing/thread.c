/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:52:08 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/06 14:05:35 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_limit		ft_limit_thread(int nb)
{
	t_limit		lim;
	int			modulo_y;
	int			modulo_x;

	modulo_x = nb ;
	modulo_y = nb ;
	lim.x = 0;
	lim.tmp_x = ((WIN_WIDTH * modulo_x)) - 1;
	lim.y = (WIN_HEIGHT * modulo_y) - 1;
	lim.max_x = (WIN_WIDTH * (modulo_x + 1)) ;
	lim.max_y = (WIN_HEIGHT * (modulo_y + 1)) ;
	return (lim);
}

void		init_thread(t_env env)
{
	pthread_t	*t;
	int			nb_t;
	int			nb;
	t_env		*tmp;

	nb_t = 1;
	nb = -1;
	if (!(t = (pthread_t*)malloc(sizeof(pthread_t) * nb_t)))
		merror();
	if (!(tmp = (t_env*)malloc(sizeof(t_env) * nb_t)))
		merror();
	while (++nb < nb_t)
	{
		tmp[nb] = env;
		tmp[nb].nb_t = nb;
		pthread_create(&t[nb], NULL, &raytracing, &tmp[nb]);
	}
	nb = -1;
	while (++nb < nb_t)
		pthread_join(t[nb], NULL);
	ft_memdel((void**)&t);
	ft_memdel((void**)&tmp);
}
