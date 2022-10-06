# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:50:54 by hyunkyle          #+#    #+#              #
#    Updated: 2022/10/06 13:26:21 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =					ft_strcmp.c \
						ft_isalpha.c \
						ft_isdigit.c \
						ft_strdup.c	\
						ft_strlcpy.c \
						ft_strlen.c \
						ft_substr.c \
						ft_split.c \
						ft_calloc.c \
						ft_atoi.c \
						ft_memset.c \
						ft_exit.c \
						ft_putchar_fd.c \
						ft_putstr_fd.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

$(NAME)	: $(OBJS)
	ar -rc $(NAME) $(OBJS)
.c.o :
	$(CC) $(FLAGS) -o $@ -c $<

all	: $(NAME)

clean	:
		rm -f $(OBJS) $(BNS_OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
