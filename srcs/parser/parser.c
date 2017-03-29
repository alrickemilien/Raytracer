/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:19 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/29 17:05:50 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_object(t_env *env, char *line)
{
	int		i;
	char	*crochet;

	i = -1;
	while (++i < NBR_OBJECT)
		if (!ft_strcmp(line, env->tab_str_object[i]))
			break ;
	if (i == NBR_OBJECT)
		return (parse_error(INVALID_FORMAT_FILE));
	get_next_line(env->fd, &crochet);
	recycle(&crochet, ft_strtrim(crochet));
	if (ft_strcmp("{", crochet))
	{
		ft_strdel(&crochet);
		return (parse_error(INVALID_FORMAT_FILE));
	}
	if (!env->set_object[i](env, &env->list))
		return (clean_error(&crochet));
	ft_strdel(&crochet);
	return (1);
}

int		parser(t_env *env)
{
	char	*line;

	line = 0;
	while (get_next_line(env->fd, &line))
	{
		ft_putendl(line);
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, ""))
			if (!check_object(env, line))
				return (clean_error(&line));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}
