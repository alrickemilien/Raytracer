/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rayon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:59 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:49:01 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		set_rayon(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->rayon++;
	if (!fill_data(tmp, &new->r))
		return (0);
	if (new->r <= 0)
		return (0);
	return (1);
}
