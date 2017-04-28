/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:32 by aemilien          #+#    #+#             */
/*   Updated: 2017/04/28 14:58:11 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


static int			check_reference(t_pars_scene index)
{
	if (index.k > 1)
		return (parse_error(INVALID_OBJECT));
	if (index.msaa > 1)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

static void			set_default_scene(t_env *env)
{
	env->k = 0.1;
	env->msaa = 0;
}

static int			check_scene(t_env *env, char *tmp, t_pars_scene *index)
{
	int				n;

	if (!ft_strncmp(AMBIENT, tmp, (n = ft_strlen(AMBIENT))))
	{
		if ((!fill_data(tmp + n, &env->k)) && !(index->k)++)
			return (parse_error(INVALID_PARAM_FORMAT));
		return (1);
	}
	if (!ft_strncmp(MSAA, tmp, (n = ft_strlen(MSAA))))
	{
		if (!set_msaa(tmp + n, env, index))
			return (parse_error(INVALID_PARAM_FORMAT));
		return (1);
	}
	else
		return (0);
}

int					set_scene(t_env *env, t_list **list_obj)
{
	char			*line;
	t_pars_scene	index;

	ft_bzero(&index, sizeof(t_pars_scene));
	(void)list_obj;
	set_default_scene(env);
	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_scene(env, line, &index))
				return (clean_error(&line));
		if (line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(index))
		return (0);
	return (1);
}
