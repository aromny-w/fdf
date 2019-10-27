# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 15:50:07 by aromny-w          #+#    #+#              #
#    Updated: 2019/10/27 19:41:26 by aromny-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = $(addprefix libft/, libft.a)

CC = gcc
FLAG = -Wall -Wextra -Werror -g
FW = -framework OpenGL -framework AppKit

SRC = fdf.c initmlx.c veccount.c vecparse.c destroystruct.c readinput.c \
	  printmatrix.c

OBJ = $(SRC:.c=.o)

%.o: %.c
		@$(CC) $(FLAG) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
		@make -C libft

$(NAME): $(OBJ)
		@$(CC) $(FLAG) $(OBJ) -o $(NAME) -L libft -lft -lmlx $(FW)

clean:
		@make clean -C libft
		@/bin/rm -f $(OBJ)

fclean: clean
		@make fclean -C libft
		@/bin/rm -f $(NAME)

re: fclean all
