/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reflection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:06:17 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:06:19 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		set_reflection(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->reflection++;
	if (!fill_data(tmp, &new->reflection))
		return (0);
	if (new->reflection < 0 || new->reflection > 1)
		return (parse_error(BAD_COEFF));
	return (1);
}
