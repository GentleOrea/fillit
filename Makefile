# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 19:18:21 by ygarrot           #+#    #+#              #
#    Updated: 2017/12/23 19:40:34 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT = libft/libft.a

SRC =  libft/libft.a \
		find_pos.c \
		parser.c \
		fillit.c \
		resolve.c \
		genmap.c \
		basics.c

FLAGS =  -Werror -Wall -Wextra 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		 @gcc -o $(NAME) $^

$(LIBFT):
	@make -C libft

%.o: %.c
	@gcc -o $@ $(FLAGS) -c $<

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	make -C libft fclean

re : fclean all

.PHONY: all, clean, re
