# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/12 16:38:13 by vimucchi          #+#    #+#              #
#    Updated: 2019/02/27 16:42:28 by vimucchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_PATH = ./
OBJ_PATH = ./
INC = -I /usr/local/include
LDFLAGS = -L ./minilibx -L ./libft
LDLIBS = -lmlx -framework OpenGL -framework AppKit -lft
CFLAGS = -g3 -Wall -Wextra -Werror 
CC = gcc
SRC = main.c \
	parser.c \
	draw.c \

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@echo "\033[32m>>\033[0m \033[33mStarting library & $(NAME)\033[32m compilation\033[0m \033[0m"
	@make -C libft
	@make -C minilibx
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\033[32m>> $(NAME) correctly created ... OK\033[0m"

%.o: %.c fdf.h
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@echo "\033[32mObjects \033[31mremoved\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "\033[32m$(NAME) \033[31mremoved\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
