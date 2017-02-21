/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recycle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:14 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:47:15 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	recycle(char **old_ptr, char *new_ptr)
{
	char	*tmp;

	tmp = *old_ptr;
	*old_ptr = new_ptr;
	if (tmp)
		free(tmp);
}
