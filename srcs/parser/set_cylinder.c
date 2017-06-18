/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:05:54 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:05:55 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "vector.h"
#include "rtv1.h"

static t_obj		set_default_cylinder(t_env *env)
{
	t_obj			new;

	ft_bzero(&new, (sizeof(t_obj)));
	set_vec(&new.axis, 0, 0, 1);
	set_vec(&new.apex, 0, 0, 1);
	set_vec(&new.rot, 0, 0, 0);
	set_vec(&new.translation, 0, 0, 0);
	new.r = 1;
	new.size = 2000000;
	new.color = split_color(mlx_get_color_value(env->addr_mlx, 0x00FF3421));
	new.brillance = 10;
	new.specular = 1;
	new.diffuse = 1;
	new.etat = CYLINDRE;
	new.func_obj = &cylindre;
	new.refraction = 1;
	return (new);
}

static int			check_cylinder(t_env *env, t_obj *new,
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

static void			set_limits(t_obj *obj)
{
	t_obj	le_plan;

	if (obj->size == 2000000)
		return ;
	le_plan = *obj;
	le_plan.csg = NULL;
	le_plan.etat = PLAN;
	le_plan.n = obj->axis;
	le_plan.pos = vec_add(obj->pos, n_vec(obj->axis, obj->size));
	ft_lstadd(&obj->csg, ft_lstnew(&le_plan, sizeof(t_obj)));
	negative_vec(&le_plan.n);
	le_plan.pos = vec_add(obj->pos, n_vec(obj->axis, -obj->size));
	ft_lstadd(&obj->csg, ft_lstnew(&le_plan, sizeof(t_obj)));
}

static int			check_reference(t_pars_object reference)
{
	if (reference.apex > 1 || reference.axis > 1 || reference.color > 1
			|| reference.rayon > 1 || reference.brillance > 1
			|| reference.rot > 1 || reference.size > 1
			|| reference.specular > 1 || reference.diffuse > 1
			|| reference.reflection > 1 || reference.transparent > 1
			|| reference.translation > 1)
		return (parse_error(INVALID_OBJECT));
	if (reference.normal || reference.position
			|| reference.angle || reference.from
			|| reference.to || reference.type)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

int					set_cylinder(t_env *env, t_list **list_obj)
{
	t_obj			new_cylinder;
	char			*line;
	t_pars_object	reference;

	new_cylinder = set_default_cylinder(env);
	ft_bzero(&reference, sizeof(reference));
	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_cylinder(env, &new_cylinder, line, &reference))
				return (clean_error(&line));
		if (line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(reference))
		return (parse_error(INVALID_OBJECT));
	rotate_object(&new_cylinder, &new_cylinder.axis);
	new_cylinder.apex = vec_add(new_cylinder.apex, new_cylinder.translation);
	set_limits(&new_cylinder);
	ft_lstadd(list_obj, ft_lstnew(&new_cylinder, sizeof(t_obj)));
	return (1);
}
