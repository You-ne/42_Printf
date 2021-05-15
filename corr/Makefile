# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 11:09:40 by edjavid           #+#    #+#              #
#    Updated: 2021/04/24 11:43:47 by edjavid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  ft_printf.c \
        ft_char.c \
        ft_hex.c \
        ft_pointer.c \
        ft_utils.c \
        ft_utils2.c \
        ft_dec.c \
        ft_u.c \

SURO =  ft_printf.o \
        ft_char.o \
        ft_hex.o \
        ft_pointer.o \
        ft_utils.o \
        ft_utils2.o \
        ft_dec.o \
        ft_u.o \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) ft_printf.h $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(SURO)
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
