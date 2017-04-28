/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_of.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 07:55:15 by salibert          #+#    #+#             */
/*   Updated: 2017/04/22 07:55:34 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ptr_of(t_list *lst, void *data, int (*cmp)(void *a, void *b))
{
	while (lst)
	{
		if (cmp(data, lst->content))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
