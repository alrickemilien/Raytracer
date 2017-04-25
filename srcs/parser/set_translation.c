#include "parser.h"
#include "vector.h"

int			set_translation(t_env *env, char *s, t_obj *new, t_pars_object *i)
{
	(void)env;
	i->translation++;
	if (!fill_data_vec(s, &new->translation))
		return (0);
	return (1);
}

void		set_translation_csg(t_vector translation, t_list *csg)
{
	t_obj	*obj;

	if (!translation.x && !translation.y && !translation.z)
		return ;
	while (csg)
	{
		obj = (t_obj*)csg->content;
		if (obj->etat == CSG || obj->etat == BOX)
			set_translation_csg(translation, obj->csg);
		else if (obj->etat == CONE || obj->etat == CYLINDRE)
			obj->apex = vec_add(obj->apex, translation);
		else
			obj->pos = vec_add(obj->pos, translation);
		csg = csg->next;
	}
}
