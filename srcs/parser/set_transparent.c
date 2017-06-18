/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transparent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:06:53 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:06:54 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			set_transparent(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index)
{
	(void)env;
	index->transparent++;
	if (!fill_data(tmp, &new->transparent))
		return (0);
	if (new->transparent < 0 || new->transparent > 1)
		return (parse_error(BAD_COEFF));
	new->transparent = new->transparent;
	return (1);
}
