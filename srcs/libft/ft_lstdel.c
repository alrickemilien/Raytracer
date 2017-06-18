/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:56:05 by salibert          #+#    #+#             */
/*   Updated: 2016/11/13 13:49:19 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list1;
	t_list *list2;

	list1 = *alst;
	while (list1)
	{
		list2 = list1->next;
		del(list1->content, list1->content_size);
		free(list1);
		list1 = list2;
	}
	*alst = NULL;
}
