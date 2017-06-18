/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:05:20 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:05:21 by lvalenti         ###   ########.fr       */
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
	if (!get_next_line(env->fd, &crochet))
		return (0);
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

int			parser(t_env *env)
{
	char	*line;
	int		error;

	line = 0;
	error = 0;
	while (get_next_line(env->fd, &line))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, ""))
			if (!check_object(env, line))
			{
				error = 1;
				break ;
			}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	while (get_next_line(env->fd, &line))
		ft_strdel(&line);
	if (error)
		return (0);
	return (1);
}
