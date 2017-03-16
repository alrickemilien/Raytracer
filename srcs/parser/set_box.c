/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:47 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/15 14:08:08 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void			set_boxs_plans(t_list **list, t_obj obj)
{
	t_obj	plan_tab[6];
	int		i;

	i = -1;
	while (++i < 6)
	{
		plan_tab[i] = obj;
		plan_tab[i].etat = PLAN;
		plan_tab[i].func_obj = &plan;
		plan_tab[i].csg = NULL;
	}
	plan_tab[0].pos = vec_add(vec_add(obj.pos, obj.translation), get_vec(0, 0, obj.size));
	set_vec(&plan_tab[0].n, 0, 0, 1);
	plan_tab[1].pos = vec_add(vec_add(obj.pos, obj.translation), get_vec(0, 0, -obj.size));
	set_vec(&plan_tab[1].n, 0, 0, -1);
	plan_tab[2].pos = vec_add(vec_add(obj.pos, obj.translation), get_vec(0, obj.size, 0));
	set_vec(&plan_tab[2].n, 0, 1, 0);
	plan_tab[3].pos = vec_add(vec_add(obj.pos, obj.translation), get_vec(0, -obj.size, 0));
	set_vec(&plan_tab[3].n, 0, -1, 0);
	plan_tab[4].pos = vec_add(vec_add(obj.pos, obj.translation), get_vec(obj.size, 0, 0));
	set_vec(&plan_tab[4].n, 1, 0, 0);
	plan_tab[5].pos = vec_add(vec_add(obj.pos, obj.translation), get_vec(-obj.size, 0, 0));
	set_vec(&plan_tab[5].n, -1, 0, 0);
	i = -1;
	while (++i < 6)
	{
		rotate_object(&plan_tab[i], &plan_tab[i].n);
		ft_lstadd(list, ft_lstnew(&plan_tab[i], sizeof(t_obj)));
	}
}
void	set_bounds(t_obj *obj)
{
	double	size;

	size = obj->size;
	obj->bounds[0] = vec_add(vec_add(obj->pos, obj->translation), get_vec(-size, -size, -size)); // min
	rotate_object(obj, &obj->bounds[0]);
	obj->bounds[1] = vec_add(vec_add(obj->pos, obj->translation), get_vec(size, size, size)); // max
	rotate_object(obj, &obj->bounds[1]);
}

static t_obj		set_default_box(t_env *env)
{
	t_obj			obj;

	set_vec(&obj.translation, 0, 0, 0);
	set_vec(&obj.rotation, 0, 0, 0);
	obj.color = split_color(mlx_get_color_value(env->mlx, 0x00FFFFFF));
	obj.brillance = 10;
	obj.diffuse = 1;
	obj.specular = 1;
	obj.etat = BOX;
	obj.func_obj = &box;
	obj.reflection = 0;
	obj.refraction = 1;
	obj.transparent = 0;
	obj.csg = NULL;
	obj.size = 1;
	return (obj);
}

static int			check_box(t_env *env, t_obj *new,
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
	if (reference.position > 1 || reference.color > 1
			|| reference.brillance > 1 || reference.rotation > 1
			|| reference.specular > 1 || reference.diffuse > 1
			|| reference.reflection > 1 || reference.transparent > 1 
			|| reference.translation > 1)
		return (parse_error(INVALID_OBJECT));
	if (reference.axis || reference.apex || reference.rayon
			|| reference.angle || reference.to || reference.from 
			|| reference.type || reference.normal)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

int					set_box(t_env *env, t_list **list_obj)
{
	t_obj			box;
	char			*line;
	t_pars_object	reference;

	box = set_default_box(env);
	ft_bzero(&reference, sizeof(reference));
	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_box(env, &box, line, &reference))
				return (0);
		if(line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(reference))
		return (0);
	set_boxs_plans(&box.csg, box);
	set_bounds(&box);
	ft_lstadd(list_obj, ft_lstnew(&box, (sizeof(t_obj))));
	return (1);
}
