/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:03 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/02 11:51:48 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "vector.h"

static int		sort_camera(t_env *env)
{
	t_camera	*cam;
	t_list		*tmp_cam;
	int			i;

	i = 0;
	tmp_cam = env->camera;
	cam = (t_camera*)(tmp_cam->content);
	cam->num = 0;
	env->select->c = cam;
	tmp_cam = tmp_cam->next;
	while (tmp_cam)
	{
		cam = (t_camera*)(tmp_cam->content);
		cam->num = ++i;
		tmp_cam = tmp_cam->next;
	}
	env->nbr_cam = cam->num;
	return (1);
}

int				init_default_camera(t_env *env)
{
	t_camera	*new;
	t_obj		*obj;

	if (!env->list)
		parse_error(INVALID_NO_OBJ);
	if (env->camera)
		return (sort_camera(env));
	obj = ((t_obj*)(env->list->content));
	if (!(new = (t_camera*)malloc(sizeof(t_camera))))
		parse_error("malloc error") ;
	set_vec(&new->pos, obj->pos.x + 5, obj->pos.y + 5, obj->pos.z + 5);
	set_vec(&new->to, obj->pos.x, obj->pos.y, obj->pos.z);
	new->num = 0;
	env->nbr_cam = 0;
	set_camera_data(new);
	env->select->c = new;
	return (1);
}
