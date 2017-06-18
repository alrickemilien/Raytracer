/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_perturbation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:06:08 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:06:09 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parser.h"

static void	del_tab(char **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
}

static int	check_perturbation(t_obj *new, char *tmp)
{
	char	*tab[2];
	int		i;
	int		n;

	i = 0;
	tab[SIN] = ft_strdup("sinus");
	tab[TAN] = ft_strdup("tangeante");
	while (i < 2)
	{
		if (!ft_strncmp(tmp, tab[i], (n = ft_strlen(tab[i]))))
			break ;
		i++;
	}
	if (i == 2)
		return (parse_error(INVALID_PARAM_FORMAT));
	new->perturbation = i;
	del_tab(tab, 2);
	return (n);
}

int			set_perturbation(t_env *env, char *s, t_obj *new, t_pars_object *i)
{
	int		n;

	(void)env;
	i->perturbation++;
	while (*s == ' ' || *s == '\t')
		s++;
	if (*(s++) != '(')
		return (parse_error(INVALID_PARAM_FORMAT));
	while (*s == ' ' || *s == '\t')
		s++;
	if (!(n = check_perturbation(new, s)))
		return (0);
	s += n;
	while (ft_isalpha(*s))
		s++;
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s != ')')
		return (parse_error(INVALID_PARAM_FORMAT));
	if (!check_end_data(s + 1))
		return (parse_error(INVALID_PARAM_FORMAT));
	return (1);
}
