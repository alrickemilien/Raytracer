#include "rtv1.h"

int				red_cross(void *param)
{
	t_env		*env;

	env = (t_env*)param;
	end_program(env);
	return (0);
}

int ft_mouse(int clic, int x, int y, t_menu *menu)
{
	x = y;
	int size_scroll;
	int	size_y;

	size_y = menu->page->height;
	size_scroll = 50;
	if (clic == 4)
	{
		if (menu->y_scroll + size_scroll < 0)
			mlx_put_image_to_window(menu->addr_mlx, menu->addr_win,
			menu->page->image, 0, menu->y_scroll += size_scroll);
	}
	else if (clic == 5)
	{
		if (menu->y_scroll - size_scroll >= -(size_y - 1000))
			mlx_put_image_to_window(menu->addr_mlx, menu->addr_win,
			menu->page->image, 0, menu->y_scroll -= size_scroll);
	}
	return (1);
}