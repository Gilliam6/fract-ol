SRCS = srcs/*.c

INCLUDE = includes/fractol.h libft/libft.h

NAME = fractol

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

${NAME}: ${INCLUDE}
		make -C libft
		gcc ${CFLAGS} libft/libft.a -I /usr/local/include ${SRCS} ${MLX} -o ${NAME}
		./${NAME}

all:	${NAME}

clean:
		make clean -C libft

fclean: clean
		make fclean -C libft
		${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean bonus re