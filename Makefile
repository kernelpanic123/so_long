# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 21:29:19 by abtouait          #+#    #+#              #
#    Updated: 2025/04/18 21:09:02 by abtouait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = get_next_line.c get_next_line_utils.c so_long.c parser.c parser_2.c flood_fill.c flood_fill_2.c

CFLAGS = -Wall -Wextra -Werror

#MLX_LIB = mlx/libmlx.a

OBJ = $(SRC:.c=.o)

all: $(MLX_LIB) $(NAME)

#$(MLX_LIB):
	#make -C mlx

.c.o:
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME)

clean:
	rm -f *.o
	#make -C mlx clean

fclean: clean
	rm -f $(NAME)
	#rm -f mlx/libmlx.a

re: fclean all

.PHONY: all clean fclean re N