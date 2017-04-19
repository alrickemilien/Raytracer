#include "parser.h"
#include "init.h"

static int check_extention(char *str, char *extention, char **path)
{
    int   size;

    str = ft_strtrim(str);
    size = ft_strlen(str);
    if (str[size - 1] != ')')
        return (2);
    str[size - 1] = ' ';
    recycle(path, ft_strtrim(str));
    ft_strdel(&str);
    if (!(str = ft_strstr(*path, extention)))
        return (0);
    if (ft_strcmp(str, extention))
        return (0);
    return (1);
}

static int     fill_path(char *str, char **path)
{
    int i;

    i  = 0;
    while ((*str == ' '  || *str == '\t') && str)
        str++;
    if (*str != '(')
        return (parse_error(INVALID_PARAM_FORMAT));
    str++;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (!(i = check_extention(str, ".xpm", path)))
        return (parse_error(INVALID_XPM_EXTENTION));
    else if (i == 2)
        return (parse_error(INVALID_PARAM_FORMAT));
    return (1);
}

int		set_texture(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
    char *path;

    path = NULL;
	(void)env;
	index->texture++;
	if (!(fill_path(tmp, &path)))
		return (clean_error(&path));
    path = ft_strjoinf("srcs/textures/", path, 'R');
    if (!(new->texture = init_texture(env->addr_mlx, path)))
    {
        ft_strdel(&path);
	    return (parse_error(INVALID_TEXTURE));
    }
    ft_strdel(&path);
    return (1);
}