/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_nbr_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:46:47 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/27 18:01:20 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/rtv1.h"

int				check_floating_number(char *str)
{
	int			i;
	int			j;

	i = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(str[i]))
		i++;
	if (i > 12)
		return (parse_error(INVALID_SIZE_NBR));
	j = 0;
	if (str[i] == '.')
	{
		while (ft_isdigit(str[++i]))
			j++;
		if (str[i] == '.')
			return (parse_error(INVALID_FORMA_NBR));
		if (i > 17)
			return (parse_error(INVALID_SIZE_NBR));
		if (j > 5)
			ft_putendl_fd(INVALID_DECIMAL, 2);
	}
	return (1);
}

static int		check_overflow(char *tmp)
{
	int			i;

	i = 0;
	if (tmp[i++] == '-')
	{
		if (ft_strcmp(tmp + i, "2147483648") < 0)
			return (0);
	}
	else if (ft_isdigit(tmp[i]) || tmp[i++] == '+')
	{
		if (ft_strcmp(tmp + i, "2147483647") < 0)
			return (0);
	}
	return (1);
}

static int		check_size(char *tmp)
{
	int			i;

	i = 0;
	if (tmp[i] == '+' || tmp[i] == '-')
		i++;
	while (tmp[i] && ft_isdigit(tmp[i]))
		i++;
	if (i < 10)
		return (i);
	if (i == 10)
		return (check_overflow(tmp));
	return (0);
}

int				check_number_int(char *str)
{
	int			i;

	i = 0;
	if (str[i] == '-')
		return (parse_error(INVALID_INT));
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '	')
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i++] == ')')
			break ;
	}
	if (!check_end_data(str + i))
		return (parse_error(INVALID_PARAM_FORMAT));
	if (!check_size(str))
		return (parse_error(INVALID_INT));
	return (1);
}

int				fill_int_data(char *str, int *data)
{
	while (*str == '	' || *str == ' ')
		str++;
	if (*str == '(' && !check_number_int(++str))
		return (0);
	while (*str == ' ' || *str == '\t')
		str++;
	*data = ft_trim(0, 4000, ft_atoi(str));
	return (1);
}
