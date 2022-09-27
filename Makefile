# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 21:29:03 by daegulee          #+#    #+#              #
#    Updated: 2022/09/27 21:58:13 by daegulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= ./parser/auto_exps_util.c \
					./parser/do_0~3.c \
					./parser/do_4~8.c \
					./parser/do_9~13.c \
					./parser/do_14~17.c \
					./parser/ft_util.c \
					./parser/ft_util2.c \
					./parser/get_char_status.c \
					./parser/lexer.c \
					./parser/list_util.c 	
					  
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc
AR = ar rcs

NAME = lexer.a

all	: $(NAME)

${NAME}: ${OBJS}
		${AR} $@ ${OBJS}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all	: $(NAME)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:
	make fclean 
	make all

.PHONY	:	all clean fclean re