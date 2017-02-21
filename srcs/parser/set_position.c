/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:53 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:48:54 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		set_position(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->position++;
	if (!fill_data_vec(tmp, &new->pos))
		return (0);
	return (1);
}
