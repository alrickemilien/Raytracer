#ifndef COMMUN_STRUCT_H
# define COMMUN_STRUCT_H
# include "../srcs/libft/libft.h"
# include "../srcs/minilibx_macos/mlx.h"
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
# define NBR_DESCRIPTION 19
# define ZERO 0.000000001
# define LIGHT_PTR ((t_light*)(tmp_light->content))

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	double		norme;
}				t_vector;

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


typedef struct	s_pars_object
{
	int			to;
	int			from;
	int			position;
	int			brillance;
	int			angle;
	int			rayon;
	int			color;
	int			apex;
	int			axis;
	int			normal;
	int			rotation;
	int			intensity;
	int			size;
	int			diffuse;
	int			specular;
	int			reflection;
	int			refraction;
	int			transparent;
	int			type;
	int			translation;
	int			resize_texture;
	int			texture;
}				t_pars_object;

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

typedef struct s_menu
{
    void    *addr_mlx;
    void    *addr_win;
	t_env	*env;
	t_image *page;
	t_list	*button;
	int		y_scroll;
	int		etat;
}				t_menu;

int					merror(void);

#endif