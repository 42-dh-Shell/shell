# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:50:54 by hyunkyle          #+#    #+#              #
#    Updated: 2022/09/22 19:36:26 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =					ft_strcmp.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

$(NAME)	: $(OBJS)
	ar -rc $(NAME) $(OBJS)
.c.o :
	$(CC) -o $@ -c $<

all	: $(NAME)

clean	:
		rm -f $(OBJS) $(BNS_OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
