/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:40:02 by salibert          #+#    #+#             */
/*   Updated: 2016/11/13 16:35:47 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str_chr;
	size_t		i;

	i = 0;
	str_chr = (char*)s;
	while (i != n)
	{
		if ((unsigned char)str_chr[i] == (unsigned char)c)
			return ((char*)s + i);
		i++;
	}
	return (0);
}
