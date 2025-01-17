NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror 
INC = -Iinc/
# -fsanitize=address

PARSE = parser env element obj panic checker
UTILS = isspace2space smlrDbl time
RENDER = ui render free_mlx_ptrs
MATH = vec vec2 vec3 interval
CALC = calc_ray color sphere plane cylinder cy_color 
DEBUG = prnt prnt_objs

FILE = main \
	$(addprefix parse/, $(PARSE)) \
	$(addprefix utils/, $(UTILS)) \
	$(addprefix render/, $(RENDER)) \
	$(addprefix math/, $(MATH)) \
	$(addprefix calc/, $(CALC)) \
	$(addprefix debug/, $(DEBUG))

SRCS = $(addprefix srcs/, $(addsuffix .c, $(FILE)))
OBJS = $(patsubst %.c, objs/%.o, $(notdir $(SRCS)))
vpath %.c srcs srcs/parse srcs/utils srcs/render srcs/math srcs/calc srcs/debug

MLXLIB = $(MLX)/libmlx.a
LIBFT = libft/libft.a

ifeq ($(shell uname), Darwin)
	MLX = minilibx_opengl
	MLXFLAGS += -framework OpenGL -framework AppKit
	MLXLINK += -L$(MLX) -lmlx -framework OpenGL -framework AppKit
	INC += -I$(MLX)
else ifeq ($(shell uname), Linux)
	MLX = minilibx_linux
	MLXFLAGS += -lX11 -lXext -lm
	MLXLINK += -L$(MLX) -Lmlx -lmlx -lX11 -lXext -lm
	INC += -I$(MLX)
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLXLIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXLIB) -o $(NAME) $(MLXFLAGS)
# $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLXLINK) 

objs/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	@make -C libft/

$(MLXLIB):
	@make -C $(MLX) 2> /dev/null

norm:
	norminette srcs/ libft/ inc/

clean:
	rm -rf objs/
	make -C $(MLX) clean
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re