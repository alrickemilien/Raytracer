#include "../include/rtv1.h"

int		set_reflection(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->reflection++;
	if (!fill_int_data(tmp, &new->reflection))
		return (0);
	if (new->reflection < 0)
		return (0);
	return (1);
}
