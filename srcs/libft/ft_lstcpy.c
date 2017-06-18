/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 07:43:40 by salibert          #+#    #+#             */
/*   Updated: 2017/04/22 07:43:57 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*cpy;

	cpy = NULL;
	while (lst)
	{
		ft_lstadd(&cpy, ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
	}
	return (cpy);
}
