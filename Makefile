NAME		=	miniRT

LIBFT		=	libft.a

LIBFT_DIR	=	libft

MLX_DIR		=	mlx_linux

MLX		=	libmlx_Linux.a

SRC		:=	$(addprefix srcs/,		\
			main.c				\
			ft_atof.c			\
			get_scene_from_file.c		\
			get_next_line.c			\
			image.c				\
			vector_calculation.c		\
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
			validation_functions.c		\
			get_scene_from_file_objects.c	\
			get_scene_from_file_utils.c		\
			render_engine_lighting.c		\
			image_to_file.c				\
			scene_object_creation_destruction.c	\
			vector_calculation_color.c		\
			render_engine_objects_creation.c	\
			render_engine_objects_intersections.c	\
			validation_scene_objects.c		\
			validation_scene_utils.c		\
			validation_scene_processor.c)

HEADER		=	ft.h

OBJ		=	$(SRC:.c=.o)

INC_FL		=	-L$(LIBFT_DIR) -I$(LIBFT_DIR)	\
			-L$(MLX_DIR) -I$(MLX_DIR) 	\
			-lm -lbsd -lX11 -lXext		\
			-Iincludes

CC		=	gcc -Wall -Wextra -Werror $(INC_FL) 

.PHONY:		all clean fclean re

all:		$(NAME)

%.o:		%.c $(HEADER)
		$(CC) -g -c $< -o ${<:.c=.o}

$(LIBFT_DIR)/(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/$(MLX):
			$(MAKE) -C $(MLX_DIR)
			cp $(MLX_DIR)/$(MLX) .

$(NAME):	$(OBJ) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
			$(CC) -o $(NAME) $(OBJ) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX) $(INC_FL)

clean:
			-rm -f $(OBJ)

fclean:		clean
			-rm -f $(MLX)
			-rm -f $(NAME)

re:			fclean all
