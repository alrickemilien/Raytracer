/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:08:57 by salibert          #+#    #+#             */
/*   Updated: 2016/11/11 15:56:37 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	ls1;
	size_t	ls2;

	ls1 = 0;
	ls2 = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[ls1])
	{
		while (s1[ls1 + ls2] == s2[ls2] && s2[ls2] != '\0')
			ls2++;
		if (s2[ls2] == '\0')
			return ((char*)s1 + ls1);
		ls2 = 0;
		ls1++;
	}
	return (0);
}
