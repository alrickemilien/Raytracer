#ifndef RTV1_H
# define RTV1_H
# include "macro_key_mlx.h"
# include "commun_struct.h"

void		set_vignette_dimensions(t_env *e, t_limit *l);
t_color		shining(t_list *lights, t_ray *ray, double *norme);
t_color		moyenne(t_color *tab, int size);
t_color		scolor(t_color color, double k);
t_color		add_color(t_color current, t_color to_add, double t);
void		set_primary_ray(t_env *env, t_ray *ray, double j, double i);
void		free_data(void *content, size_t size);
void		free_tab(char ***tab, size_t size);
t_limit		ft_limit_thread(int nb, int width, int height);
void		ft_put_pos_select(t_env *env);
int			sphere(t_obj *sphere, t_ray *ray, double *t, t_list **inter);
int			hit_light(t_light light, t_ray *ray, double *t);
int			cylindre(t_obj *cylindre, t_ray *ray, double *t, t_list **inter);
int			box(t_obj *box, t_ray *ray, double *t, t_list **inter);
int			plan(t_obj *plan, t_ray *ray, double *t, t_list **inter);
int			csg(t_obj *csg, t_ray *ray, double *t, t_list **inter);
void		*raytracing(void *env);
int			cone(t_obj *cone, t_ray *ray, double *t, t_list **inter);
void		mlx_put_pixel_to_image(t_image *image, int x, int y,
			t_color color);
int			hit_light(t_light light, t_ray *ray, double *t);
int			key_press(int keycode, t_menu *menu);
int			red_cross(t_menu *menu);
int			red_cross_env(t_menu *menu);
void		end_program(t_menu *menu);
t_list		*f_i(t_list *a, t_list *b);
t_list		*f_d(t_list *a, t_list *b);
void		thread(pthread_t *t, void *(*funct)(void*), void *params, int size);
int			ft_mouse(int clic, int x, int y, t_menu *menu);
t_color		mapping(t_obj obj, t_surface s);
void		end_scene(t_menu *menu, void *addr_mlx, void *addr_win);
void		end_menu(
			t_menu *menu, void *addr_mlx, void *addr_win, void *addr_img);
void		ray_draw_data(t_menu *menu, t_env *env);
void		set_sepia(t_env *env, t_image *image);
void		ft_bitmap(t_image *image, char *path);

#endif
