# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srachdi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 18:44:27 by srachdi           #+#    #+#              #
#    Updated: 2022/11/15 11:11:50 by srachdi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar
ARFLAGS = cr

INCLUDES = ./ft_printf.h


SRCS = ft_printf.c nbrFuncs.c strFuncs.c 
OBJS = $(SRCS:.c=.o)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY : all clean fclean re 
