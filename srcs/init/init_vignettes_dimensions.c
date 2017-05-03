#include "rtv1.h"
#include "vector.h"

void set_vignette_dimensions(t_env *e, t_limit *l)
{
	if (e->nb_thread == 9)
	{
		l->y = -1;
		l->max_y = 200;
		l->max_x = 400;
		l->tmp_x = -1;
	}
	else
		*l = ft_limit_thread(e->nb_thread, e->image->width, e->image->height);
}
