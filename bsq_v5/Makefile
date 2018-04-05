#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajohnson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/01 02:24:02 by ajohnson          #+#    #+#              #
#    Updated: 2018/04/01 09:06:32 by ajohnson         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bsq

SRC = bsq.c map.c func.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) -Wall -Wextra -Werror $(SRC)

clean:
	rm -rf *~

fclean: clean
	rm -rf $(NAME)

re: fclean all
