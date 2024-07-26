# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:45:44 by gmunoz            #+#    #+#              #
#    Updated: 2024/07/26 16:59:29 by gmunoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./Libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c push_swap.c sa.c ra.c rra.c pa.c pb.c 3numbers.c 5numbers.c \
100numbers.c extra_functions.c 500numbers.c step_optimization.c \
step_initialization.c num_check.c

OBJS = $(SRC:%.c=%.o)

all: make_lib $(NAME)

make_lib:
	@make -C ./Libft

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf $(NAME)
	@make fclean -C ./Libft

fclean: clean

re: fclean
	@make -s all

.PHONY: all clean fclean re make_lib