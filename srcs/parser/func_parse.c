/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:46:59 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:47:00 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/rtv1.h"

int			check_data_type_color(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (str[i] != '0' && str[i + 1] != 'x')
		return (parse_error(INVALID_HEXA_FORMAT));
	i += 2;
	while (ft_isalpha(str[i]) || ft_isdigit(str[i]))
	{
		i++;
		k++;
	}
	if (k > 8 || k == 0)
		return (parse_error(INVALID_HEXA_SIZE));
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != ')')
		return (parse_error(INVALID_PARAM_FORMAT));
	if (str[i + 1])
		return (parse_error(INVALID_PARAM_FORMAT));
	return (1);
}

int			check_data_type_nbr(char *str, int k)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '	')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (ft_isdigit(str[i]) || str[i] == '.')
			k--;
		while (ft_isdigit(str[i]) || str[i] == '.')
			i++;
		if (str[i] != ')' && str[i] != ' ' && str[i] != '	')
			return (parse_error(INVALID_PARAM_FORMAT));
		if (str[i++] == ')')
			break ;
	}
	while (str[i] == ' ' || str[i] == '	')
		i++;
	if (str[i])
		return (parse_error(INVALID_PARAM_FORMAT));
	if (k)
		return (parse_error(INVALID_NBR_OF_PARAM));
	return (1);
}

int			fill_data_vec(char *str, t_vector *vec)
{
	double	tab[3];
	int		j;

	while (*str == '	' || *str == ' ')
		str++;
	if (*str != '(')
		return (parse_error(INVALID_PARAM_FORMAT));
	str++;
	if (!check_data_type_nbr(str, 3))
		return (0);
	j = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		if (!check_floating_number(str))
			return (0);
		tab[j] = ft_atod(&str);
		j++;
		if (j == 3)
			break ;
	}
	set_vec(vec, tab[0], tab[1], tab[2]);
	return (1);
}

int			check_indent(char *str, int n)
{
	int		i;

	i = 0;
	while (*str == '	')
	{
		i++;
		str++;
	}
	if (i != n)
		return (0);
	if (*str == ' ')
		return (0);
	return (1);
}

int			fill_data(char *str, double *data)
{
	while (*str == '	' || *str == ' ')
		str++;
	if (*str != '(')
		return (parse_error(INVALID_PARAM_FORMAT));
	str++;
	if (!check_data_type_nbr(str, 1))
		return (0);
	while (*str == ' ' || *str == '	')
		str++;
	*data = ft_atod(&str);
	return (1);
}
