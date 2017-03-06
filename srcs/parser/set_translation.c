#include "../include/rtv1.h"

int		set_translation(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->translation++;
	if (!fill_data_vec(tmp, &new->translation))
		return (0);
	return (1);
}
