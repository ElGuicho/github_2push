# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:45:44 by gmunoz            #+#    #+#              #
#    Updated: 2024/05/17 18:04:55 by gmunoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = gcc	

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = push_swap.c sa.c ra.c rra.c pa.c pb.c 3numbers.c 5numbers.c \
100numbers.c 100num_functions.c 500numbers.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header file
HEADER = push_swap.h

# Executable name
NAME = push_swap.a

# Default NAME
all: $(NAME)

# Compile source files into object files
$(LIBFT):
	@$(MAKE) -C Libft

# Link object files into the executable
$(NAME): $(OBJS)
	@$(MAKE) -C Libft
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)
	
#	ar -rcs $(NAME) $(OBJS)
#	ranlib $(NAME)

# Clean up generated files
clean:
	@$(MAKE) clean -C Libft
	rm -f $(OBJS)

#
fclean:
	@$(MAKE) fclean -C Libft
	rm -f $(NAME) $(OBJS)

# Re-compile everything
re: fclean all

.PHONY: all clean fclean re