SRCS_LIST = burning_ship.c calculator.c\
		colorize.c draw.c\
		fractol.c hooks.c\
		init.c Julia.c\
		Mandelbroth.c utils.c
SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJ_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ_DIR = objects/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

LIBFT = libft/libft.a
HEADER = includes/fractol.h
HEADER_LIB = libft/libft.h

INCLUDES = -I$(HEADER) -I$(HEADER_LIB) -Imlx/mlx.h

NAME = fractol

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
		@gcc $(CFLAGS) libft/libft.a -I /usr/local/include $(INCLUDES) $(OBJ) $(MLX) -o $(NAME)
		@echo "\n$(NAME):$(GREEN).o files were created$(RESET)"
		@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
		@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
		@echo "$(GREEN)/$(RESET)\c"

$(LIBFT):
		@echo "$(NAME): $(GREEN)Creating libft.a...$(RESET)"
		@make -sC libft

clean:
		@echo "$(NAME):$(GREEN) libft is cleaned$(RESET)"
		@echo "$(NAME):$(GREEN) objects dir is cleaned$(RESET)"
		@make clean -C libft
		@rm -rf objects


fclean: clean
		@make fclean -C libft
		@${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re