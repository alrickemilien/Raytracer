/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_refraction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:06:22 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:06:23 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		set_refraction(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->refraction++;
	if (!fill_data(tmp, &new->refraction))
	{
		ft_strdel(&tmp);
		return (0);
	}
	if (new->refraction < 0)
		return (parse_error(BAD_COEFF));
	return (1);
}
