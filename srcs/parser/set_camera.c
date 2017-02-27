/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:46 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/27 13:15:45 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void			set_default_camera(t_camera *new)
{
	set_vec(&new->pos, 0, 0, 0);
	set_vec(&new->to, 0, 0, 1);
	new->num = 0;
}

static int			check_camera(
		t_env *env, t_camera *new,
		char *tmp, t_pars_object *index)
{
	int				n;

	(void)env;
	if (!ft_strncmp(FROM, tmp, (n = ft_strlen(FROM))))
	{
		(index->from)++;
		if (!fill_data_vec(tmp + n, &new->pos))
			return (0);
	}
	else if (!ft_strncmp(TO, tmp, (n = ft_strlen(TO))))
	{
		(index->to)++;
		if (!fill_data_vec(tmp + n, &new->to))
			return (0);
	}
	else
		return (parse_error(INVALID_DESCRIPTION));
	return (1);
}

int		check_straight(t_camera *cam)
{
	t_vector	f;
	t_vector	vec_forward;
	t_vector	vec_right;
	t_vector	vec_up;

	f = vec_diff(cam->pos, cam->to);
	normalize_vec(&f);
	if (ft_dabs(f.x) <= 1 && ft_dabs(f.y) > 0.988 && ft_dabs(f.z) <= 1)
	{
		vec_forward = vec_diff(cam->pos, cam->to);
		normalize_vec(&vec_forward);
		set_vec(&f, 0, 0, 1);
		normalize_vec(&f);
		vec_right = cross_product(f, vec_forward);
		vec_up = cross_product(vec_forward, vec_right);
		cam->matrix = set_camera_matrix(vec_forward, vec_up,
				vec_right, cam->pos);
		return (1);
	}
	return (0);
}

int					check_ref_camera(t_pars_object ref, t_camera new)
{
	if (ref.from > 1 || ref.to > 1 || ref.position || ref.brillance || ref.angle
			|| ref.rayon || ref.color || ref.apex || ref.axis || ref.normal
			|| ref.rotation || ref.intensity || ref.size || ref.diffuse
			|| ref.specular || ref.transparent)
		return (parse_error(INVALID_OBJECT));
	if (new.pos.x == new.to.x && new.pos.z == new.to.z && new.pos.y == new.to.y)
		return (parse_error(INVALID_CAMERA));
	return (1);
}

int					set_camera(t_env *env, t_list **list_obj)
{
	t_camera		new;
	char			*line;
	t_pars_object	reference;

	(void)list_obj;
	set_default_camera(&new);
	ft_bzero(&reference, sizeof(reference));
	line = NULL;
	while (get_next_char(env->fd, &line, '\n'))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && line[0] != '}')
			if (!check_camera(env, &new, line, &reference))
				return (0);
		if(line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!(check_ref_camera(reference, new)))
		return (0);
	if (!check_straight(&new))
		set_camera_data(&new);
	ft_lstadd(&env->camera, ft_lstnew(&new, (sizeof(t_camera))));
	return (1);
}
