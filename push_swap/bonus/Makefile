# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 14:37:51 by fbechtol          #+#    #+#              #
#    Updated: 2021/12/13 15:49:14 by fbechtol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _*_ Makefile _*_

NAME = checker

CFLAGS = -Wall -Wextra -Werror
# -L followed by the relative path of the library to link it 
LIBFT_LINKING = -L ../libft -lft
CFILES = checker.c parse_bonus.c check_doubles_bonus.c is_sorted_bonus.c swap_ops_bonus.c push_ops_bonus.c \
		rotate_ops_bonus.c reverse_ops_bonus.c get_check_do_instructions.c

OBJECTS = $(patsubst %.c,%.o,$(CFILES))

$(NAME): $(OBJECTS)
	make -C ../libft
	gcc $(CFLAGS) -o $(NAME) $(OBJECTS) -lm $(LIBFT_LINKING)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

.phony: all
all: $(NAME)

.phony: clean
clean: clean_libft 
	rm -f *.o

.phony: fclean
fclean: clean fclean_libft
	rm -f $(NAME) *~

.phony: re
re: fclean all

# @ makes it silence
.phony: clean_libft
clean_libft:
	@make clean -C ../libft/

.phony: fclean_libft
fclean_libft:
	@make fclean -C ../libft/
