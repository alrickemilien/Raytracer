.PHONY: re all clean fclean

CCFLAGS= -Wall -Wextra -Werror -Ofast -ffast-math

LIBFT= -lft -L srcs/libft -I srcs/libft

LPTHREAD= -lpthread

LIBMLX= -lmlx -L srcs/minilibx_macos -I srcs/minilibx_macos

INCLUDE= -I include

FRAMEWORK= -framework OpenGL -framework AppKit

SRCS=\
	srcs/raytracing/mlx_put_pixel_to_image.c\
	srcs/raytracing/raytracing.c\
	srcs/raytracing/split_color.c\
	srcs/raytracing/thread.c\
	srcs/raytracing/shadow.c\
	srcs/init/main.c\
	srcs/init/init_func.c\
	srcs/raytracing/get_specularity.c\
	srcs/raytracing/get_diffuse.c\
	srcs/raytracing/get_surface_caracter.c\
	srcs/raytracing/get_reflection.c\
	srcs/raytracing/get_refraction.c\
	srcs/raytracing/set_color_coeff.c\
	srcs/raytracing/beers_law.c\
	srcs/raytracing/fresnel.c\
	srcs/event/end_program.c\
	srcs/event/free_data.c\
	srcs/event/free_tab.c\
	srcs/event/event.c\
	srcs/math/light.c\
	srcs/math/vector_1.c\
	srcs/math/vector_2.c\
	srcs/math/matrix_func.c\
	srcs/math/get_surface_normal.c\
	srcs/math/sphere.c\
	srcs/math/plan.c\
	srcs/math/cone.c\
	srcs/math/box.c\
	srcs/math/cylindre.c\
	srcs/math/csg.c\
	srcs/math/intersection.c\
	srcs/math/difference.c\
	srcs/math/rotation.c\
	srcs/init/init_default_camera.c\
	srcs/parser/recycle.c\
	srcs/parser/error.c\
	srcs/parser/sort_camera.c\
	srcs/init/init_parser.c\
	srcs/parser/func_nbr_parse.c\
	srcs/parser/set_camera_data.c\
	srcs/parser/set_apex.c\
	srcs/parser/set_angle.c\
	srcs/parser/set_axis.c\
	srcs/parser/set_color.c\
	srcs/parser/set_position.c\
	srcs/parser/set_rayon.c \
	srcs/parser/set_normal.c\
	srcs/parser/set_brillance.c\
	srcs/parser/set_rotation.c\
	srcs/parser/set_size.c\
	srcs/parser/set_diffuse.c\
	srcs/parser/set_specular.c\
	srcs/parser/set_reflection.c\
	srcs/parser/set_refraction.c\
	srcs/parser/set_transparent.c\
	srcs/parser/set_type.c\
	srcs/parser/set_translation.c\
	srcs/parser/set_camera.c\
	srcs/parser/set_scene.c\
	srcs/parser/set_light.c\
	srcs/parser/set_box.c\
	srcs/parser/set_sphere.c\
	srcs/parser/set_cone.c\
	srcs/parser/set_cylinder.c\
	srcs/parser/set_csg.c\
	srcs/parser/set_plan.c\
	srcs/parser/func_parse.c\
	srcs/parser/parser.c\
	srcs/math/invert_matrix.c\
	srcs/parser/set_resize.c\
	srcs/parser/set_texture.c\
	srcs/math/mapping_uv.c\

OBJ=$(SRCS:.c=.o)

NAME=rt

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./srcs/libft
	@make -C ./srcs/minilibx_macos
	@gcc -o $@ $^ $(INCLUDE) $(LIBFT) $(LIBMLX) $(LPTHREAD) $(FRAMEWORK) $(CCFLAGS)

%.o: %.c
	@gcc -o $@ -c $< $(INCLUDE) $(CCFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
