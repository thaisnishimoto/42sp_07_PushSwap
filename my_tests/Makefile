#*************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 20:22:45 by tmina-ni          #+#    #+#              #
#    Updated: 2023/10/18 17:09:48 by tmina-ni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
SRC = tester_push_swap.c ../src/rotate.c
LIBFT = -L../libft -lft

all: push_swap $(NAME)
	./$(NAME)
	make --no-print fclean

push_swap:
	$(MAKE) -C ../ 

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -lrt -lm $(LIBFT)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all push_swap clean fclean re
