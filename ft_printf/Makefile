# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 10:33:17 by fbechtol          #+#    #+#              #
#    Updated: 2021/07/29 10:57:32 by fbechtol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _*_ Makefile _*_

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a
SOURCES = ft_print_i_d.c ft_print_c_p_s.c ft_print_u.c ft_printf.c \
	ft_specifier.c ft_print_x_xx_p.c
OBJECTS = $(SOURCES:.c=.o)
LIBFT_PATH = ./libft

.phony: all clean fclean re bonus fclean_libft

$(NAME): $(OBJECTS) target_libft
	ar -crs $@ $(OBJECTS) $(LIBFT_PATH)/*.o

all: $(NAME) target_libft

target_libft:
	make all -C libft/

clean:
	rm -f *.o

fclean: clean fclean_libft
	rm -f $(NAME)

fclean_libft:
	make fclean -C libft/

re: fclean all
