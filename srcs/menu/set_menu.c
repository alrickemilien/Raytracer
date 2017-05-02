#include "menu.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "init.h"
#include "parser.h"
#include "rtv1.h"

static int			check_stat(char *path, int *nb, int *marge, t_menu *menu)
{
	struct stat		filestat;
	t_data_draw		new_button;

	if (*path == '.')
		return (0);
	path = ft_strjoin("scene/", path);
	lstat(path, &filestat);
	if (!S_ISREG(filestat.st_mode))
	{
		ft_strdel(&path);
		return (0);
	}
	new_button = params_draw_scene(menu, *nb, *marge, path);
	ft_lstadd(&menu->button, ft_lstnew(&new_button, (sizeof(t_data_draw))));
	*nb += 1;
	if (*nb % 2 == 0)
		*marge += 1;
	return (1);
}

static int			set_menu(t_menu *menu)
{
	t_data_draw		new_button;
	DIR				*dir;
	struct dirent	*file;
	int				nb_data_draw;
	int				marge;

	nb_data_draw = 0;
	marge = 0;
	if (!(dir = opendir("scene")))
	{
		perror("Error ");
		exit(-1);
	}
	while ((file = readdir(dir)) && (nb_data_draw < 10000))
		if (!(check_stat(file->d_name, &nb_data_draw, &marge, menu)))
			continue;
	marge = 100 + 135 * nb_data_draw;
	if (!(menu->page = init_image(menu->addr_mlx, WIN_WIDTH,
		(WIN_HEIGHT < marge ? marge : WIN_HEIGHT))))
		merror();
	new_button = params_data_draw(menu);
	ft_lstadd(&menu->button, ft_lstnew(&new_button, (sizeof(t_data_draw))));
	closedir(dir);
	return (nb_data_draw);
}

void		reset_menu(t_menu *menu)
{
	t_env	*env;

	env = menu->env;
	free_button(&menu->button, menu);
	set_menu(menu);
		ft_putendl("salut1");

	free_image(env->addr_mlx, &env->image, env->image->addr_img);
	env->image = init_image(env->addr_mlx, 400, 200);
	ft_bzero(env->tab_ray, sizeof(t_ray) * 1000 * 1000);
	env->image_aspect_ratio = 400 / 200;
	env->nb_thread = 9;
	free_list(&env->list, &env->camera, &env->light, env);
	ray_draw_data(menu, env);
	mlx_put_image_to_window(
			menu->addr_mlx, menu->addr_win, menu->page->addr_img, 0, 0);
	loop_menu(menu);
}

t_menu				*creat_menu(void)
{
	t_menu			*new_menu;
	int				nb_data_draw;

	nb_data_draw = 0;
	if (!(new_menu = (t_menu*)ft_memalloc(sizeof(t_menu))))
		return (NULL);
	new_menu->addr_mlx = mlx_init();
	new_menu->background = init_texture(
		new_menu->addr_mlx, "textures/skybox/the_universe.xpm");
	set_menu(new_menu);
	new_menu->error = init_texture(
		new_menu->addr_mlx, "textures/plan/error.xpm");
	new_menu->addr_win = mlx_new_window(
		new_menu->addr_mlx, WIN_WIDTH, WIN_HEIGHT, "Menu_RT");
	return (new_menu);
}
