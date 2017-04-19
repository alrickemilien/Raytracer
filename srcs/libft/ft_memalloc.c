/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:08:55 by salibert          #+#    #+#             */
/*   Updated: 2017/03/22 18:15:36 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*list;
	void *s;

	if (!(s = malloc(size)))
		return (NULL);
	list = (char*)s;
	while (size != 0)
		list[--size] = 0;
	return (s);
}
