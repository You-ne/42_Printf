# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 21:03:36 by yotillar          #+#    #+#              #
#    Updated: 2020/10/01 04:43:36 by yotillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = ./inc/ft_printf.h
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS =	./src/ft_printf.c \
		./src/ft_init.c \
		./src/ft_specials.c \
		./src/ft_flags_bonus.c \
		./src/ft_handlers.c \
		./src/ft_buff.c \
		./src/ft_display_num.c \
		./src/ft_display_char.c \
		./src/ft_conv_csp.c \
		./src/ft_conv_diux.c \
		./src/ft_conv_no_bonus.c \
		./src/ft_atoi_itoa_base.c \
		./src/ft_tools_num.c \
		./src/ft_tools_char.c \

BONUS_SRCS =	./src/ft_printf.c \
				./src/ft_init.c \
				./src/ft_flags_bonus.c \
				./src/ft_handlers.c \
				./src/ft_buff.c \
				./src/ft_display_num.c \
				./src/ft_display_char.c \
				./src/ft_specials.c \
				./src/ft_conv_csp.c \
				./src/ft_conv_diux.c \
				./src/ft_conv_no_bonus.c \
				./src/ft_atoi_itoa_base.c \
				./src/ft_tools_num.c \
				./src/ft_tools_char.c \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	ar -rcs $(NAME) $(OBJS)

bonus:	$(BONUS_OBJS) $(INCLUDE)
	ar -rcs $(NAME) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus : fclean bonus

main:
	gcc $(CFLAGS) main.c libftprintf.a
