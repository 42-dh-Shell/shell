# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:07:35 by hyunkyle          #+#    #+#              #
#    Updated: 2022/09/27 16:46:24 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS				= main.c \
					./signal/signal.c \
					./parser/parser_list_utils.c \
					./parser/parser_token_utils.c \
					./parser/parser_token_utils1.c \
					./parser/parser_token_utils2.c \
					./parser/parser_utils.c \
					./parser/parser_while_utils.c \
					./parser/parser.c \
					 
					  
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -lncurses -g
LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
COMFILE_FLAGS = -I${HOME}/.brew/opt/readline/include

CC = cc

NAME = mini

$(NAME)	: $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(LINKING_FLAGS) $(FLAGS) -o $(NAME) $(OBJS) ./libft/libft.a

.c.o :
	$(CC) $(CFLAGS) $(COMFILE_FLAGS) -c $< -o $@

all	: $(NAME)

clean	:
		make -C ./libft clean
		rm -f $(OBJS)

fclean	:	clean
		make -C ./libft fclean
		rm -f $(NAME)

re	:
	make -C ./libft re
	make fclean 
	make all

.PHONY	:	all clean fclean re
