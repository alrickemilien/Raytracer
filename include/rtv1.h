/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:17:22 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/28 13:14:22 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../srcs/libft/libft.h"
# include "macro_key_mlx.h"
# include "../srcs/minilibx_macos/mlx.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <pthread.h>
# include "vector.h"
# include <stdio.h>
# include "parser.h"
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define WIN_WIDTH_HALF 500
# define WIN_HEIGHT_HALF 500
# define WIN_WIDTH_QUART 250
# define WIN_HEIGHT_QUART 250
# define WIN_WIDTH_OCT 125
# define WIN_HEIGHT_OCT 125
# define B 0x00FFFFFF
# define NBR_OBJECT 9
# define NBR_DESCRIPTION 20
# define ZERO 0.000000001
# define LIGHT_PTR ((t_light*)(tmp_light->content))
# define NB_THREAD 8

typedef struct		s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_color;

typedef struct		s_pivot_gauss
{
	int		i;
	int		j;
	int		k;
	int		pivot;
	double	pivotsize;
	double	f;
	double	tmp;
}					t_pivot_gauss;

typedef	struct		s_image
{
	void		*image;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct		s_ray
{
	t_vector		org;
	t_vector		dir;
	double			t;
	double			coeff;
	int				thread;
	t_list			*inter;
}					t_ray;

typedef struct		s_light
{
	t_vector		org;
	double			intensity;
	double			specular;
	double			diffuse;
	int				(*hit_light)(
			struct s_light light,
			t_ray *ray, double *t);
}					t_light;

typedef struct		s_matrix_rot
{
	double			a;
	double			b;
	double			c;
	double			d;
	double			e;
	double			f;
	double			ad;
	double			bd;
}					t_matrix_rot;

enum {
	SPHERE,
	PLAN,
	CONE,
	CYLINDRE,
	CAMERA,
	LIGHT,
	CSG,
	SCENE,
	BOX
};

enum {
	SIN,
	TAN,
	NO_PERTURBATION
};

enum {
	UNION,
	INTERSECTION,
	DIFFERENCE,
};

typedef struct		s_obj
{
	t_image			*texture;
	double			resize_texture;
	t_vector		pos;
	double			r;
	int				mat;
	double			albedo;
	t_vector		n;
	t_color			color;
	int				(*func_obj)(struct s_obj *tmp,
			t_ray *ray, double *t, t_list **inter);
	int				etat;
	t_vector		axis;
	t_vector		apex;
	t_vector		rotation;
	double			angle;
	double			height;
	int				brillance;
	double			size;
	double			specular;
	double			diffuse;
	double			refraction;
	int				reflection;
	t_vector		absorbtion;
	double			transparent;
	int				intersection;
	int				type;
	int				perturbation;
	double			*matrix;
	int				inter_type;
	struct s_obj	*pointeur[8];
	t_vector		translation;
	t_vector		bounds[2];
	t_list			*csg;
}					t_obj;

typedef struct	s_inter
{
	double		t;
	t_obj		*obj;
}				t_inter;

typedef struct	s_range
{
	t_inter		t1;
	t_inter		t2;
}				t_range;

typedef struct		s_limit
{
	int				x;
	int				y;
	int				max_x;
	int				max_y;
	int				tmp_x;
}					t_limit;

typedef struct		s_camera
{
	int				num;
	t_vector		pos;
	t_vector		to;
	double			*matrix;
	struct s_camera *next;
}					t_camera;

typedef struct		s_select
{
	t_obj			*o;
	t_camera		*c;
}					t_select;

typedef struct		s_surface
{
	t_vector		intersection;
	t_vector		n;
	double			spec;
	double			diffuse;
	double			refraction;
	double			transparent;
}					t_surface;

typedef	struct		s_env
{
	int				nb_thread;
	pthread_t		*tab_thread;
	void			*tab_env;	
	void			*addr_mlx;
	void			*addr_win;
	t_image			*image;
	t_vector		cursor;
	int				fd;
	int				thread_index;
	double			image_aspect_ratio;
	double			scale;
	int				command;
	int				lock;
	int				reflection;
	double			zoom;
	t_list			*light;
	double			k;
	t_ray			*tab_ray;
	char			**tab_str_object;
	int				(*set_object[NBR_OBJECT])(struct s_env *env, t_list **list_obj);
	char			**tab_str_description;
	int				(*check_description[NBR_DESCRIPTION])(
			struct s_env *env, char *str,
			t_obj *new, t_pars_object *index);
	t_list			*list;
	t_list			*camera;
	int				nbr_cam;
	double			fov;
	t_select		*select;
}					t_env;

int					set_color(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_axis(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_apex(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_position(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_angle(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_brillance(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_rayon(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_normal(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_rotation(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_size(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_diffuse(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_specular(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_reflection(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_refraction(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_transparent(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_type(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_translation(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_perturbation(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_resize_texture(t_env *env, char *tmp, t_obj *new, t_pars_object *index);

int					set_camera(t_env *env, t_list **list_obj);
int					set_scene(t_env *env, t_list **list_obj);
int					set_light(t_env *env, t_list **list_obj);
int					set_cone(t_env *env, t_list **list_obj);
int					set_cylinder(t_env *env, t_list **list_obj);
int					set_sphere(t_env *env, t_list **list_obj);
int					set_plan(t_env *env, t_list **list_obj);
int					set_csg(t_env *env, t_list **list_obj);
int					set_box(t_env *env, t_list **list_obj);
int					parser(t_env *env);
int					set_texture(t_env *env, char *tmp, t_obj *new, t_pars_object *index);

void				init_default_camera(t_env *env);
pthread_t			*init_thread(int nb_thread);
t_image		*init_image(void *mlx, int width, int height);
void				init_env_values(t_env *env);
void				init_tab_str_description(t_env *env);
void				init_tab_function_description(t_env *env);
void				init_tab_str_object(t_env *env);
void				init_tab_function_object(t_env *env);

void				free_data(void *content, size_t size);
void				free_tab(char ***tab, size_t size);
t_vector			get_surface_normal(t_vector intersection,
		t_obj *tmp, t_ray ray);
void				rotate_object(t_obj *object, t_vector *vector);
void				sort_camera(t_env *env);
void				recycle(char **old_ptr, char *new_ptr);

t_limit				ft_limit_thread(int nb);
void				ft_put_pos_select(t_env *env);
int					sphere(t_obj *sphere, t_ray *ray, double *t, t_list **inter);
int					hit_light(t_light light, t_ray *ray, double *t);
int					cylindre(t_obj *cylindre, t_ray *ray, double *t, t_list **inter);
int					box(t_obj *cylindre, t_ray *ray, double *t, t_list **inter);
int					plan(t_obj *plan, t_ray *ray, double *t, t_list **inter);
int					csg(t_obj *csg, t_ray *ray, double *t, t_list **inter);
void				*raytracing(void *env);
int					cone(t_obj *cone, t_ray *ray, double *t, t_list **inter);
t_color				split_color(unsigned long color);
void				mlx_put_pixel_to_image(t_image *image, int x, int y,
		t_color color);
int					hit_light(t_light light, t_ray *ray, double *t);
int					error(t_env *env, char *str);
int					key_press(int keycode, t_env *env);
int					ft_mouse(int button, int x, int y, t_env *env);
int					red_cross(void *param);
void				set_camera_data(t_camera *camera);
void				end_program(t_env *env);
double				shadow(t_env *env, t_ray ray, double norme);
int					merror(void);
double				get_specularity(t_vector intersection, t_vector n,
		t_vector light_dir, t_obj *obj);
double				get_diffuse(t_vector n, t_vector light_dir);
t_surface				get_surface_caracter(t_ray ray, t_obj *tmp);
t_ray				get_reflection(t_surface s, t_ray ray);
t_ray				get_refraction(t_surface s, t_ray ray);
double  			*set_camera_matrix(
							t_vector vec_forward, t_vector vec_up,
							t_vector vec_right, t_vector from);
void				set_color_coeff(t_env *env, t_surface s,
									t_obj *tmp, double *t);
double				fresnel(t_ray ray, t_surface s);
t_color				beers_law(t_color color, t_obj *obj, t_surface s, t_ray ray);
void				swap(double *a, double *b);
int					between(double t, double n1, double n2);
double				range(double a, double b);
t_list				*function_intersection(t_list *a, t_list *b);
t_list				*function_difference(t_list *a, t_list *b);
int					betweex(double t, double n1, double n2);
double				*set_rotation_matrix(double *matrix, double alpha,
											double beta, double gamma);
double				*invert_matrix(double *m);
void				thread(pthread_t *t, void *(*funct)(void*), void *params, int size);
t_color mapping(t_obj obj, t_surface s);

#endif
