/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:48:38 by salibert          #+#    #+#             */
/*   Updated: 2016/11/11 15:11:38 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	len_s;

	len_s = ft_strlen(s);
	while (len_s != 0)
	{
		if (s[len_s] == c)
			return ((char*)s + len_s);
		len_s--;
	}
	if (s[len_s] == c)
		return ((char*)s + len_s);
	return (0);
}
