/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:11:35 by salibert          #+#    #+#             */
/*   Updated: 2016/11/13 17:42:47 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t ls1;
	size_t ls2;

	ls2 = 0;
	ls1 = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[ls1] && ls1 < n)
	{
		while (s1[ls1 + ls2] == s2[ls2] && s2[ls2] != '\0' && ls1 + ls2 < n)
			ls2++;
		if (s2[ls2] == '\0')
			return ((char*)s1 + ls1);
		ls2 = 0;
		ls1++;
	}
	return (0);
}
