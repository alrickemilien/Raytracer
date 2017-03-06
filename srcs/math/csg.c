#include "../include/rtv1.h"

/*
 *
 * t_list *a ---> liste d'intersections de l'objet a
 * t_list *b ---> liste d'intersections de l'objet b
 *
 */

void	swap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		between(double t, double n1, double n2)
{
	if (n1 > n2)
		swap(&n1, &n2);
	if (t >= n1 && t <= n2)
		return (1);
	return (0);
}

int		betweex(double t, double n1, double n2)
{
	if (n1 > n2)
		swap(&n1, &n2);
	if (t > n1 && t < n2)
		return (1);
	return (0);
}

double	range(double a, double b)
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

static void	get_smaller_t(t_list *lst, t_obj **obj, double *t)
{
	*t = 2000000;
	while (lst)
	{
		//		printf("range : %lf --- %lf\n",
		//				((t_range*)(lst->content))->t1.t,
		//				((t_range*)(lst->content))->t2.t);
		if (((t_range*)(lst->content))->t1.t < *t
				&& ((t_range*)(lst->content))->t1.t > ZERO)
		{
			*t = ((t_range*)(lst->content))->t1.t;
			*obj = ((t_range*)(lst->content))->t1.obj;
		}
		if (((t_range*)(lst->content))->t2.t < *t
				&& ((t_range*)(lst->content))->t2.t > ZERO)
		{
			*t = ((t_range*)(lst->content))->t2.t;
			*obj = ((t_range*)(lst->content))->t2.obj;
		}
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

static void	set_caracteristic(t_obj *obj, t_obj *lol)
{
	if (!lol)
		return ;
	obj->pos = lol->pos;
	obj->n = lol->n;
	obj->apex = lol->apex;
	obj->axis = lol->axis;
	obj->r = lol->r;
	obj->angle = lol->angle;
	obj->brillance = lol->brillance;
	obj->inter_type = lol->etat;
	obj->refraction = lol->refraction;
	obj->reflection = lol->reflection;
	obj->transparent = lol->transparent;
	obj->color = lol->color;
}

int		csg(t_obj *obj, t_ray *ray, double *t, t_list **inter)
{
	t_list			*tmp_list;
	t_list			*a; // liste d'intersections pour l'objet a (x et y)
	t_list			*b;
	t_obj			*lol;

	a = NULL;
	b = NULL;
	lol  = NULL;
	tmp_list = obj->csg;
	((t_obj*)(tmp_list->content))->func_obj(
	((t_obj*)(tmp_list->content)),
	ray, t, &b);
	tmp_list = tmp_list->next;
	((t_obj*)(tmp_list->content))->func_obj(
	((t_obj*)(tmp_list->content)),
	ray, t, &a);
	if (obj->type == DIFFERENCE)
		*inter = function_difference(a, b);
	else
		*inter = function_intersection(a, b);
	get_smaller_t(*inter, &lol, t);
	set_caracteristic(obj, lol);
	if (*inter)
		return (1);
	return (0);
}
