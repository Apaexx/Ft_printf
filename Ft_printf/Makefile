# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynejmi <ynejmi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 15:55:24 by ynejmi            #+#    #+#              #
#    Updated: 2020/02/06 16:03:53 by ynejmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
OUTPUT=*.o

SRC=	ft_atoi.c	\
		ft_itoa.c	\
		ft_printf.c	\
		treats.c	\

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar -rc $(NAME) *.o
	ranlib $(NAME)

bonus:
	gcc -Wall -Wextra -Werror -c $(SRC) $(SRCB)
	ar -rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
