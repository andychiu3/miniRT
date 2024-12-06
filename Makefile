NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
INC = inc/

FILE = main
SRCS = $(addprefix srcs/, $(addsuffix .c, $(FILE)))
OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))
MLXLIB = libmlx.a


ifeq ($(shell uname), Darwin)
	MLX = minilibx_opengl
	MLXLINK += -L$(MLX) -Lmlx -lmlx -framework OpenGL -framework AppKit
	INC += $(MLX)
else ifeq ($(shell uname), Linux)
	MLX = minilibx_linux
	MLXLINK += -L$(MLX) -Lmlx -lmlx -lX11 -lXext -lm
	# INC += $(MLX)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLXLINK) 
#  $(MLX)/$(MLXLIB)

objs/%.o: srcs/%.c
	@mkdir -p objs/
	@make -C $(MLX)
	$(CC) $(CFLAGS) -I$(INC) -I$(MLX) -c $< -o $@

clean:
	rm -rf objs/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re