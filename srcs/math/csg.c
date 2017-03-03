#include "../include/rtv1.h"

/*
 *
 * t_list *a ---> liste d'intersections de l'objet a
 * t_list *b ---> liste d'intersections de l'objet b
 *
 */

static void	swap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int		between(double t, double n1, double n2)
{
	if (n1 > n2)
		swap(&n1, &n2);
	if (t >= n1 && t <= n2)
		return (1);
	return (0);
}

static double	range(double a, double b)
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
		if (a > 0 && b < 0)
			return (a - b);
		if (a < 0 && b < 0)
			return (-a + b);
		return (b - a);
	}
	return (0);
}

static void	swap_object(t_range *a, t_range *b)
{
	t_obj	*tmp;

	tmp = a->t1.obj;
	a->t1.obj = b->t1.obj;
	b->t1.obj = tmp;
	tmp = a->t2.obj;
	a->t2.obj = b->t2.obj;
	b->t2.obj = tmp;
}

static void	set_spaces(t_range *a, t_range *b)
{
	t_obj	*tmp;

	if (range(a->t1.t, a->t2.t) < range(b->t1.t, b->t2.t))
	{
		swap(&a->t1.t, &b->t1.t);
		swap(&a->t2.t, &b->t2.t);
		swap_object(a, b);
	}
	if (a->x > a->y)
		swap(&a->x, &a->y);
	if (b->x > b->y)
		swap(&b->x, &b->y);
	//printf("structure a : a.x = %lf --- a.y = %lf\n", a->x, a->y);
	//printf("structure b : b.x = %lf --- b.y = %lf\n\n", b->x, b->y);
}

void	intersection(t_list **ret, t_range a, t_range b)
{
	t_vector	n;
	int			k;

	set_spaces(&a, &b);
	k = 0;
	n.x = a.x;
	if (between(b.x, a.x , a.y))
	{
		k = 1;
		n.x = b.x;
	}
	n.y = a.y;
	if (between(b.y, a.x, a.y))
	{
		k = 1;
		n.y = b.y;
	}
	if (k)
		ft_lstadd(ret, ft_lstnew(&n, sizeof(t_vector)));
}

t_list	*function(t_list *a, t_list *b)
{
	t_list	*ret;
	t_list *tmp_b;

	ret = NULL;
	while (a)
	{
		tmp_b = b;
		while(tmp_b)
		{
			intersection(&ret,
					*((t_range*)(a->content)),
					*((t_range*)(tmp_b->content)));
			tmp_b = tmp_b->next;
		}
		a = a->next;
	}
	return (ret);
}

/*
 *
 * Liste de deux valeurs double intersection qui sont des plages
 *
 */

static void	get_smaller_t(t_list *lst, double *t)
{
	*t = 2000000;
	while (lst)
	{
		if (((t_vector*)(lst->content))->x < *t
			&& ((t_vector*)(lst->content))->x > ZERO)
			*t = ((t_vector*)(lst->content))->x;
		if (((t_vector*)(lst->content))->y < *t
			&& ((t_vector*)(lst->content))->y > ZERO)
			*t = ((t_vector*)(lst->content))->y;
		lst = lst->next;
	}
}

int		ft_lstlen(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int		csg(t_obj *obj, t_ray *ray, double *t, t_list **inter)
{
	t_list			*tmp_list;
	t_list			*a; // liste d'intersections pour l'objet a (x et y)
	t_list			*b;

	a = NULL;
	b = NULL;
	tmp_list = obj->csg;
	((t_obj*)(tmp_list->content))->func_obj(
				((t_obj*)(tmp_list->content)),
				ray, t, &b);
	tmp_list = tmp_list->next;
	((t_obj*)(tmp_list->content))->func_obj(
				((t_obj*)(tmp_list->content)),
				ray, t, &a);
	*inter = function(a, b);
	get_smaller_t(*inter, t);
	if (*inter)
		return (1);
	return (0);
}
