/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:25:35 by salibert          #+#    #+#             */
/*   Updated: 2016/11/10 09:33:37 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*str1;
	const char	*str2;

	str1 = (char*)dest;
	str2 = (char*)src;
	while (n != 0)
	{
		n--;
		str1[n] = str2[n];
	}
	return (dest);
}
