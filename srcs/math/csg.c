#include "../include/rtv1.h"

int		intersection(double t, t_list *lst)
{
	t_list	*tmp;
	int		res[2];

	tmp = lst;
	while (tmp)
	{
		if (*((double*)(tmp->content)) <= t)
		tmp = tmp->next;
	}
	if ()
}

void	set_intersection(t_list	*a, t_list *b, int (*check)(double t, t_list *inter))
{
	t_list		*tmp;
	t_list		inter_csg;

	tmp = a;
	while (tmp)
	{
		if (check(((t_vector*)(tmp->content))->x, b))
			ft_lstadd(&inter_csg, ft_lstnew(tmp->content, tmp->size));
	}
}

/*
 *
 * Liste de deux valeur double interesction qui sont des plages
 *
 */

int		csg(t_obj obj, t_ray *ray, double *t, t_list **inter)
{
	(void)inter;
	t_list			*tmp_list;
	t_obj			*tmp;
	t_list			*a; // liste d'intersection pour l'objet a
	t_list			*b;

	ray->t = 2000000;
	t = 0;
	tmp_list = obj.csg;
	((t_obj*)(tmp_list->content))->func_obj(
			*((t_obj*)(tmp_list->content)), ray,
			t, b)
		tmp_list = tmp_list->next;
	((t_obj*)(tmp_list->content))->func_obj(
			*((t_obj*)(tmp_list->content)),
			ray, t, a)
		if (tmp)
			return (1);
	return (0);
}
