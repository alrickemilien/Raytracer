#include "../include/rtv1.h"

int			set_transparent(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index)
{
	(void)env;
	index->transparent++;
	if (!fill_data(tmp, &new->transparent))
		return (0);
	if (new->transparent < 0 || new->transparent > 1)
		return (parse_error(BAD_COEFF));
	new->transparent = new->transparent;
	return (1);
}
