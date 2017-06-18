/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:05:16 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:05:17 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_object(t_env *env, t_obj *obj,
						int (*check_object)(t_env *env, t_obj *obj,
								char *line, void *reference),
						void *reference)
{
	char	*line;

	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_object(env, obj, line, reference))
				return (clean_error(&line));
		if (line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	free(line);
	return (1);
}
