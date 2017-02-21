/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:43:10 by salibert          #+#    #+#             */
/*   Updated: 2016/11/13 17:31:55 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	char	*new;
	size_t	a;
	size_t	z;

	if (!s)
		return (NULL);
	if (ft_strlen(s) == 0)
		return ((char*)malloc(sizeof(*new) * (0)));
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return ((ft_strsub(s, 0, 0)));
	a = i;
	while (s[i])
		i++;
	while (s[i] == ' ' || s[i] == '\0' || s[i] == '\t' || s[i] == '\n')
		i--;
	z = i;
	new = ft_strsub(s, a, (z - a + 1));
	return (new);
}
