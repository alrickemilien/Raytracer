#include "parser.h"

int		parse_object(t_env *env, t_obj *obj,
						int (*check_object)(t_env *env, t_obj *obj,
								char *line, void *reference),
						void *reference)
{
	char	*line;

	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		recycle(&line, ft_strtrim(line));
		if (ft_strcmp(line, "") && ft_strcmp(line, "{") && ft_strcmp(line, "}"))
			if (!check_object(env, obj, line, reference))
				return (0);
		if (line[ft_strlen(line) - 1] == '}')
			break ;
		ft_strdel(&line);
	}
	return (1);
}
