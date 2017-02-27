/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:08 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/27 13:26:05 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	init_tab_str_description(t_env *env)
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
}

void	init_tab_function_description(t_env *env)
{
	env->check_description[0] = &set_position;
	env->check_description[1] = &set_rayon;
	env->check_description[2] = &set_color;
	env->check_description[3] = &set_normal;
	env->check_description[4] = &set_apex;
	env->check_description[5] = &set_axis;
	env->check_description[6] = &set_brillance;
	env->check_description[7] = &set_angle;
	env->check_description[8] = &set_rotation;
	env->check_description[9] = &set_size;
	env->check_description[10] = &set_diffuse;
	env->check_description[11] = &set_specular;
	env->check_description[12] = &set_reflection;
	env->check_description[13] = &set_refraction;
	env->check_description[14] = &set_transparent;
}

void	init_tab_str_object(t_env *env)
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
}

void	init_tab_function_object(t_env *env)
{
	env->set_object[SPHERE] = &set_sphere;
	env->set_object[CONE] = &set_cone;
	env->set_object[CYLINDRE] = &set_cylinder;
	env->set_object[PLAN] = &set_plan;
	env->set_object[CAMERA] = &set_camera;
	env->set_object[LIGHT] = &set_light;
	env->set_object[CSG] = &set_csg;
}
