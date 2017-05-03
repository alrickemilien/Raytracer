/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:52:08 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/03 17:10:41 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun_struct.h"
#include <pthread.h>
#include <stdio.h>

static t_limit		ft_limit_thread(int nb, int width, int height)
{
	t_limit		lim;
	int			modulo_y;
	int			modulo_x;

	modulo_x = (nb % 8) / 2;
	modulo_y = (nb % 2);
	lim.tmp_x = ((width * modulo_x) / 4) - 1;
	lim.y = (height * modulo_y / 2) - 1;
	lim.max_x = (width * (modulo_x + 1)) / 4;
	lim.max_y = (height * (modulo_y + 1)) / 2;
	return (lim);
}

void	set_vignette_dimensions(t_env *e, t_limit *l)
{
	if (e->nb_thread == 9)
	{
		l->y = -1;
		l->max_y = 200;
		l->max_x = 400;
		l->tmp_x = -1;
	}
	else
		*l = ft_limit_thread(e->nb_thread, e->image->width, e->image->height);
}

void		thread(pthread_t *t, void *(*funct)(void*), void *params, int size)
{
	int		nb;

	nb = -1;
	while (++nb < 8)
		pthread_create(&t[nb], NULL, funct, &params[size * nb]);
	nb = -1;
	while (++nb < 8)
		pthread_join(t[nb], NULL);
}
