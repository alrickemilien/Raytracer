/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:32 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/31 10:25:04 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	new->type = SPHERICAL_LIGHT;
	new->angle = M_PI_2 - (M_PI_4 / 2);
	new->hit_light = &hit_light;
}

static int			check_light(t_light *new, char *tmp, t_pars_object *index)
{
	int				n;

	if (!ft_strncmp(POSITION, tmp, (n = ft_strlen(POSITION))))
	{
		if ((!fill_data_vec(tmp + n, &new->org)) && !(index->position)++)
			return (parse_error(INVALID_PARAM_FORMAT));
	}
	else if (!ft_strncmp(INTENSITY, tmp, (n = ft_strlen(INTENSITY))))
	{
		if ((!fill_data(tmp + n, &new->intensity)) && !(index->intensity)++)
			return (parse_error(INVALID_PARAM_FORMAT));
	}
	else if (!ft_strncmp(SPECULAR, tmp, (n = ft_strlen(SPECULAR))))
	{
		if ((!fill_data(tmp + n, &new->specular)) && !(index->specular)++)
			return (parse_error(INVALID_PARAM_FORMAT));
	}
	else if (!ft_strncmp(DIFFUSE, tmp, (n = ft_strlen(DIFFUSE))))
	{
		if ((!fill_data(tmp + n, &new->diffuse)) && !(index->diffuse)++)
			return (parse_error(INVALID_PARAM_FORMAT));
	}
	else if (!ft_strncmp(TYPE, tmp, (n = ft_strlen(TYPE))))
	{
		if (!set_type_light(tmp + n, new, index))
			return (parse_error(INVALID_PARAM_FORMAT));
	}
	else if (!ft_strncmp(ANGLE, tmp, (n = ft_strlen(ANGLE))))
	{
		if ((!fill_data(tmp + n, &new->angle)) && !(index->angle)++)
			return (parse_error(INVALID_PARAM_FORMAT));
	}
	else if (!ft_strncmp(AXIS, tmp, (n = ft_strlen(AXIS))))
	{
		if ((!fill_data_vec(tmp + n, &new->axis)) && !(index->axis)++)
			return (parse_error(INVALID_PARAM_FORMAT));
	}
	else
		return (parse_error(INVALID_DESCRIPTION));
	return (1);
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
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_light(&new_light, line, &reference))
				return (0);
		if(line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(reference, new_light.type))
		return (0);
	if (new_light.diffuse + new_light.specular > 1)
		return (parse_error(INVALID_LIGHT));
	ft_lstadd(&env->light, ft_lstnew(&new_light, (sizeof(t_light))));
	return (1);
}
