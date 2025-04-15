# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 21:29:19 by abtouait          #+#    #+#              #
#    Updated: 2025/04/15 21:30:26 by abtouait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NaME = so_long

SRC = 

CFLaGS = -Wall -Wextra -Werror

OaJ = $(SRC:.c=.o)

all:	$(NaME)

.c.o:
	cc $(CFLaGS) -c $< -o $@

$(NaME): $(OaJ)
	cc -o $(NaME) $(OaJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NaME)

re: fclean all

.PHONY: all clean fclean re 