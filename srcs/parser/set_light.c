/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:32 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:48:33 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int			check_reference(t_pars_object reference)
{
	if (reference.position > 1 || reference.intensity > 1
		|| reference.specular > 1 || reference.diffuse > 1)
		return (parse_error(INVALID_OBJECT));
	if (reference.normal || reference.apex || reference.axis
		|| reference.angle || reference.from || reference.to
		|| reference.rayon || reference.brillance || reference.rotation)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

static void			set_default_light(t_light *new)
{
	set_vec(&new->org, 0, 0, 1);
	new->intensity = 5.5;
	new->specular = 0.5;
	new->diffuse = 0.5;
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
	else
		return (parse_error(INVALID_DESCRIPTION));
	return (1);
}

int					set_light(t_env *env)
{
	t_light			new_light;
	char			*line;
	t_pars_object	reference;

	set_default_light(&new_light);
	ft_bzero(&reference, sizeof(reference));
	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		if (!ft_strcmp(line, ""))
			break ;
		if (!check_indent(line, 1))
			return (parse_error(BAD_INDENT));
		recycle(&line, ft_strtrim(line));
		if (!check_light(&new_light, line, &reference))
			return (0);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(reference))
		return (0);
	if (new_light.diffuse + new_light.specular > 1)
		return (parse_error(INVALID_LIGHT));
	ft_lstadd(&env->light, ft_lstnew(&new_light, (sizeof(t_light))));
	return (1);
}
