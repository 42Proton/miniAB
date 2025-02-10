include Includes.mk
CC = cc 
LINKERS= -L./libft/ -lft -L./minilibx-linux/ -lmlx_Linux -lmlx -lXext -lX11 -lm -g
CFLAGS = -Wall -Werror -Werror -I./includes/ -I./libft/includes/ -I./minilibx-linux/
SRC_DIR = src
MATH_DIR = math

OBJ_DIR = build
NAME = miniRT 

SRCSDIR = $(addprefix src/,$(SRCS))
MATHDIR = $(addprefix math/,$(MATH))

SRCS_OBJ = $(SRCSDIR:%.c=$(OBJ_DIR)/%.o)
MATH_OBJ = $(MATHDIR:%.c=$(OBJ_DIR)/%.o)

LIBFT= libft
MINILIB= minilibx-linux

all: libft minilibx-linux $(NAME)

libft:
	@make -C $(LIBFT)
minilibx-linux:
	@make -C $(MINILIB)
$(NAME):$(SRCS_OBJ) $(MATH_OBJ)
	@make -C $(LIBFT)
	$(CC) $(SRCS_OBJ) $(MATH_OBJ) $(CFLAGS) $(LINKERS) -o $(NAME)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $< $(CFLAGS) -c  -o $@
clean:
	@make -C libft fclean
	rm -f $(SRCS_OBJ)
	rm -f $(MATH_OBJ)
	rm -rf $(OBJ_DIR)
fclean:clean
	rm -f $(NAME) 
re: fclean all
.PHONY: all clean fclean re libft minilibx-linux
