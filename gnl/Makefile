# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 16:37:07 by daegulee          #+#    #+#              #
#    Updated: 2022/09/09 16:47:14 by daegulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :	$(OBJS)
		ar -rcs $(NAME) $(OBJS)

.c.o :
		$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

clean :
		$(RM) $(OBJS)

fclean :	clean
		$(RM)  $(NAME)

re		:
		make fclean
		make all

.PHONY : all clean fclean re
