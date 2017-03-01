#include "../include/rtv1.h"

int		csg(t_obj obj, t_ray *ray, double *t)
{
	double		t;
	t_list		*tmp_list;
	t_obj		*obj;

	ray->t = 2000000;
	t = 0;
	tmp_list = obj->csg;
	while (tmp_list)
	{
		if (((t_obj*)(tmp_list->content))->func_obj(
					*((t_obj*)(tmp_list->content)), ray, &t))
		{
			if (ray->t > t && t > ZERO)
				*tmp = (t_obj*)(tmp_list->content);
		}
		tmp_list = tmp_list->next;
	}
	if (*tmp)
		return (1);
	return (0);
}
