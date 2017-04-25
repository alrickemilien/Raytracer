#include "parser.h"
#include "vector.h"
#include "rtv1.h"

static t_obj		set_default_box(t_env *env)
{
	t_obj			obj;

	ft_bzero(&obj, (sizeof(t_obj)));
	set_vec(&obj.translation, 0, 0, 0);
	set_vec(&obj.rot, 0, 0, 0);
	obj.color = split_color(mlx_get_color_value(env->addr_mlx, 0x00FF0000));
	obj.brillance = 10;
	obj.diffuse = 1;
	obj.specular = 1;
	obj.etat = BOX;
	obj.func_obj = &box;
	obj.refraction = 1;
	obj.size = 1;
	return (obj);
}

static int			check_box(t_env *env, t_obj *new,
					char *tmp, t_pars_object *index)
{
	int				n;
	int				i;

	i = 0;
	while (i < NBR_DESCRIPTION)
	{
		if (!ft_strncmp(env->tab_str_description[i],
					tmp, (n = ft_strlen(env->tab_str_description[i]))))
			break ;
		i++;
	}
	if (i == NBR_DESCRIPTION)
		return (parse_error(INVALID_DESCRIPTION));
	if (!env->check_description[i](env, tmp + n, new, index))
		return (0);
	return (1);
}

static int			check_reference(t_pars_object reference)
{
	if (reference.position > 1 || reference.color > 1
			|| reference.brillance > 1 || reference.rot > 1
			|| reference.specular > 1 || reference.diffuse > 1
			|| reference.reflection > 1 || reference.transparent > 1
			|| reference.translation > 1)
		return (parse_error(INVALID_OBJECT));
	if (reference.axis || reference.apex || reference.rayon
			|| reference.angle || reference.to || reference.from
			|| reference.type || reference.normal)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

static void			ft_clean(t_pars_object *ref, double *m)
{
	ft_bzero(ref, sizeof(t_pars_object));
	ft_bzero(m, sizeof(double) * 16);
}

int					set_box(t_env *env, t_list **list_obj)
{
	t_obj			box;
	char			*line;
	t_pars_object	ref;
	double			m[16];

	box = set_default_box(env);
	line = NULL;
	ft_clean(&ref, m);
	while (get_next_line(env->fd, &line))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_box(env, &box, line, &ref))
				return (clean_error(&line));
		if (line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(ref))
		return (0);
	set_boxs_plans(&box.csg, box);
	box.matrix = inv_m(set_rot_m(m, box.rot.x, box.rot.y, box.rot.z));
	ft_lstadd(list_obj, ft_lstnew(&box, (sizeof(t_obj))));
	return (1);
}
