/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_box.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:47 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/29 15:24:34 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "vector.h"
#include "rtv1.h"

static void			set_boxs_plans(t_list **list, t_obj obj)
{
	t_obj	plan_tab[6];
	int		i;
	t_vector	new_x;
	t_vector	new_y;
	t_vector		new_z;

	i = -1;
	while (++i < 6)
	{
		plan_tab[i] = obj;
		plan_tab[i].etat = PLAN;
		plan_tab[i].func_obj = &plan;
		plan_tab[i].csg = NULL;
		plan_tab[i].texture = NULL;
	}
	new_x = get_vec(obj.size, 0, 0);
	new_y = get_vec(0, obj.size, 0);
	new_z = get_vec(0, 0, obj.size);

	rotate_object(&obj, &new_x);
	rotate_object(&obj, &new_y);
	rotate_object(&obj, &new_z);

	plan_tab[0].pos = vec_add(vec_add(obj.pos, obj.translation), new_z);
	plan_tab[0].n = new_z;
	normalize_vec(&plan_tab[0].n);

	negative_vec(&new_z);
	plan_tab[1].pos = vec_add(vec_add(obj.pos, obj.translation), new_z);
	plan_tab[1].n = new_z;
	normalize_vec(&plan_tab[0].n);

	plan_tab[2].pos = vec_add(vec_add(obj.pos, obj.translation), new_y);
	plan_tab[2].n = new_y;
	normalize_vec(&plan_tab[2].n);

	negative_vec(&new_y);
	plan_tab[3].pos = vec_add(vec_add(obj.pos, obj.translation), new_y);
	plan_tab[3].n = new_y;
	normalize_vec(&plan_tab[3].n);

	plan_tab[4].pos = vec_add(vec_add(obj.pos, obj.translation), new_x);
	plan_tab[4].n = new_x;
	normalize_vec(&plan_tab[4].n);

	negative_vec(&new_x);
	plan_tab[5].pos = vec_add(vec_add(obj.pos, obj.translation), new_x);
	plan_tab[5].n = new_x;
	normalize_vec(&plan_tab[5].n);
	i = -1;
	while (++i < 6)
		ft_lstadd(list, ft_lstnew(&plan_tab[i], sizeof(t_obj)));
}
void	set_bounds(t_obj *obj)
{
	double	size;

	size = obj->size;
	obj->bounds[0] = get_vec(-size, -size, -size); // min
	obj->bounds[1] = get_vec(size, size, size); // max
}

static t_obj		set_default_box(t_env *env)
{
	t_obj			obj;

	ft_bzero(&obj, (sizeof(t_obj)));
	set_vec(&obj.translation, 0, 0, 0);
	set_vec(&obj.rotation, 0, 0, 0);
	obj.color = split_color(mlx_get_color_value(env->addr_mlx, 0x00FF0000));
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
	double			m[16];

	ft_bzero(m, sizeof(double) * 16);
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
	box.matrix = invert_matrix(set_rotation_matrix(m, box.rotation.x,
									box.rotation.y, box.rotation.z));
	ft_lstadd(list_obj, ft_lstnew(&box, (sizeof(t_obj))));
	return (1);
}
