# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 15:50:07 by aromny-w          #+#    #+#              #
#    Updated: 2019/10/27 00:38:36 by aromny-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = $(addprefix libft/, libft.a)

CC = gcc
FLAG = -Wall -Wextra -Werror
FW = -framework OpenGL -framework AppKit

SRC = fdf.c initstruct.c isvalid.c destroystruct.c readinput.c

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
