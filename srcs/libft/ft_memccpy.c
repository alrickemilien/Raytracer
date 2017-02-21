/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:21:09 by salibert          #+#    #+#             */
/*   Updated: 2016/11/04 12:13:44 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*str_d;
	const char	*str_s;
	size_t		i;

	i = 0;
	str_d = (char*)dest;
	str_s = (char*)src;
	while (i != n)
	{
		str_d[i] = str_s[i];
		if (str_d[i] == c)
			return ((char*)dest + ++i);
		i++;
	}
	return (0);
}
