/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:19 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:50:37 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		parser(t_env *env)
{
	char	*line;
	int		i;

	line = 0;
	while (get_next_line(env->fd, &line))
	{
		if (!check_indent(line, 0))
			return (parse_error(BAD_INDENT));
		recycle(&line, ft_strtrim(line));
		i = -1;
		while (++i < 6)
			if (!ft_strcmp(line, env->tab_str_object[i]))
				break ;
		if (ft_strcmp(line, ""))
		{
			if (i == 6)
				return (parse_error(INVALID_FORMAT_FILE));
			if (!env->set_object[i](env))
				return (0);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}
