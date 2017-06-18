/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 10:13:18 by aemilien          #+#    #+#             */
/*   Updated: 2017/04/28 11:09:34 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		operate(double *t, double *s, t_pivot_gauss *tools)
{
	tools->k = 0;
	while (tools->k < 4)
	{
		t[tools->j * 4 + tools->k] -= tools->f * t[tools->i * 4 + tools->k];
		s[tools->j * 4 + tools->k] -= tools->f * s[tools->i * 4 + tools->k];
		tools->k++;
	}
}

static int		backward_substitution(double *t, double *s)
{
	t_pivot_gauss	tools;

	tools.i = 3;
	while (--tools.i >= 0)
	{
		tools.f = t[tools.i * 4 + tools.i];
		if (tools.f == 0)
			return (0);
		tools.j = 0;
		while (tools.j < 4)
		{
			t[tools.i * 4 + tools.j] /= tools.f;
			s[tools.i * 4 + tools.j] /= tools.f;
			tools.j++;
		}
		tools.j = 0;
		while (tools.j < tools.i)
		{
			tools.f = t[tools.j * 4 + tools.i];
			operate(t, s, &tools);
			tools.j++;
		}
	}
	return (1);
}

static double	*init_matrix(void)
{
	double			*s;

	s = (double*)ft_memalloc(sizeof(double) * 16);
	s[0] = 1;
	s[5] = 1;
	s[10] = 1;
	s[15] = 1;
	return (s);
}

static int		forward_substitution(double *t, double *s, t_pivot_gauss *tools)
{
	tools->j = tools->i + 1;
	while (tools->j < 4)
	{
		tools->tmp = t[tools->j * 4 + tools->i];
		if (tools->tmp < 0)
			tools->tmp = -tools->tmp;
		if (tools->tmp > tools->pivotsize)
		{
			tools->pivot = tools->j;
			tools->pivotsize = tools->tmp;
		}
		tools->j++;
	}
	if (tools->pivotsize == 0)
		return (0);
	if (tools->pivot != tools->i)
	{
		tools->j = -1;
		while (++tools->j < 4)
		{
			swap(&t[tools->i * 4 + tools->j], &t[tools->pivot * 4 + tools->j]);
			swap(&s[tools->i * 4 + tools->j], &s[tools->pivot * 4 + tools->j]);
		}
	}
	return (1);
}

double			*inv_m(double *t)
{
	t_pivot_gauss	tools;
	double			*s;

	s = init_matrix();
	tools.i = 0;
	while (tools.i < 3)
	{
		tools.pivot = tools.i;
		tools.pivotsize = t[tools.i * 4 + tools.i];
		if (tools.pivotsize < 0)
			tools.pivotsize = -tools.pivotsize;
		tools.j = tools.i + 1;
		if (!forward_substitution(t, s, &tools))
			return (NULL);
		tools.j = tools.i;
		while (++tools.j < 4)
		{
			tools.f = t[tools.j * 4 + tools.i] / t[tools.i * 4 + tools.i];
			operate(t, s, &tools);
		}
		tools.i++;
	}
	if (!(backward_substitution(t, s)))
		return (NULL);
	return (s);
}
