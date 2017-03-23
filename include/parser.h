/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:54:50 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/23 15:00:00 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

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
# define INVALID_RESIZE_TEXTURE "Error : resize_texture invalid, resize_texture: (0.1 to 1000)"
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

int				check_indent(char *str, int n);
int				parse_error(char *str);
int				fill_data(char *tmp, double *data);
int				check_floating_number(char *str);
int				fill_data_vec(char *str, t_vector *vec);
int				check_data_type_color(char *str);
int				check_data_type_nbr(char *str, int k);
int				error_file(char *file);
int				fill_int_data(char *str, int *data);
int				check_end_data(char *str);

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

#endif
