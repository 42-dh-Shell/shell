# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 21:29:03 by daegulee          #+#    #+#              #
#    Updated: 2022/10/07 19:22:53 by daegulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= main.c \
					./signal/signal.c \
					./parser/lexer/auto_exps_util.c \
					./parser/lexer/do_0~3.c \
					./parser/lexer/do_4~8.c \
					./parser/lexer/do_9~13.c \
					./parser/lexer/do_14~17.c \
					./parser/lexer/get_char_status.c \
					./parser/lexer/lexer.c \
					./parser/lexer/list_util.c \
					./parser/lexer/debug_print.c \
					./parser/stack/stack.c \
					./parser/parser/parser.c \
					./parser/parser/lalr_table.c \
					./parser/parser/stack_util.c
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -g
LINKING_FLAGS = -lncurses -lreadline -L${HOME}/.brew/opt/readline/lib
COMFILE_FLAGS = -I${HOME}/.brew/opt/readline/include
CC = cc

NAME = mini

all	: $(NAME)

${NAME}: ${OBJS}
	make -C ./libft
	make -C ./gnl
	$(CC) $(LINKING_FLAGS) $(FLAGS) -o $(NAME) $(OBJS) ./libft/libft.a ./gnl/gnl.a

.c.o :
	$(CC) $(FLAGS) $(COMFILE_FLAGS) -c $< -o $@

all	: $(NAME)

clean	:
		make -C ./libft clean
		make -C ./gnl clean
		rm -f $(OBJS)

fclean	:	clean
		make -C ./libft fclean
		make -C ./gnl fclean
		rm -f $(NAME)

re	:
	make fclean 
	make all

.PHONY	:	all clean fclean re