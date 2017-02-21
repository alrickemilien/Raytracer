/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_specular.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:49:22 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:49:23 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int			set_specular(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index)
{
	(void)env;
	index->specular++;
	if (!fill_data(tmp, &new->specular))
		return (0);
	if (new->specular < 0 || new->specular > 1)
		return (parse_error(BAD_COEFF));
	return (1);
}
