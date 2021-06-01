SRCS			= 	main.c mandelbrot.c image_pixel_put.c keys.c \
					complex.c screen_elements.c color_pixel.c choose_type.c \
					julia.c message.c mandelbar.c
DIR_S			= src
SOURCE			=$(addprefix $(DIR_S)/,$(SRCS))
OBJS			= $(SOURCE:.c=.o)
HEADER			= ./includes/fractol.h
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -I $(HEADER)

NAME			= fractol

all:			$(NAME)

%.o:		%.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJS)
				make -C ./mlx/
				make -C ./libft/
				$(CC) -o $(NAME )$@ $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -Llibft -lft
				-mv ./mlx/libmlx.dylib ./

clean:
				$(RM) $(OBJS)
				make -C ./libft/ clean
				-mv libmlx.dylib ./mlx/
				make -C ./mlx/ clean

fclean:			clean
				$(RM) $(NAME)
				make -C ./libft/ fclean
				make -C ./mlx/ clean

re:				fclean all

.PHONY:			all clean fclean re