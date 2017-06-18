NAME=rt

OS="$(shell uname)"

CCFLAGS= -Ofast -ffast-math -O3 -Wall -Wextra -Werror 

LIBFT= -lft -L srcs/libft -I srcs/libft

USAGE="Usage : ./rt"

LPTHREAD= -lpthread

FRAMEWORK= -framework OpenGL -framework AppKit

INCLUDE=-I include

SRCS=srcs/raytracing/mlx_put_pixel_to_image.c\
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
	srcs/event/free_button.c\
	srcs/math/light.c\
	srcs/math/vector_1.c\
	srcs/math/func_csg.c\
	srcs/math/vector_2.c\
	srcs/math/matrix_func.c\
	srcs/math/rotate_vec.c\
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
	srcs/init/init_parser.c\
	srcs/parser/set_arth_box.c\
	srcs/parser/func_nbr_parse.c\
	srcs/parser/set_camera_data.c\
	srcs/parser/set_apex.c\
	srcs/parser/set_perturbation.c\
	srcs/parser/set_angle.c\
	srcs/parser/set_axis.c\
	srcs/parser/set_color.c\
	srcs/parser/set_position.c\
	srcs/parser/set_rayon.c \
	srcs/parser/set_normal.c\
	srcs/parser/set_brillance.c\
	srcs/parser/set_rotation.c\
	srcs/parser/set_size.c\
	srcs/parser/set_msaa.c\
	srcs/parser/set_diffuse.c\
	srcs/parser/set_specular.c\
	srcs/parser/set_reflection.c\
	srcs/parser/set_refraction.c\
	srcs/parser/set_transparent.c\
	srcs/parser/set_type.c\
	srcs/parser/set_type_light.c\
	srcs/parser/set_shining.c\
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
	srcs/menu/draw_menu.c\
	srcs/menu/data_draw.c\
	srcs/menu/set_menu.c\
	srcs/event/event_mouse.c\
	srcs/event/event.c\
	srcs/event/free_all_list.c\
	srcs/menu/menu_all_scene.c\
	srcs/event/bmp.c\
	srcs/event/set_sepia.c\
	srcs/raytracing/set_primary_ray.c\
	srcs/raytracing/colors.c\
	srcs/raytracing/shining.c\
	srcs/event/set_rep.c\


OBJ=$(SRCS:.c=.o)

ifeq ($(OS), "Linux")
	TARGET= LINUX
	LIBMLX_SRCS= srcs/minilibx_linux
else
	TARGET= MACOS
	LIBMLX_SRCS= srcs/minilibx_macos
endif

LIBMLX= -lmlx -L $(LIBMLX_SRCS) -I $(LIBMLX_SRCS)


all: $(TARGET)

LINUX: $(OBJ)
	@make -C srcs/libft
	@make -C srcs/minilibx_linux
	@gcc -o $(NAME) $^ $(LIBFT) $(INCLUDE) $(LPTHREAD) \
		$(LIBMLX) $(CCFLAGS) -lX11 -lXext -lm \
		`pkg-config --libs --cflags x11` 

MACOS: $(OBJ)
	@make -C srcs/libft
	@make -C srcs/minilibx_macos
	@gcc -o $(NAME) $^ $(LIBFT) $(LPTHREAD) \
		$(LIBMLX) $(FRAMEWORK) $(CCFLAGS)

%.o: %.c
	@gcc -o $@ -c $< $(INCLUDE) $(CCFLAGS)

clean:
	@make clean -C srcs/libft
	@make clean -C $(LIBMLX_SRCS)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C srcs/libft
	@rm -rf $(NAME)

re: fclean all
