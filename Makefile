# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:07:35 by hyunkyle          #+#    #+#              #
#    Updated: 2022/09/21 15:11:49 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS				= main.c \
					 
					  
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror
LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
COMFILE_FLAGS = -I${HOME}/.brew/opt/readline/include

CC = cc

NAME = mini

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(LINKING_FLAGS) $(FLAGS) -o $(NAME) $(OBJS) -I inc

.c.o :
	$(CC) $(CFLAGS) $(COMFILE_FLAGS) -c $< -o $@

all	: $(NAME)


clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	
	make fclean 
	make all

.PHONY	:	all clean fclean re
