/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_csg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:23:20 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/06 13:23:21 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "commun_struct.h"

void		set_spaces_diff(t_range *a, t_range *b)
{
	if (a->t1.t > a->t2.t)
		swap(&a->t1.t, &a->t2.t);
	if (b->t1.t > b->t2.t)
		swap(&b->t1.t, &b->t2.t);
}

int			betwn(double t, double n1, double n2)
{
	if (n1 > n2)
		swap(&n1, &n2);
	if (t >= n1 && t <= n2)
		return (1);
	return (0);
}

int			betwx(double t, double n1, double n2)
{
	if (n1 > n2)
		swap(&n1, &n2);
	if (t > n1 && t < n2)
		return (1);
	return (0);
}

double		range(double a, double b)
{
	if (a > b)
	{
		if (a > 0 && b > 0)
			return (a - b);
		if (a < 0 && b < 0)
			return (-b + a);
		return (a - b);
	}
	if (a < b)
	{
		if (a > 0 && b > 0)
			return (b - a);
		if (a < 0 && b < 0)
			return (-a + b);
		return (b - a);
	}
	return (0);
}
