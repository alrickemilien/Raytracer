/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:17:22 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/28 16:27:31 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "macro_key_mlx.h"
# include "commun_struct.h"

void				free_data(void *content, size_t size);
void				free_tab(char ***tab, size_t size);
void				sort_camera(t_env *env);
t_limit		ft_limit_thread(int nb, int width, int height);
void				ft_put_pos_select(t_env *env);
int					sphere(t_obj *sphere, t_ray *ray, double *t, t_list **inter);
int					hit_light(t_light light, t_ray *ray, double *t);
int					cylindre(t_obj *cylindre, t_ray *ray, double *t, t_list **inter);
int					box(t_obj *box, t_ray *ray, double *t, t_list **inter);
int					plan(t_obj *plan, t_ray *ray, double *t, t_list **inter);
int					csg(t_obj *csg, t_ray *ray, double *t, t_list **inter);
void				*raytracing(void *env);
int					cone(t_obj *cone, t_ray *ray, double *t, t_list **inter);
void				mlx_put_pixel_to_image(t_image *image, int x, int y,
		t_color color);
int					hit_light(t_light light, t_ray *ray, double *t);
int					key_press(int keycode, t_env *env);
int					red_cross(void *param);
void				end_program(t_env *env);
t_list				*function_intersection(t_list *a, t_list *b);
t_list				*function_difference(t_list *a, t_list *b);
void				thread(pthread_t *t, void *(*funct)(void*), void *params, int size);
int ft_mouse(int clic, int x, int y, t_menu *menu);
t_color mapping(t_obj obj, t_surface s);

#endif