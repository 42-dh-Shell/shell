# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 21:29:03 by daegulee          #+#    #+#              #
#    Updated: 2022/09/28 12:50:13 by daegulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= main.c \
					./signal/signal.c \
					./parser/auto_exps_util.c \
					./parser/do_0~3.c \
					./parser/do_4~8.c \
					./parser/do_9~13.c \
					./parser/do_14~17.c \
					./parser/ft_util.c \
					./parser/ft_util2.c \
					./parser/get_char_status.c \
					./parser/lexer.c \
					./parser/list_util.c \
					./parser/debug_print.c 	

					  
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -lncurses -g
LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
COMFILE_FLAGS = -I${HOME}/.brew/opt/readline/include
CC = cc

NAME = mini

all	: $(NAME)

${NAME}: ${OBJS}
	$(CC) $(LINKING_FLAGS) $(FLAGS) -o $(NAME) $(OBJS) 

.c.o :
	$(CC) $(COMFILE_FLAGS) -c $< -o $@

all	: $(NAME)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:
	make fclean 
	make all

.PHONY	:	all clean fclean re