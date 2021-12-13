# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 14:37:51 by fbechtol          #+#    #+#              #
#    Updated: 2021/12/13 15:46:43 by fbechtol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _*_ Makefile _*_

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror
# -L followed by the relative path of the library to link it 
LIBFT_LINKING = -L ../libft -lft
CFILES = push_swap.c parse.c check_doubles.c is_sorted.c swap_ops.c push_ops.c \
		rotate_ops.c reverse_ops.c sort_short_lists.c sort.c get_lis.c \
		brute_search.c brute_search_utils.c brute_back.c brute_back_utils.c

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
