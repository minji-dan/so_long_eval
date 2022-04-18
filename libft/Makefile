# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 19:02:52 by mkim2             #+#    #+#              #
#    Updated: 2022/04/16 19:02:55 by mkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	ft_strlen.c \
	ft_strcmp.c	\
	ft_strlcat.c	\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJS)
	ar rcs $@ $^

.PHONY : all, clean, fclean, re
