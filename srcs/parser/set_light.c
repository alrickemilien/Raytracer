/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:32 by aemilien          #+#    #+#             */
/*   Updated: 2017/04/27 09:15:50 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "vector.h"
#include "rtv1.h"

static int			check_reference(t_pars_object reference, int light_type)
{
	if (reference.position > 1 || reference.intensity > 1
		|| reference.specular > 1 || reference.diffuse > 1
		|| reference.type > 1 || reference.angle > 1 || reference.axis > 1)
		return (parse_error(INVALID_OBJECT));
	if (light_type == SPHERICAL_LIGHT && (reference.angle || reference.axis))
		return (parse_error(INVALID_OBJECT));
	if (reference.normal || reference.apex 
		|| reference.from || reference.to
		|| reference.rayon || reference.brillance 
		|| reference.rotation || reference.reflection 
		|| reference.transparent)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

static void			set_default_light(t_light *new)
{
	set_vec(&new->org, 0, 0, 3);
	set_vec(&new->axis, 0, 0, -1);
	new->intensity = 5.5;
	new->specular = 0.5;
	new->diffuse = 0.5;
	new->shining = 0;
	new->type = SPHERICAL_LIGHT;
	new->angle = M_PI_4 / 2;
	new->hit_light = &hit_light;
}

static int			check_light(t_light *new, char *tmp, t_pars_object *index)
{
	int				n;
	int				t;

	t = 1;
	if ((!ft_strncmp(POSITION, tmp, (n = ft_strlen(POSITION))))
			&& fill_data_vec(tmp + n, &new->org))
		t = 0;
	if ((!ft_strncmp(INTENSITY, tmp, (n = ft_strlen(INTENSITY))))
			&& fill_data(tmp + n, &new->intensity))
		t = 0;
	if ((!ft_strncmp(TYPE, tmp, (n = ft_strlen(TYPE))))
			&& set_type_light(tmp + n, new, index))
		t = 0;
	if ((!ft_strncmp(ANGLE, tmp, (n = ft_strlen(ANGLE))))
			&& fill_data(tmp + n, &new->angle))
		t = 0;
	if ((!ft_strncmp(AXIS, tmp, (n = ft_strlen(AXIS))))
			&& fill_data_vec(tmp + n, &new->axis))
		t = 0;
	if ((!ft_strncmp(SHINING, tmp, (n = ft_strlen(SHINING))))
			&& set_shining(tmp + n, new, index))
		t = 0;
	if (!t)
		return (1);
	return (parse_error(INVALID_DESCRIPTION));
}

int					set_light(t_env *env, t_list **list_obj)
{
	t_light			new_light;
	char			*line;
	t_pars_object	reference;

	(void)list_obj;
	set_default_light(&new_light);
	ft_bzero(&reference, sizeof(reference));
	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		ft_putendl(line);
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_light(&new_light, line, &reference))
				return (clean_error(&line));
		if(line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(reference, new_light.type))
		return (0);
	if (new_light.diffuse + new_light.specular > 1)
		return (parse_error(INVALID_LIGHT));
	ft_lstadd(&env->light, ft_lstnew(&new_light, sizeof(t_light)));
	return (1);
}
