NAME		=	so_long

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -g

HEADER		=	mlx.h

LIBFT		=	libft/libft.a

SRCS		=	maps_read.c so_long_utils.c so_long_utils_2.c so_long.c \
				maps_init.c initial_game.c\
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

OBJS		=	$(SRCS:%.c=%.o)

RM			=	rm -f

MLX_FLAGS	=	-L ./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

$(NAME):	$(OBJS)
			make -C ./minilibx_opengl_20191021
			make -C ./libft
			$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS) -Imlx -c $< -o $@

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			make fclean -C ./libft
			make clean -C ./minilibx_opengl_20191021

re:			fclean all

.PHONY: all clean fclean re