/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:46 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/29 16:58:11 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int			check_camera(
		t_env *env, t_camera *new,
		char *tmp, t_pars_object *index)
{
	int				n;

	(void)env;
	if (!ft_strncmp(FROM, tmp, (n = ft_strlen(FROM))))
	{
		(index->from)++;
		if (!fill_data_vec(tmp + n, &new->pos))
			return (0);
	}
	else if (!ft_strncmp(TO, tmp, (n = ft_strlen(TO))))
	{
		(index->to)++;
		if (!fill_data_vec(tmp + n, &new->to))
			return (0);
	}
	else
		return (parse_error(INVALID_DESCRIPTION));
	return (1);
}

int					check_ref_camera(t_pars_object ref, t_camera new)
{
	if (ref.from > 1 || ref.to > 1 || ref.position || ref.brillance || ref.angle
			|| ref.rayon || ref.color || ref.apex || ref.axis || ref.normal
			|| ref.rotation || ref.intensity || ref.size || ref.diffuse
			|| ref.specular || ref.transparent || ref.translation)
		return (parse_error(INVALID_OBJECT));
	if (new.pos.x == new.to.x && new.pos.z == new.to.z && new.pos.y == new.to.y)
		return (parse_error(INVALID_CAMERA));
	return (1);
}

int					set_camera(t_env *env, t_list **list_obj)
{
	t_camera		new;
	char			*line;
	t_pars_object	reference;

	(void)list_obj;
	set_default_camera(&new);
	ft_bzero(&reference, sizeof(reference));
	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_camera(env, &new, line, &reference))
				return (clean_error(&line));
		if(line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!(check_ref_camera(reference, new)))
		return (0);
	set_camera_data(&new);
	ft_lstadd(&env->camera, ft_lstnew(&new, (sizeof(t_camera))));
	return (1);
}
