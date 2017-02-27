#include "../include/rtv1.h"

static int	get_intersection(t_list *csg, t_ray *ray, t_obj **tmp)
{
	double		t;
	t_list		*tmp_list;

	ray->t = 2000000;
	t = 0;
	tmp_list = csg;
	while (tmp_list)
	{
		if (((t_obj*)(tmp_list->content))->func_obj(
					*((t_obj*)(tmp_list->content)), ray, &t))
		{
			if (ray->t > t && t > ZERO)
			{
				ray->t = t;
				*tmp = (t_obj*)(tmp_list->content);
			}
		}
		tmp_list = tmp_list->next;
	}
	if (*tmp)
		return (1);
	return (0);
}

int		csg(t_obj obj, t_ray *ray, double *t)
{
	
}
