/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:03 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/31 17:03:00 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "vector.h"

void	init_default_camera(t_env *env)
{
	t_camera	*new;
	t_obj		*obj;

	if (!env->list)
		merror();
	obj = ((t_obj*)(env->list->content));
	if (!(new = (t_camera*)malloc(sizeof(t_camera))))
		return ;
	set_vec(&new->pos, obj->pos.x + 5, obj->pos.y + 5, obj->pos.z + 5);
	set_vec(&new->to, obj->pos.x, obj->pos.y, obj->pos.z);
	new->num = 0;
	env->nbr_cam = 0;
	set_camera_data(new);
	env->select->c = new;
}
