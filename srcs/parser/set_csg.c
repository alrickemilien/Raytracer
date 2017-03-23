#include "../include/rtv1.h"

static t_obj	set_default_csg(t_env *env)
{
	t_obj		new_csg;

	(void)env;
	ft_bzero(&new_csg, sizeof(t_obj));
	new_csg.etat = CSG;
	new_csg.intersection = UNION;
	new_csg.func_obj = &csg;
	new_csg.csg = NULL;
	new_csg.color = split_color(mlx_get_color_value(env->addr_mlx, 0xFF0000));
	new_csg.diffuse = 0.5;
	new_csg.specular = 0.5;
	new_csg.reflection = 0;
	new_csg.refraction = 1;
	new_csg.csg = NULL;
	return (new_csg);
}

static int	check_object(t_env *env, char *line, t_obj *new)
{
	int		i;
	char	*crochet;

	i = -1;
	while (++i < NBR_OBJECT)
		if (!ft_strcmp(line, env->tab_str_object[i]))
			break ;
	if (i == LIGHT || i == CAMERA || i == NBR_OBJECT)
		return (parse_error(INVALID_FORMAT_FILE));
	get_next_line(env->fd, &crochet);
	recycle(&crochet, ft_strtrim(crochet));
	if (ft_strcmp("{", crochet))
		return (parse_error(INVALID_FORMAT_FILE));
	if (!env->set_object[i](env, &new->csg))
		return (0);
	ft_strdel(&crochet);
	return (1);
}

static int	check_reference(t_pars_object reference)
{
	if (reference.position || reference.color > 1 || reference.rayon
			|| reference.brillance || reference.rotation
			|| reference.specular > 1 || reference.diffuse > 1
			|| reference.reflection > 1 || reference.transparent > 1
			|| reference.type > 1 || reference.translation > 1)
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

	i = 0;
	while (i < NBR_DESCRIPTION)
	{
		if (!ft_strncmp(env->tab_str_description[i],
					tmp, (n = ft_strlen(env->tab_str_description[i]))))
			break ;
		i++;
	}
	if (i < NBR_DESCRIPTION)
		if (!env->check_description[i](env, tmp + n, new, index))
			return (0);
	if (i == NBR_DESCRIPTION)
		if (!check_object(env, tmp, new))
			return (0);
	return (1);
}

static void		set_translation_csg(t_vector translation, t_list *csg)
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

int				set_csg(t_env *env, t_list **list_obj)
{
	t_obj			new;
	char			*line;
	t_pars_object	reference;

	new = set_default_csg(env);
	line = NULL;
	ft_bzero(&reference, sizeof(reference));
	while (get_next_line(env->fd, &line))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_csg(env, &new, line, &reference))
				return (0);
		if (line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(reference))
		return (0);
	set_translation_csg(new.translation, new.csg);
	ft_lstadd(list_obj, ft_lstnew(&new, (sizeof(t_obj))));
	return (1);
}
