# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 10:33:17 by fbechtol          #+#    #+#              #
#    Updated: 2021/12/09 12:55:27 by fbechtol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _*_ Makefile _*_

NAME = fdf

CFLAGS = -Wall -Wextra -Werror
# -L followed by the relative path of the library to link it 
MLX_LINKING = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit
LIBFT_LINKING = -L ./libft -lft
CFILES = fdf_main.c get_data.c put_data.c draw.c draw_utils.c bresenham.c \
		keys.c
B_CFILES = fdf_main.c get_data.c put_data.c draw.c draw_utils.c bresenham.c \
		keys_bonus.c

$(NAME): mlx compile_libft
	gcc -g $(CFLAGS) -o $(NAME) $(CFILES) $(MLX_LINKING) -lm $(LIBFT_LINKING)

.phony: all
all: $(NAME) bonus

.phony: bonus
bonus: mlx compile_libft
	gcc $(CFLAGS) -o $(NAME)_bonus $(B_CFILES) $(MLX_LINKING) -lm $(LIBFT_LINKING)

.phony: compile_libft
compile_libft:
	make libft.a -C ./libft

.phony: mlx
mlx:
	make -C ./minilibx_macos

.phony: clean
clean: clean_libft clean_mlx clean_bonus
	rm -f *.o

.phony: fclean
fclean: clean fclean_libft fclean_bonus
	rm -f $(NAME) *~ $(NAME)_bonus

.phony: re
re: fclean all

.phony: clean_bonus
clean_bonus: clean_libft clean_mlx
	rm -f *_bonus.o

.phony: fclean_bonus
fclean_bonus: clean_bonus fclean_libft
	rm -f *_bonus~ $(NAME)_bonus

# @ makes it silence
.phony: clean_libft
clean_libft:
	@make clean -C libft/

.phony: fclean_libft
fclean_libft:
	@make fclean -C libft/

.phony: clean_mlx
clean_mlx:
	@make clean -C ./minilibx_macos
