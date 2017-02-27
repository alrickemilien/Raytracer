#include "../include/rtv1.h"

static t_obj	set_default_csg(t_env *env)
{
	t_obj		csg;

	(void)env;
	ft_bzero(&csg, sizeof(t_obj));
	csg.etat = CSG;
	return (csg);
}

static int		check_reference(t_pars_object reference)
{
	if (reference.position > 1 || reference.color > 1 || reference.rayon > 1
			|| reference.brillance > 1 || reference.rotation > 1
			|| reference.specular > 1 || reference.diffuse > 1
			|| reference.reflection > 1 || reference.transparent > 1)
		return (parse_error(INVALID_OBJECT));
	if (reference.normal || reference.apex || reference.axis
			|| reference.angle || reference.from || reference.to || reference.size)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

static int		check_csg(t_env *env, t_obj *new,
		char *tmp, t_pars_object *index)
{
	int		n;
	int		i;

	(void)index;
	i = 0;
	while (i < NBR_DESCRIPTION)
	{
		if (!ft_strncmp(env->tab_str_object[i],
					tmp, (n = ft_strlen(env->tab_str_object[i]))))
			break ;
		i++;
	}
	if (i == NBR_DESCRIPTION)
		return (parse_error(INVALID_DESCRIPTION));
	if (i == LIGHT || i == CAMERA)
		return (parse_error(INVALID_DESCRIPTION));
	if (!env->set_object[i](env, &new->csg))
		return (0);
	return (1);
}

int				set_csg(t_env *env, t_list **list_obj)
{
	t_obj			new;
	char			*line;
	t_pars_object	reference;

	new = set_default_csg(env);
	line = NULL;
	ft_bzero(&reference, sizeof(reference));
	while (get_next_char(env->fd, &line, '\n'))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && line[0] != '}')
			if (!check_csg(env, &new, line, &reference))
				return (0);
		if(line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(reference))
		return (0);
	ft_lstadd(list_obj, ft_lstnew(&new, (sizeof(t_obj))));
	return (1);
}
