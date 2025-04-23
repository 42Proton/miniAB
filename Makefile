include Includes.mk
CC = cc 

LIBFT= libft
MLXLIB= ./MLX42

LINKERS= -L./$(LIBFT)/ -lft -L$(MLXLIB)/build/ -lmlx42 -ldl -lglfw -pthread -lm
CFLAGS = -Wall -Werror -Werror -g -std=c99 -Ofast -I./includes/ -I./$(LIBFT)/includes/ -I$(MLXLIB)/include

OBJ_DIR = build
NAME = miniRT 

SRCSDIR = $(addprefix src/,$(SRCS))
TUPLESDIR = $(addprefix tuples/,$(TUPLES))
COLDIR = $(addprefix colors/,$(COLORS))
MATRIXDIR =$(addprefix matrix/,$(MATRIX))
RAYSDIR =$(addprefix rays/,$(RAYS))
INCLUDES_DIR = $(addprefix includes/,$(INCLUDES))

SRCS_OBJ = $(SRCSDIR:%.c=$(OBJ_DIR)/%.o)
TUPLES_OBJ = $(TUPLESDIR:%.c=$(OBJ_DIR)/%.o)
COL_OBJ = $(COLDIR:%.c=$(OBJ_DIR)/%.o)
MATRIX_OBJ = $(MATRIXDIR:%.c=$(OBJ_DIR)/%.o)
RAYS_OBJ = $(RAYSDIR:%.c=$(OBJ_DIR)/%.o)

all: libft mlx42 $(NAME)

libft:
	@make -C $(LIBFT)
mlx42:
	@cmake $(MLXLIB) -B $(MLXLIB)/build && make -C $(MLXLIB)/build -j4
$(NAME):$(SRCS_OBJ) $(TUPLES_OBJ) $(COL_OBJ) $(MATRIX_OBJ) $(RAYS_OBJ)
	@make -C $(LIBFT)
	$(CC) $(SRCS_OBJ) $(TUPLES_OBJ) $(COL_OBJ) $(MATRIX_OBJ) $(RAYS_OBJ) $(CFLAGS) $(LINKERS) -o $(NAME)
$(OBJ_DIR)/%.o: %.c  $(INCLUDES_DIR)
	@mkdir -p $(dir $@)
	$(CC) $< $(CFLAGS) -c -o $@
clean:
	@make -C libft fclean
	@rm -rf $(MLXLIB)/build
	@rm -f $(SRCS_OBJ)
	@rm -f $(TUPLES_OBJ)
	@rm -f $(COL_OBJ)
	@rm -rf $(MATRIX_OBJ)
	@rm -rf $(OBJ_DIR)

fclean:clean
	@rm -f $(NAME) 
re: fclean all

.PHONY: all clean fclean re libft minilibx-linux
