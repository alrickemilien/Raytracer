#include "rtv1.h"
#include "parser.h"

static void	del_tab(char **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
}

static int	check_type(t_light *new, char *tmp)
{
	char	*tab[2];
	int		i;
	int		n;

	i = 0;
	tab[SPHERICAL_LIGHT] = ft_strdup("spherical");
	tab[CONE_LIGHT] = ft_strdup("cone");
	while (i < 3)
	{
		if (!ft_strncmp(tmp, tab[i], (n = ft_strlen(tab[i]))))
			break ;
		i++;
	}
	if (i == 3)
		return (parse_error(INVALID_PARAM_FORMAT));
	new->type = i;
	del_tab(tab, 2);
	return (n);
}

int			set_type_light(char *tmp, t_light *new, t_pars_object *index)
{
	int		n;

	index->type++;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (*(tmp++) != '(')
		return (parse_error(INVALID_PARAM_FORMAT));
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (!(n = check_type(new, tmp)))
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
