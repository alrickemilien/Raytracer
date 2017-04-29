#ifndef PARSER_H
# define PARSER_H
# include "commun_struct.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <stdio.h>

# define INVALID_SIZE_NBR "Invalid number, number must be less than 17 digit"
# define INVALID_DECIMAL "RT_v1 doesn't not support precison more than 4 digit"
# define INVALID_FORMA_NBR "Invalid number, number bad formated"
# define INVALID_PARAM "Invalid parametre, some character are not valid"
# define INVALID_NBR_OF_PARAM "Invalid param, some param need only 3 values"
# define INVALID_PARAM_FORMAT "Invalid formatage of parameter"
# define INVALID_HEXA_FORMAT "Hexa numbers start with 0x"
# define INVALID_PARAMS "Invalid parametres"
# define INVALID_HEXA_SIZE "Hexa number must be less than 8 digits"
# define INVALID_EXTENTION "Invalid extention file [scene].rt"
# define INVALID_DESCRIPTION "Invalid description of an object"
# define INVALID_FORMAT_FILE "Invalid file format"
# define USAGE "Usage : ./rtv1 no source or one source"
# define BAD_INDENT "Bad indentation"
# define INVALID_OBJECT "There is more than one valid caracteristic precised"
# define INVALID_INT "Invalid int"
# define INVALID_NORMAL "Normale of a plan cannot be null"
# define INVALID_CAMERA "Camera cannot watch itself"
# define BAD_COEFF "Coeffs like specular or diffuse must be between 0 and 1"
# define INVALID_LIGHT "Light specularity + diffuse cant be greater than one"
# define INVALID_ANGLE "Angle must be lower than 180 degrees"
# define INVALID_FILE "The file is not valid"
# define INVALID_DIRECTORY "Argument is a directory"
# define INVALID_NO_OBJ "List object null"
# define INVALID_LOOKAT "Camera matrix looking straight up/down : not defined"
# define INVALID_CSG "More than 2 objects in CSG object"
# define INVALID_TEXTURE "Error : Texture not found or not valid"
# define INVALID_RESIZE_TEXTURE "Error : R_T invalid, R_T (0.1 to 1000)"
# define INVALID_XPM_EXTENTION "WARNING : Invalid extention texture.xpm"

# define POSITION "position:"
# define RAYON "rayon:"
# define COLOR "color:"
# define NORMAL "normal:"
# define TO "to:"
# define FROM "from:"
# define APEX "apex:"
# define AXIS "axis:"
# define BRILLANCE "brillance:"
# define ANGLE "angle:"
# define ROTATION "rotation:"
# define INTENSITY "intensity:"
# define SIZE "size:"
# define SPECULAR "specular:"
# define DIFFUSE "diffuse:"
# define REFLECTION "reflection:"
# define REFRACTION "refraction:"
# define TRANSPARENT "transparent:"
# define TYPE "type:"
# define TRANSLATION "translation:"
# define AMBIENT "ambient:"
# define TEXTURE "texture:"
# define RESIZE "resize_texture:"
# define PERTURBATION "perturbation:"
# define SHINING "shining:"

t_color				split_color(unsigned long color);
int					check_indent(char *str, int n);
int					parse_error(char *str);
int					fill_data(char *tmp, double *data);
int					check_floating_number(char *str);
int					fill_data_vec(char *str, t_vector *vec);
int					check_data_type_color(char *str);
int					error_file(char *file);
int					fill_int_data(char *str, int *data);
int					check_end_data(char *str);

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
int					set_rot(t_env *env, char *tmp,
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
int					set_type_light(char *tmp,
		t_light *new, t_pars_object *index);
int					set_shining(char *tmp,
		t_light *new, t_pars_object *index);
int					set_resize_texture(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);
int					set_texture(t_env *env, char *tmp,
		t_obj *new, t_pars_object *index);

void				set_translation_csg(t_vector translation, t_list *csg);
int					set_camera(t_env *env, t_list **list_obj);
int					set_scene(t_env *env, t_list **list_obj);
int					set_light(t_env *env, t_list **list_obj);
int					set_cone(t_env *env, t_list **list_obj);
int					set_cylinder(t_env *env, t_list **list_obj);
int					set_sphere(t_env *env, t_list **list_obj);
int					set_plan(t_env *env, t_list **list_obj);
int					set_csg(t_env *env, t_list **list_obj);
int					set_box(t_env *env, t_list **list_obj);
void				set_camera_data(t_camera *camera);
void				set_boxs_plans(t_list **list, t_obj obj);
int					parser(t_env *env);
int					error(t_env *env, char *str);
void				recycle(char **old_ptr, char *new_ptr);
void				set_default_camera(t_camera *new);
int					clean_error(char **str);
void				free_list(
					t_list **obj, t_list **camera, t_list **t_3, t_env *env);
void				free_button(t_list **button, t_menu *menu);

#endif
