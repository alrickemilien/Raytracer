/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:55:11 by salibert          #+#    #+#             */
/*   Updated: 2017/05/03 18:03:29 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "init.h"
#include "menu.h"
#include <math.h>

static void		init_tab_str_description(t_env *env)
{
	if (!(env->tab_str_description = (
					char**)malloc(sizeof(char*) * NBR_DESCRIPTION)))
		merror();
	env->tab_str_description[0] = ft_strdup(POSITION);
	env->tab_str_description[1] = ft_strdup(RAYON);
	env->tab_str_description[2] = ft_strdup(COLOR);
	env->tab_str_description[3] = ft_strdup(NORMAL);
	env->tab_str_description[4] = ft_strdup(APEX);
	env->tab_str_description[5] = ft_strdup(AXIS);
	env->tab_str_description[6] = ft_strdup(BRILLANCE);
	env->tab_str_description[7] = ft_strdup(ANGLE);
	env->tab_str_description[8] = ft_strdup(ROTATION);
	env->tab_str_description[9] = ft_strdup(SIZE);
	env->tab_str_description[10] = ft_strdup(DIFFUSE);
	env->tab_str_description[11] = ft_strdup(SPECULAR);
	env->tab_str_description[12] = ft_strdup(REFLECTION);
	env->tab_str_description[13] = ft_strdup(REFRACTION);
	env->tab_str_description[14] = ft_strdup(TRANSPARENT);
	env->tab_str_description[15] = ft_strdup(TYPE);
	env->tab_str_description[16] = ft_strdup(TRANSLATION);
	env->tab_str_description[17] = ft_strdup(TEXTURE);
	env->tab_str_description[18] = ft_strdup(RESIZE);
	env->tab_str_description[19] = ft_strdup(PERTURBATION);
}

static void		init_tab_function_description(t_env *env)
{
	env->check_description[0] = &set_position;
	env->check_description[1] = &set_rayon;
	env->check_description[2] = &set_color;
	env->check_description[3] = &set_normal;
	env->check_description[4] = &set_apex;
	env->check_description[5] = &set_axis;
	env->check_description[6] = &set_brillance;
	env->check_description[7] = &set_angle;
	env->check_description[8] = &set_rot;
	env->check_description[9] = &set_size;
	env->check_description[10] = &set_diffuse;
	env->check_description[11] = &set_specular;
	env->check_description[12] = &set_reflection;
	env->check_description[13] = &set_refraction;
	env->check_description[14] = &set_transparent;
	env->check_description[15] = &set_type;
	env->check_description[16] = &set_translation;
	env->check_description[17] = &set_texture;
	env->check_description[18] = &set_resize_texture;
	env->check_description[19] = &set_perturbation;
}

static void		init_tab_str_object(t_env *env)
{
	if (!(env->tab_str_object = (char**)malloc(sizeof(char*) * NBR_OBJECT)))
		merror();
	env->tab_str_object[SPHERE] = ft_strdup("sphere:");
	env->tab_str_object[CONE] = ft_strdup("cone:");
	env->tab_str_object[CYLINDRE] = ft_strdup("cylinder:");
	env->tab_str_object[PLAN] = ft_strdup("plan:");
	env->tab_str_object[CAMERA] = ft_strdup("camera:");
	env->tab_str_object[LIGHT] = ft_strdup("light:");
	env->tab_str_object[CSG] = ft_strdup("csg:");
	env->tab_str_object[SCENE] = ft_strdup("scene:");
	env->tab_str_object[BOX] = ft_strdup("box:");
}

static void		init_tab_function_object(t_env *env)
{
	env->set_object[SPHERE] = &set_sphere;
	env->set_object[CONE] = &set_cone;
	env->set_object[CYLINDRE] = &set_cylinder;
	env->set_object[PLAN] = &set_plan;
	env->set_object[CAMERA] = &set_camera;
	env->set_object[LIGHT] = &set_light;
	env->set_object[CSG] = &set_csg;
	env->set_object[SCENE] = &set_scene;
	env->set_object[BOX] = &set_box;
}

void			init_env(t_env *env)
{
	env->addr_mlx = mlx_init();
	env->fov = M_PI_4;
	env->scale = tan(M_PI_4 * 0.5);
	env->select = (t_select*)ft_memalloc(sizeof(t_select));
	env->image = init_image(env->addr_mlx, 400, 200);
	env->tab_ray = (t_ray*)ft_memalloc(sizeof(t_ray) * 1000 * 1000);
	env->image_aspect_ratio = 400 / 200;
	env->nb_thread = 9;
	init_tab_str_object(env);
	init_tab_function_object(env);
	init_tab_str_description(env);
	init_tab_function_description(env);
}
