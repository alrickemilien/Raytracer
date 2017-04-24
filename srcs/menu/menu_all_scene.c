#include "rtv1.h"
#include "menu.h"
#include "init.h"
#include "parser.h"

static void		data_while(t_data_draw *data,
				t_list *tmp, t_env *env, t_menu *menu)
{
	while (tmp)
	{
		free_list(&env->list, &env->camera, &env->light, env);
		data = (t_data_draw*)(tmp->content);
		ft_bzero(env->tab_ray, sizeof(t_ray) * 600 * 400);
		if ((env->fd = open(data->path, O_RDWR)) == -1)
		{
			tmp = tmp->next;
			continue;
		}
		if (!parser(env))
		{
			data->error = 1;
			data->picture = menu->error;
			draw_menu(*data, menu->page);
			tmp = tmp->next;
			continue;
		}
		(!env->camera) ? init_default_camera(env) : sort_camera(env);
		raytracing((void*)env);
		data->picture = env->image;
		draw_menu(*data, menu->page);
		tmp = tmp->next;
		close(env->fd);
	}
}

void			ray_draw_data(t_menu *menu, t_env *env)
{
	t_list		*tmp;
	t_data_draw	*data;

	tmp = menu->button;
	data = (t_data_draw*)(tmp->content);
	draw_menu(*data, menu->page);
	tmp = menu->button->next;
	data_while(data, tmp, env, menu);
	mlx_destroy_image(env->addr_mlx, env->image->addr_img);
	free(env->tab_ray);
	free_list(&env->list, &env->camera, &env->light, env);
	ft_bzero(env->select, sizeof(t_select));
}
