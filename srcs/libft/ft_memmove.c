/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:15:39 by salibert          #+#    #+#             */
/*   Updated: 2016/11/13 15:58:05 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*str_d;
	const char	*str_s;
	size_t		i;

	i = 0;
	str_d = (char*)dest;
	str_s = (char*)src;
	if (dest > src)
		while (n)
		{
			n--;
			str_d[n] = str_s[n];
		}
	else
		while (i < n)
		{
			str_d[i] = str_s[i];
			i++;
		}
	return (dest);
}
