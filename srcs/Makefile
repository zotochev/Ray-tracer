# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 21:46:16 by mscot             #+#    #+#              #
#    Updated: 2021/02/08 22:18:10 by mscot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

LIBFT	=	libft.a

MLX_DIR	=	mlx_mms

MLX		=	libmlx.dylib

SRC		:=	$(addprefix srcs/,		\
			main.c					\
			ft_atof.c				\
			get_scene_from_file.c	\
			get_next_line.c			\
			image.c					\
			vector_calculation.c	\
			vector_calculation_products.c	\
			look_at_matrix.c		\
			objects_sphere.c		\
			render_engine.c			\
			objects_triangle.c		\
			objects_plane.c			\
			objects_cylinder.c		\
			object_square.c			\
			mlx_processor.c			\
			mlx_check_screen.c		\
			validation_functions.c			\
			get_scene_from_file_objects.c	\
			get_scene_from_file_utils.c		\
			render_engine_lighting.c		\
			image_to_file.c					\
			scene_object_creation_destruction.c		\
			vector_calculation_color.c				\
			render_engine_objects_creation.c		\
			render_engine_objects_intersections.c	\
			validation_scene_objects.c				\
			validation_scene_utils.c				\
			validation_scene_processor.c)


HEADER	=	ft.h

OBJ		=	$(SRC:.c=.o)

CC		=	gcc -Wall -Wextra -Werror -Iincludes -Imlx_mms -Ilibft


.PHONY:		all clean fclean re

all:		$(NAME)

%.o:		%.c $(HEADER)

libft/libft.a:
			$(MAKE) -C libft

libmlx.dylib:
			$(MAKE) -C $(MLX_DIR)
			cp $(MLX_DIR)/$(MLX) .

$(NAME):	$(OBJ) libft/libft.a $(MLX)
			$(CC) -Llibft -lft -L$(MLX_DIR) -framework OpenGL \
				-framework AppKit -o $(NAME) $(OBJ) libft/$(LIBFT) $(MLX_DIR)/$(MLX)

clean:
			-rm -f $(OBJ)

fclean:		clean
			-rm -f $(MLX)
			-rm -f $(NAME)

re:			fclean all
