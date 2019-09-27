NAME = FdF

FLAGS = -Wall -Wextra -Werror

LIB = -lmlx -L $(MLX_DIR) -framework OpenGL -framework AppKit
INC = -I $(MLX_HEAD)

MLX = $(MLX_DIR) libmlx.a
MLX_DIR = ./minilibx_macos
MLX_HEAD = $(MLX_DIR)

SRC = main.c

OBJ = $(SRC:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
		@gcc $(FLAGS) $(LIB) $(INC) $(OBJ) -o $(NAME)
		@./$(NAME)

$(OBJ):
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(MLX):
	@$(MAKE) -sC $(MLX_DIR)
