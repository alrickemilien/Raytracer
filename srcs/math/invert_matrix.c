#include "rtv1.h"

static int			tools_3(double *t, double *s, t_pivot_gauss tools)
{
	tools.i = 3;
	while (--tools.i >= 0)
	{
		tools.f = t[tools.i * 4 + tools.i];
		if (tools.f == 0)
			return (0);
		tools.j = -1;
		while (++tools.j < 4)
		{
			t[tools.i * 4 + tools.j] /= tools.f;
			s[tools.i * 4 + tools.j] /= tools.f;
		}
		tools.j = -1;
		while (++tools.j < tools.i)
		{
			tools.f = t[tools.j * 4 + tools.i];
			tools.k = -1;
			while (++tools.k < 4)
			{
				t[tools.j * 4 + tools.k] -= tools.f * t[tools.i * 4 + tools.k];
				s[tools.j * 4 + tools.k] -= tools.f * s[tools.i * 4 + tools.k];
			}
		}
	}
	return (1);
}

static int			tools_2(double *t, t_pivot_gauss *tools)
{
	tools->pivot = tools->i;
	tools->pivotsize = t[tools->i * 4 + tools->i];
	if (tools->pivotsize < 0)
		tools->pivotsize = -tools->pivotsize;
	tools->j = tools->i;
	while (++tools->j < 4)
	{
		tools->tmp = t[tools->j * 4 + tools->i];
		if (tools->tmp < 0)
			tools->tmp = -tools->tmp;
		if (tools->tmp > tools->pivotsize)
		{
			tools->pivot = tools->j;
			tools->pivotsize = tools->tmp;
		}
	}
	if (tools->pivotsize == 0)
		return (0);
	return (1);
}

static int			tools_1(double *t, double *s, t_pivot_gauss *tools)
{
	if (!(tools_2(t, tools)))
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
	tools->j = tools->i;
	while (++tools->j < 4)
	{
		tools->f = t[tools->j * 4 + tools->i] / t[tools->i * 4 + tools->i];
		tools->k = -1;
		while (++tools->k < 4)
		{
			t[tools->j * 4 + tools->k] -= tools->f * t[tools->i * 4 + tools->k];
			s[tools->j * 4 + tools->k] -= tools->f * s[tools->i * 4 + tools->k];
		}
	}
	return (1);
}

static double		*init_s(void)
{
	double			*s;

	s = (double*)ft_memalloc(sizeof(double) * 16);
	s[0] = 1;
	s[5] = 1;
	s[10] = 1;
	s[15] = 1;
	return (s);
}

double				*inv_m(double *t)
{
	t_pivot_gauss	tools;
	double			*s;

	s = init_s();
	tools.i = -1;
	while (++tools.i < 3)
		if (!(tools_1(t, s, &tools)))
			return (NULL);
	if (!(tools_3(t, s, tools)))
		return (NULL);
	return (s);
}
