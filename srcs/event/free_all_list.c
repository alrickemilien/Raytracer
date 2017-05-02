#include "commun_struct.h"

void			free_image(void *addr_mlx, t_image **image, void *addr_img)
{
	mlx_destroy_image(addr_mlx, addr_img);
	free(*image);
	*image = NULL;
}

void			ft_objdel(t_list **obj, void *addr_mlx)
{
	t_obj		*tmp_obj;
	t_list		*list;
	t_list		*tmp_list;

	list = *obj;
	while (list)
	{
		if ((tmp_obj = (t_obj*)(list->content)))
		{
			if (tmp_obj->texture)
				free_image(addr_mlx, &tmp_obj->texture, tmp_obj->texture->addr_img);
			if (tmp_obj->texture)
				free(tmp_obj->texture);
			if (tmp_obj->csg)
				ft_objdel(&tmp_obj->csg, addr_mlx);
			if (tmp_obj->matrix)
				free(tmp_obj->matrix);
			tmp_list = list;
			list = list->next;
			free(tmp_list->content);
			tmp_list->content = NULL;
			free(tmp_list);
		}
	}
	*obj = NULL;
}

static void		ft_lstdel_s(t_list **alst)
{
	t_list		*list1;
	t_list		*list2;

	list1 = *alst;
	while (list1)
	{
		list2 = list1->next;
		free(list1->content);
		list1->content = NULL;
		free(list1);
		list1 = list2;
	}
	*alst = NULL;
}

static void		del_camera(void *data, size_t size)
{
	t_camera	*tmp;

	(void)size;
	tmp = (t_camera*)data;
	if (tmp->matrix)
		free(tmp->matrix);
	free(data);
}

void			free_list(t_list **obj, t_list **cam, t_list **t_3, t_env *env)
{
	ft_objdel(obj, env->addr_mlx);
	ft_lstdel(cam, &del_camera);
	ft_lstdel_s(t_3);
}
