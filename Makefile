include Includes.mk
CC = cc 
LINKERS= -L./libft/ -lft -L./minilibx-linux/ -lmlx_Linux -lmlx -lXext -lX11 -lm -g
CFLAGS = -Wall -Werror -Werror -I./includes/ -I./libft/includes/ -I./minilibx-linux/
SRC_DIR = src
OBJ_DIR = build
NAME = miniRT 
SRCSDIR = $(addprefix src/,$(SRCS))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCSDIR)) 
LIBFT= libft
MINILIB= minilibx-linux

all: libft minilibx-linux $(NAME)

libft:
	@make -C $(LIBFT)
minilibx-linux:
	@make -C $(MINILIB)
$(NAME):$(OBJS)
	@make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LINKERS) -o $(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/minirt.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@make -C libft fclean
	rm -f $(OBJS)
fclean:clean
	rm -f $(NAME) 
re: fclean all
.PHONY: all clean fclean re libft minilibx-linux
