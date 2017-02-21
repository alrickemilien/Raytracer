/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:29:19 by salibert          #+#    #+#             */
/*   Updated: 2016/11/13 16:14:15 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!(s1 && s2))
		return (NULL);
	i = 0;
	j = 0;
	if (!(str = (char *)malloc(sizeof(str) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
