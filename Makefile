# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 12:17:42 by tbolsako          #+#    #+#              #
#    Updated: 2024/10/01 14:43:55 by tbolsako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker
CFLAGS = -Wall -Wextra -Werror

SRC = input_validity.c main.c operation_push.c operation_reverse_rotate.c \
	operation_rotate.c operation_swap.c sort_3_to_5.c sort_6_plus.c \
	stack_helper.c stack_create.c utils_1.c utils_2.c utils_3.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cc $(CFLAGS)  -o $(NAME) $(OBJ)

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER):
	@cc $(CFLAGS) $(OBJ) -o $(CHECKER)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
