include Includes.mk
CC = cc 
LINKERS= -L./libft/ -lft -L./minilibx-linux/ -lmlx_Linux -lmlx -lXext -lX11 -lm
CFLAGS = -Wall -Werror -Werror -g -I./includes/ -I./libft/includes/ -I./minilibx-linux/
SRC_DIR = src
MATH_DIR = math

OBJ_DIR = build
NAME = miniRT 

SRCSDIR = $(addprefix src/,$(SRCS))
MATHDIR = $(addprefix math/,$(MATH))
COLDIR = $(addprefix colors/,$(COLORS))

SRCS_OBJ = $(SRCSDIR:%.c=$(OBJ_DIR)/%.o)
MATH_OBJ = $(MATHDIR:%.c=$(OBJ_DIR)/%.o)
COL_OBJ = $(COLDIR:%.c=$(OBJ_DIR)/%.o)

LIBFT= libft
MINILIB= minilibx-linux

all: libft minilibx-linux $(NAME)

libft:
	@make -C $(LIBFT)
minilibx-linux:
	@make -C $(MINILIB)
$(NAME):$(SRCS_OBJ) $(MATH_OBJ) $(COL_OBJ)
	@make -C $(LIBFT)
	$(CC) $(SRCS_OBJ) $(MATH_OBJ) $(COL_OBJ) $(CFLAGS) $(LINKERS) -o $(NAME)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $< $(CFLAGS) -c  -o $@
clean:
	@make -C libft fclean
	@make -C $(MINILIB) clean
	rm -f $(SRCS_OBJ)
	rm -f $(MATH_OBJ)
	rm -f $(COL_OBJ)
	rm -rf $(OBJ_DIR)
fclean:clean
	rm -f $(NAME) 
re: fclean all
.PHONY: all clean fclean re libft minilibx-linux
