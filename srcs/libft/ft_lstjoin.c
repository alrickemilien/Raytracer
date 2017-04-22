/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 07:44:22 by salibert          #+#    #+#             */
/*   Updated: 2017/04/22 07:45:21 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstjoin(t_list *head, t_list *to_join)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_join;
}
