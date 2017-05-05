/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_rm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 07:41:44 by salibert          #+#    #+#             */
/*   Updated: 2017/05/05 18:42:52 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*elem_rm(t_list *head, void *value, int (*cmp)(void *a, void *b))
{
	t_list	*ret;

	if (!head)
		return (NULL);
	if (cmp(head->content, value))
	{
		ret = head->next;
		free(head->content);
		free(head);
		return (ret);
	}
	head->next = elem_rm(head->next, value, cmp);
	return (head);
}
