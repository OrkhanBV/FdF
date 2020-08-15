# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 19:11:56 by ccred             #+#    #+#              #
#    Updated: 2019/12/05 02:32:13 by jremarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS=-framework OpenGL -framework AppKit

FLAGS=-Wall -Wextra -Werror
NAME=fdf
SRC = ./src/action.c ./src/get_map.c ./src/helper.c \
		./src/isometric_magic.c ./src/line_lena.c \
		./src/main.c

OBJ = $(SRC:.c=.o)

INCLUDES=libft/libft.a minilibx_macos/libmlx.a

all: $(NAME)

$(NAME):$(OBJ)
	make -C libft/ all
	make -C minilibx_macos/ all
	gcc  $(SRC) -o $(NAME)  $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
