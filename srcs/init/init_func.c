#include "rtv1.h"

pthread_t	*init_thread(int nb_thread)
{
	pthread_t *tab_thread;
	int nb;

	nb = -1;
	if (!(tab_thread = (pthread_t*)ft_memalloc(sizeof(pthread_t) * nb_thread)))
		merror();
	return (tab_thread);
}

t_image		*init_image(void *mlx, int width, int height)
{
	t_image *image;

	if (!(image = (t_image *)ft_memalloc(sizeof(t_image))))
		parse_error("malloc init_image");
	image->width = width;
    image->height = height;
	image->image = mlx_new_image(mlx, image->width, image->height);
	image->data = mlx_get_data_addr(image->image,
			&(image->bpp), &(image->sizeline), &(image->endian));
	image->bpp = image->bpp / 8;
    return (image);
}