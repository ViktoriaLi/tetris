#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 15:23:08 by vlikhotk          #+#    #+#              #
#    Updated: 2017/11/02 15:15:21 by vlikhotk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SFILES = check_figures.c coordinate.c create_field.c read_test.c lib_funcs.c

OFILES = check_figures.o coordinate.o create_field.o read_test.o lib_funcs.o

all: $(NAME)

$(NAME): $(OFILES)

clean:
	rm -f $(OFILES) *.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OFILES): %.o:%.c
	gcc -c -Wall -Wextra -Werror $(SFILES) fillit.h
	gcc $(OFILES) -o $(NAME)
