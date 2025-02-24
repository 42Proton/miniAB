include Includes.mk
CC = cc 
LINKERS= -L./libft/ -lft -L./minilibx-linux/ -lmlx_Linux -lmlx -lXext -lX11 -lm
CFLAGS = -Wall -Werror -Werror -g -I./includes/ -I./libft/includes/ -I./minilibx-linux/
SRC_DIR = src
TUPLE_DIR = tuples
MATRIX_DIR = matrix

OBJ_DIR = build
NAME = miniRT 

SRCSDIR = $(addprefix src/,$(SRCS))
TUPLESDIR = $(addprefix tuples/,$(TUPLES))
COLDIR = $(addprefix colors/,$(COLORS))
MATRIXDIR =$(addprefix matrix/,$(MATRIX))

SRCS_OBJ = $(SRCSDIR:%.c=$(OBJ_DIR)/%.o)
TUPLES_OBJ = $(TUPLESDIR:%.c=$(OBJ_DIR)/%.o)
COL_OBJ = $(COLDIR:%.c=$(OBJ_DIR)/%.o)
MATRIX_OBJ = $(MATRIXDIR:%.c=$(OBJ_DIR)/%.o)

LIBFT= libft
MINILIB= minilibx-linux

all: libft minilibx-linux $(NAME)

libft:
	@make -C $(LIBFT)
minilibx-linux:
	@make -C $(MINILIB)
$(NAME):$(SRCS_OBJ) $(TUPLES_OBJ) $(COL_OBJ) $(MATRIX_OBJ)
	@make -C $(LIBFT)
	$(CC) $(SRCS_OBJ) $(TUPLES_OBJ) $(COL_OBJ) $(MATRIX_OBJ) $(CFLAGS) $(LINKERS) -o $(NAME)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $< $(CFLAGS) -c  -o $@
clean:
	@make -C libft fclean
	@make -C $(MINILIB) clean
	rm -f $(SRCS_OBJ)
	rm -f $(TUPLES_OBJ)
	rm -f $(COL_OBJ)
	rm -rf $(MATRIX_OBJ)
	rm -rf $(OBJ_DIR)

fclean:clean
	rm -f $(NAME) 
re: fclean all

.PHONY: all clean fclean re libft minilibx-linux
