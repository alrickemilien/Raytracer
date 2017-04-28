#include "rtv1.h"
#include "parser.h"

static int		check_msaa(t_env *env, char *tmp)
{
	int		n;

	if (!ft_strncmp(tmp, "yes", (n = ft_strlen("yes"))))
	{
		env->msaa = 1;
		return (n);
	}
	else if (!ft_strncmp(tmp, "no", (n = ft_strlen("no"))))
	{
		env->msaa = 0;
		return (n);
	}
	return (parse_error(INVALID_PARAM_FORMAT));
}

int		set_msaa(char *tmp, t_env *env, t_pars_scene *index)
{
	int		n;

	index->msaa++;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (*(tmp++) != '(')
		return (parse_error(INVALID_PARAM_FORMAT));
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (!(n = check_msaa(env, tmp)))
		return (0);
	tmp += n;
	while (ft_isalpha(*tmp))
		tmp++;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (*tmp != ')')
		return (parse_error(INVALID_PARAM_FORMAT));
	if (!check_end_data(tmp + 1))
		return (parse_error(INVALID_PARAM_FORMAT));
	return (1);
}
