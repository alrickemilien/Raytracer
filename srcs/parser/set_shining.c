#include "rtv1.h"
#include "parser.h"

static int		check_shining(t_light *new, char *tmp)
{
	int		n;

	if (!ft_strncmp(tmp, "yes", (n = ft_strlen("yes"))))
	{
		new->shining = 1;
		return (n);
	}
	else if (!ft_strncmp(tmp, "no", (n = ft_strlen("no"))))
	{
		new->shining = 0;
		return (n);
	}
	return (parse_error(INVALID_PARAM_FORMAT));
}

int		set_shining(char *tmp, t_light *new, t_pars_object *index)
{
	int		n;

	index->shining++;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (*(tmp++) != '(')
		return (parse_error(INVALID_PARAM_FORMAT));
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (!(n = check_shining(new, tmp)))
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
