# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:50:54 by hyunkyle          #+#    #+#              #
#    Updated: 2022/08/02 21:07:05 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = 			get_next_line_bonus.c \
				get_next_line_utils_bonus.c  \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

NAME = libgnl.a

$(NAME)	: $(OBJS)
	ar -rc $(NAME) $(OBJS)
	
.c.o :
	$(CC) -o $@ -c $< -I .

all	: $(NAME)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
