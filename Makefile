SRCS_LIST = burning_ship.c calculator.c\
		colorize.c draw.c\
		fractol.c hooks.c\
		init.c Julia.c\
		Mandelbroth.c utils.c
SRCS_DIR = srcs/
SRCS_DIR_BONUS = srcs_b/

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

BONUS_LIST = burning_ship.c calculator.c\
             		colorize.c draw_bonus.c\
             		fractol.c hooks.c\
             		init.c Julia.c\
             		Mandelbroth.c utils.c
BONUS_SRCS = $(addprefix $(SRCS_DIR_BONUS), $(BONUS_LIST))


OBJ_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ_DIR = objects/
OBJ_DIR_BONUS = objects_bonus/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

OBJ_LIST_BONUS = $(patsubst %.c, %.o, $(BONUS_LIST))
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(OBJ_LIST_BONUS))

LIBFT = libft/libft.a
HEADER = includes/fractol.h
HEADER_LIB = libft/libft.h
HEADER_BONUS = includes/fractol_bonus.h

INCLUDES = -I$(HEADER) -I$(HEADER_LIB) -Imlx/mlx.h
INCLUDES_BONUS = -I$(HEADER_BONUS) -I$(HEADER_LIB) -Imlx/mlx.h


NAME = fractol
BONUS = bonus

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

$(OBJ_DIR)%.o: $(SRCS_DIR_BONUS)%.c $(HEADER)
		@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
		@echo "$(GREEN)/$(RESET)\c"

$(LIBFT):
		@echo "$(NAME): $(GREEN)Creating libft.a...$(RESET)"
		@make -sC libft

$(BONUS): $(LIBFT) $(OBJ_DIR_BONUS) $(OBJ_BONUS)
		@gcc $(CFLAGS) libft/libft.a -I /usr/local/include $(INCLUDES_BONUS) $(OBJ_BONUS) $(MLX) -o $(BONUS)
		@echo "\n$(BONUS):$(BONUS).o files were created$(RESET)"
		@echo "$(BONUS): $(GREEN)$(BONUS) was created$(RESET)"

$(OBJ_DIR_BONUS):
		@mkdir -p $(OBJ_DIR_BONUS)
		@echo "$(BONUS): $(GREEN)$(OBJ_DIR_BONUS) was created$(RESET)"

$(OBJ_DIR_BONUS)%.o: $(SRCS_DIR_BONUS)%.c $(HEADER_BONUS)
		@$(CC) $(CFLAGS) -c $(INCLUDES_BONUS) $< -o $@
		@echo "$(GREEN)/$(RESET)\c"

clean:
		@echo "$(NAME):$(GREEN) libft is cleaned$(RESET)"
		@echo "$(NAME):$(GREEN) objects dir is cleaned$(RESET)"
		@make clean -C libft
		@rm -rf objects
		@rm -rf objects_bonus


fclean: clean
		@make fclean -C libft
		@${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re