# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 14:37:51 by fbechtol          #+#    #+#              #
#    Updated: 2022/01/24 13:32:14 by fbechtol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _*_ Makefile _*_

NAME = pipex

CFLAGS = -Wall -Wextra -Werror #-ggdb3 -fsanitize=address
# -L followed by the relative path of the library to link it 
LIBFT_LINKING = -L ../libft -lft
CFILES = pipex_bonus.c parsing_bonus.c parsing_utils_bonus.c \
		piping_bonus.c piping_utils_bonus.c pipe_here_doc_bonus.c \
		err_exit_bonus.c
OBJECTS = $(patsubst %.c,%.o,$(CFILES))

$(NAME): $(OBJECTS) 
	make -C ../libft
	gcc $(CFLAGS) -o $(NAME) $(OBJECTS) -lm $(LIBFT_LINKING)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

.phony: bonus
bonus: $(NAME)

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
