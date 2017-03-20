#include "rtv1.h"

double	*invert_matrix(double *t)
{
	t_pivot_gauss	tools;
	double			*s;

	s = (double*)malloc(sizeof(double) * 16);
	ft_bzero(s, sizeof(double) * 16);
	s[0] = 1;
	s[5] = 1;
	s[10] = 1;
	s[15] = 1;
	tools.i = 0;
	while (tools.i < 3)
	{
		tools.pivot = tools.i;
		tools.pivotsize = t[tools.i * 4 + tools.i];
		if (tools.pivotsize < 0)
			tools.pivotsize = -tools.pivotsize;
		tools.j = tools.i + 1;
		while (tools.j < 4)
		{
			tools.tmp = t[tools.j * 4 + tools.i];
			if (tools.tmp < 0)
				tools.tmp = -tools.tmp;
			if (tools.tmp > tools.pivotsize)
			{
				tools.pivot = tools.j;
				tools.pivotsize = tools.tmp;
			}
			tools.j++;
		}
		if (tools.pivotsize == 0)
			return NULL;
		if (tools.pivot != tools.i)
		{
			tools.j = 0;
			while (tools.j < 4)
			{
				swap(&t[tools.i * 4 + tools.j], &t[tools.pivot * 4 + tools.j]);
				swap(&s[tools.i * 4 + tools.j], &s[tools.pivot * 4 + tools.j]);
				tools.j++;
			}
		}
		tools.j = tools.i + 1;
		while (tools.j < 4)
		{
			tools.f = t[tools.j * 4 + tools.i] / t[tools.i * 4 + tools.i];
			tools.k = 0;
			while (tools.k < 4)
			{
				t[tools.j * 4 + tools.k] -= tools.f * t[tools.i * 4 + tools.k];
				s[tools.j * 4 + tools.k] -= tools.f * s[tools.i * 4 + tools.k];
				tools.k++;
			}
			tools.j++;
		}
		tools.i++;
	}
	// Backward substitute
	tools.i = 3;
	while (--tools.i >= 0)
	{
		tools.f = t[tools.i * 4 + tools.i];
		if (tools.f == 0)
			return NULL; // peut pa inverser
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
			tools.k = 0;
			while (tools.k < 4)
			{
				t[tools.j * 4 + tools.k] -= tools.f * t[tools.i * 4 + tools.k];
				s[tools.j * 4 + tools.k] -= tools.f * s[tools.i * 4 + tools.k];
				tools.k++;
			}
			tools.j++;
		}
	}
	return s;
}
