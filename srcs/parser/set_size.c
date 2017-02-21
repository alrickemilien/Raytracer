/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:49:15 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:49:17 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		set_size(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->size++;
	if (!fill_data(tmp, &new->size))
		return (0);
	return (1);
}
