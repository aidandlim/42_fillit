# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 15:59:10 by dlim              #+#    #+#              #
#    Updated: 2019/05/23 13:52:16 by dlim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCES = sources/*.c
LIBFT = sources/libft/*.c
OBJECTS = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SOURCES) $(LIBFT) -I ./includes
	gcc -o $(NAME) $(OBJECTS)

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all