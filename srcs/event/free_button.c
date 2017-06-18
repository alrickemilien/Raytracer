/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:53:55 by salibert          #+#    #+#             */
/*   Updated: 2017/05/03 15:53:56 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun_struct.h"
#include "menu.h"
#include "parser.h"

static void		del_button(void *data, size_t size)
{
	t_data_draw *tmp;

	(void)size;
	tmp = (t_data_draw*)data;
	if (tmp->path)
		free(tmp->path);
	free(data);
}

void			free_button(t_list **button, t_menu *menu)
{
	ft_lstdel(button, &del_button);
	free_image(menu->addr_mlx, &menu->page, menu->page->addr_img);
}
