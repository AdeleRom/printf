# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniki <lniki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 15:18:46 by lniki             #+#    #+#              #
#    Updated: 2020/03/17 11:19:32 by lniki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = mparser.c print_c.c print_s.c print_per.c print_p.c print_d.c print_o.c \
	   print_u.c print_x.c print_xx.c float_1.c float_2.c ft_spec_f.c

OBJECTS = *.o

INCLUDES = ft_printf.h

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(SRCS) lib/*.c
	ar rc $(NAME) *.o 
	ranlib $(NAME) 
	/bin/rm -f *.o

clean:
	/bin/rm -f *.o
	/bin/rm -f lib/*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all