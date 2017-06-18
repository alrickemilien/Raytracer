/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:58:33 by salibert          #+#    #+#             */
/*   Updated: 2016/11/10 09:53:53 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = ft_strlen(s);
	dup = (char*)malloc(sizeof(*dup) * (i + 1));
	if (dup == NULL)
		return (NULL);
	dup[i] = '\0';
	while (i--)
		dup[i] = s[i];
	return (dup);
}
