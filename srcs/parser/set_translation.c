/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_translation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:06:47 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:06:48 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "vector.h"

int			set_translation(t_env *env, char *s, t_obj *new, t_pars_object *i)
{
	(void)env;
	i->translation++;
	if (fill_data_vec(s, &new->translation))
		return (1);
	return (0);
}

void		set_translation_csg(t_vector translation, t_list *csg)
{
	t_obj	*obj;

	if (!translation.x && !translation.y && !translation.z)
		return ;
	while (csg)
	{
		obj = (t_obj*)csg->content;
		if (obj->etat == CSG || obj->etat == BOX)
			set_translation_csg(translation, obj->csg);
		else if (obj->etat == CONE || obj->etat == CYLINDRE)
			obj->apex = vec_add(obj->apex, translation);
		else
			obj->pos = vec_add(obj->pos, translation);
		csg = csg->next;
	}
}
