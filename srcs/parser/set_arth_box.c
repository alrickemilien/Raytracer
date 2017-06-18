/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arth_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:05:27 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:05:28 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "rtv1.h"

static t_vector	good_get_vec(int local, t_obj obj)
{
	t_vector	new;

	if (local == 0 || local == 1)
	{
		new = get_vec(obj.size, 0, 0);
		rotate_object(&obj, &new);
		if (local == 1)
			negative_vec(&new);
	}
	else if (local == 2 || local == 3)
	{
		new = get_vec(0, obj.size, 0);
		rotate_object(&obj, &new);
		if (local == 3)
			negative_vec(&new);
	}
	else
	{
		new = get_vec(0, 0, obj.size);
		rotate_object(&obj, &new);
		if (local == 5)
			negative_vec(&new);
	}
	return (new);
}

void			set_boxs_plans(t_list **list, t_obj obj)
{
	t_obj		face_box;
	int			i;
	t_vector	xyz;

	i = -1;
	while (++i < 6)
	{
		ft_bzero(&face_box, sizeof(t_obj));
		face_box = obj;
		face_box.etat = PLAN;
		face_box.func_obj = &plan;
		xyz = good_get_vec(i, obj);
		face_box.pos = vec_add(vec_add(obj.pos, obj.translation), xyz);
		face_box.n = xyz;
		normalize_vec(&face_box.n);
		ft_lstadd(list, ft_lstnew(&face_box, sizeof(t_obj)));
	}
}
