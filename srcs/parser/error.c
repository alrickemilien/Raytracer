/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:46:51 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/31 16:45:46 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parser.h"

int		parse_error(char *str)
{
	ft_putendl_fd(str, 1);
	return (0);
}

int		error_file(char *file)
{
	ft_putstr_fd("Error : ", 2);
	perror(file);
	ft_putendl_fd(USAGE, 2);
	exit(-1);
	return (0);
}

int		merror(void)
{
	perror("");
	exit(0);
	return (0);
}

int		clean_error(char **str)
{
	ft_strdel(str);
	return (0);
}