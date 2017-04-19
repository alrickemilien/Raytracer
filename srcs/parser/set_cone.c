/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:09 by aemilien          #+#    #+#             */
/*   Updated: 2017/04/19 13:37:14 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static t_obj		set_default_cone(t_env *env)
{
	t_obj			new_cone;

	set_vec(&new_cone.axis, 0, 0, 1);
	set_vec(&new_cone.translation, 0, 0, 0);
	set_vec(&new_cone.apex, 0, 0, 1);
	new_cone.angle = M_PI / 4;
	new_cone.angle = tan(new_cone.angle / 2) * tan(new_cone.angle / 2);
	set_vec(&new_cone.rotation, 0, 0, 0);
	new_cone.color = split_color(mlx_get_color_value(env->addr_mlx, 0x00FF0000));
	new_cone.brillance = 50;
	new_cone.diffuse = 0.5;
	new_cone.specular = 0.5;
	new_cone.etat = CONE;
	new_cone.func_obj = &cone;
	new_cone.reflection = 0;
	new_cone.refraction = 1;
	new_cone.transparent = 0;
	new_cone.csg = NULL;
	new_cone.size = 20000;
	return (new_cone);
}

static int			check_cone(t_env *env, t_obj *new,
		char *tmp, t_pars_object *index)
{
	int				n;
	int				i;

	i = 0;
	while (i < NBR_DESCRIPTION)
	{
		if (!ft_strncmp(env->tab_str_description[i],
					tmp, (n = ft_strlen(env->tab_str_description[i]))))
			break ;
		i++;
	}
	if (i == NBR_DESCRIPTION)
		return (parse_error(INVALID_DESCRIPTION));
	if (!env->check_description[i](env, tmp + n, new, index))
		return (0);
	return (1);
}

static int			check_reference(t_pars_object reference)
{
	if (reference.apex > 1 || reference.axis > 1
			|| reference.color > 1 || reference.angle > 1
			|| reference.brillance > 1 || reference.rotation > 1
			|| reference.specular > 1 || reference.diffuse > 1
			|| reference.reflection > 1 || reference.transparent > 1
			|| reference.translation > 1 || reference.size > 1)
		return (parse_error(INVALID_OBJECT));
	if (reference.normal || reference.position || reference.to
		|| reference.from || reference.rayon || reference.type)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

static void			set_limits(t_obj *obj)
{
	t_obj	le_plan;

	if (obj->size == 2000000)
		return ;
	le_plan = *obj;;
	le_plan.csg = NULL;
	le_plan.etat = PLAN;
	le_plan.n = obj->axis;
	le_plan.pos = vec_add(obj->apex, n_vec(obj->axis, obj->size));
	ft_lstadd(&obj->csg, ft_lstnew(&le_plan, sizeof(t_obj)));
	negative_vec(&le_plan.n);
	le_plan.pos = vec_add(obj->apex, n_vec(obj->axis, -obj->size));
	ft_lstadd(&obj->csg, ft_lstnew(&le_plan, sizeof(t_obj)));
}

int					set_cone(t_env *env, t_list **list_obj)
{
	t_obj			new_cone;
	char			*line;
	t_pars_object	reference;

	new_cone = set_default_cone(env);
	ft_bzero(&reference, sizeof(reference));
	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_cone(env, &new_cone, line, &reference))
				return (0);
		if(line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(reference))
		return (0);
	rotate_object(&new_cone, &new_cone.axis);
	new_cone.apex = vec_add(new_cone.apex, new_cone.translation);
	set_limits(&new_cone);
	ft_lstadd(list_obj, ft_lstnew(&new_cone, sizeof(t_obj)));
	return (1);
}
