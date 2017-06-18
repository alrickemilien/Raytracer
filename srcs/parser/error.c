/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:05:07 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:05:09 by lvalenti         ###   ########.fr       */
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

int		clean_error2(char **str, t_obj *obj, void *addr_mlx)
{
	if (obj->texture)
		free_image(addr_mlx, &obj->texture, obj->texture->addr_img);
	if (str)
		ft_strdel(str);
	return (0);
}
