/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:32 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/25 14:00:58 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int			check_reference(int k)
{
	if (k > 1)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

static void			set_default_scene(t_env *env)
{
	env->k = 0.1;
}

static int			check_scene(t_env *env, char *tmp, int *k)
{
	int				n;

	if (!ft_strncmp(AMBIENT, tmp, (n = ft_strlen(AMBIENT))))
	{
		if ((!fill_data(tmp + n, &env->k)) && !(k)++)
			return (parse_error(INVALID_PARAM_FORMAT));
		return (1);
	}
	else
		return (0);
}

int					set_scene(t_env *env, t_list **list_obj)
{
	char			*line;
	int				k;

	k = 0;
	(void)list_obj;
	set_default_scene(env);
	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_scene(env, line, &k))
				return (0);
		if(line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(k))
		return (0);
	return (1);
}
