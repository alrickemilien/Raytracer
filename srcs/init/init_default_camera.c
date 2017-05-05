/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:03 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/05 14:47:56 by salibert         ###   ########.fr       */
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
	t_camera	new;
	t_obj		*obj;

	env->nbr_cam = 0;
	if (!env->list)
		return(parse_error(INVALID_NO_OBJ));
	if (env->camera)
		return (sort_camera(env));
	obj = ((t_obj*)(env->list->content));
	set_vec(&new.pos, obj->pos.x + 15, obj->pos.y + 15, obj->pos.z + 15);
	set_vec(&new.to, obj->pos.x, obj->pos.y, obj->pos.z);
	new.num = 0;
	set_camera_data(&new);
	ft_lstadd(&env->camera, ft_lstnew(&new, sizeof(t_camera)));
	env->select->c = ((t_camera*)(env->camera->content));
	return (1);
}
