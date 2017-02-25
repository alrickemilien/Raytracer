/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:09 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/25 13:22:33 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static t_obj		set_default_cone(t_env *env)
{
	t_obj			new_cone;

	set_vec(&new_cone.axis, 0, 0, 1);
	set_vec(&new_cone.apex, 0, 0, 1);
	new_cone.angle = M_PI / 4;
	new_cone.angle = tan(new_cone.angle / 2) * tan(new_cone.angle / 2);
	set_vec(&new_cone.rotation, 0, 0, 0);
	new_cone.color = split_color(mlx_get_color_value(env->mlx, 0x00FF0000));
	new_cone.brillance = 50;
	new_cone.diffuse = 0.5;
	new_cone.specular = 0.5;
	new_cone.etat = CONE;
	new_cone.func_obj = &cone;
	new_cone.reflection = 0;
	new_cone.refraction = 1;
	new_cone.transparent = 0;
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
			|| reference.reflection > 1 || reference.transparent > 1)
		return (parse_error(INVALID_OBJECT));
	if (reference.normal || reference.position || reference.to
			|| reference.from || reference.rayon || reference.size)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

static void			join_cone(t_env *env, t_obj cone)
{
	t_obj	obj;

	obj.r = 0.00105;
	obj.etat = CYLINDRE;
	obj.color = cone.color;
	obj.apex = cone.apex;
	obj.axis = cone.axis;
	obj.specular = cone.specular;
	obj.diffuse = cone.diffuse;
	obj.rotation = cone.rotation;
	obj.brillance = cone.brillance;
	obj.func_obj = &cylindre;
	ft_lstadd(&env->list, ft_lstnew(&obj, (sizeof(t_obj))));
}

int					set_cone(t_env *env)
{
	t_obj			new_cone;
	char			*line;
	t_pars_object	reference;

	new_cone = set_default_cone(env);
	ft_bzero(&reference, sizeof(reference));
	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		if (!ft_strcmp(line, ""))
			break ;
		if (!check_indent(line, 1))
			return (parse_error(BAD_INDENT));
		recycle(&line, ft_strtrim(line));
		if (!check_cone(env, &new_cone, line, &reference))
			return (0);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	rotate_object(&new_cone, &new_cone.axis);
	ft_lstadd(&env->list, ft_lstnew(&new_cone, (sizeof(t_obj))));
	if (!check_reference(reference))
		return (0);
	join_cone(env, new_cone);
	return (1);
}
