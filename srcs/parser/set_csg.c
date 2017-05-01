#include "parser.h"
#include "vector.h"
#include "rtv1.h"

static void		ft_objdel_s(t_list *obj, void *addr_mlx)
{
	t_obj		*tmp_obj;
	t_list		*list;
	t_list		*tmp_list;

	list = obj;
	while (list)
	{
		if ((tmp_obj = (t_obj*)(list->content)))
		{
			if (tmp_obj->texture)
				mlx_destroy_image(addr_mlx, tmp_obj->texture->addr_img);
			if (tmp_obj->texture)
				free(tmp_obj->texture);
			if (tmp_obj->csg)
				ft_objdel_s(tmp_obj->csg, addr_mlx);
			if (tmp_obj->matrix)
				free(tmp_obj->matrix);
			tmp_list = list;
			list = list->next;
			free(tmp_list->content);
			tmp_list->content = NULL;
			free(tmp_list);
		}
	}
}

static t_obj		set_default_csg(t_env *env)
{
	t_obj			new_csg;

	(void)env;
	ft_bzero(&new_csg, sizeof(t_obj));
	new_csg.etat = CSG;
	new_csg.intersection = UNION;
	new_csg.func_obj = &csg;
	new_csg.color = split_color(mlx_get_color_value(env->addr_mlx, 0xFF0000));
	new_csg.diffuse = 0.5;
	new_csg.specular = 0.5;
	new_csg.refraction = 1;
	return (new_csg);
}

static int			check_object(t_env *env, char *line, t_obj *new)
{
	int			i;
	char		*crochet;

	i = -1;
	while (++i < NBR_OBJECT)
		if (!ft_strcmp(line, env->tab_str_object[i]))
			break ;
	if (i == LIGHT || i == CAMERA || i == NBR_OBJECT)
		return (parse_error(INVALID_FORMAT_FILE));
	get_next_line(env->fd, &crochet);
	recycle(&crochet, ft_strtrim(crochet));
	if (ft_strcmp("{", crochet))
	{
		free(crochet);
		return (parse_error(INVALID_FORMAT_FILE));
	}
	if (!env->set_object[i](env, &new->csg))
		return (clean_error(&crochet));
	ft_strdel(&crochet);
	return (1);
}

static int			check_reference(t_pars_object ref)
{
	if (ref.position || ref.color > 1 || ref.rayon
			|| ref.brillance || ref.rot
			|| ref.specular > 1 || ref.diffuse > 1
			|| ref.reflection > 1 || ref.transparent > 1
			|| ref.type > 1 || ref.translation > 1)
		return (parse_error(INVALID_OBJECT));
	if (ref.normal || ref.apex || ref.axis
			|| ref.angle || ref.from || ref.to || ref.size)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

static int			check_csg(t_env *env, t_obj *new,
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
	if (i < NBR_DESCRIPTION)
		if (!env->check_description[i](env, tmp + n, new, index))
			return (0);
	if (i == NBR_DESCRIPTION)
		if (!check_object(env, tmp, new))
			return (0);
	return (1);
}

int					set_csg(t_env *env, t_list **list_obj)
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
			{
				ft_objdel_s(new.csg, env->addr_mlx);
				return (clean_error(&line));
			}
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
