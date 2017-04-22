/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_rm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 07:41:44 by salibert          #+#    #+#             */
/*   Updated: 2017/04/22 07:42:17 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*elem_rm(t_list *head, t_list *to_rm)
{
	t_list	*ret;

	ret = NULL;
	if (!head)
		return (NULL);
	if (head == to_rm)
	{
		ret = head->next;
		free(head->content);
		free(head);
		return (ret);
	}
	head->next = elem_rm(head->next, to_rm);
	return (head);
}
