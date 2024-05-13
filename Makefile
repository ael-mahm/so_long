CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long
NAME_BONUS = so_long_bonus
LIBFT = libft/libft.a

SRCS = main.c			\
	   window.c			\
	   get_next_line.c	\
	   check_map.c		\
	   mlx_utlis.c		\
	   moves.c			\
	   check_map_2.c

SRCS_BONUS = main_bonus.c				\
			get_next_line.c				\
			check_map_bonus.c			\
			check_map_2_bonus.c			\
			mlx_utlis_bonus.c			\
			mlx_utlis_2_bonus.c			\
			moves_bonus.c				\
			window_bonus.c				\
			create_images_bonus.c		\
			enemy_bonus.c

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) ${MLX_FLAGS} $(LIBFT) -o $@

$(LIBFT):
	cd libft && make

all: $(NAME)

bonus: $(OBJS_BONUS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS_BONUS) ${MLX_FLAGS} $(LIBFT) -o $(NAME_BONUS)

clean:
	cd libft && make clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS) $(LIBFT)

re: fclean all