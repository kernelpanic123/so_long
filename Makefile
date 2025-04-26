# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 21:29:19 by abtouait          #+#    #+#              #
#    Updated: 2025/04/26 03:21:35 by abtouait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = get_next_line.c get_next_line_utils.c so_long.c parser.c parser_2.c flood_fill.c flood_fill_2.c window.c handle_keys.c free_it.c

CFLAGS = -Wall -Wextra -Werror -Iprintf

MLX_LIB = mlx/libmlx.a

PRINTF_LIB = printf/libftprintf.a

OBJ = $(SRC:.c=.o)

all: $(MLX_LIB) $(PRINTF_LIB) $(NAME)

$(MLX_LIB):
	make -C mlx

$(PRINTF_LIB):
	make -C printf

.c.o:
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(MLX_LIB)
	cc $(OBJ) $(PRINTF_LIB) -Lmlx -lmlx -lXext -lX11 -lm -o $(NAME)

clean:
	rm -f *.o
	make -C mlx clean
	make -C printf clean

fclean: clean
	rm -f $(NAME)
	rm -f mlx/libmlx.a
	rm -f printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re