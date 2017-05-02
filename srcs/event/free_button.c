#include "commun_struct.h"
#include "menu.h"

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
	mlx_destroy_image(menu->addr_mlx, menu->page->addr_img);
	free(menu->page);
	menu->page = NULL;
}
