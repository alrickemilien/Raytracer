/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:06:27 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:06:29 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		set_resize_texture(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index)
{
	(void)env;
	index->resize_texture++;
	if (!fill_data(tmp, &new->resize_texture))
		return (0);
	if (new->resize_texture < 0.1 || new->resize_texture > 1000)
		return (parse_error(INVALID_RESIZE_TEXTURE));
	return (1);
}
