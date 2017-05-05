/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recycle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:14 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/05 13:52:28 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

inline void	recycle(char **old_ptr, char *new_ptr)
{
	char	*tmp;

	tmp = *old_ptr;
	*old_ptr = new_ptr;
	if (tmp)
		free(tmp);
}
