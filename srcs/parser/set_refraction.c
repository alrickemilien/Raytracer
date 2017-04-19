#include "parser.h"

int		set_refraction(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->refraction++;
	if (!fill_data(tmp, &new->refraction))
		return (0);
	if (new->refraction < 0)
		return (parse_error(BAD_COEFF));
	return (1);
}
