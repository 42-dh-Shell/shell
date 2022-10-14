# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 21:29:03 by daegulee          #+#    #+#              #
#    Updated: 2022/10/14 11:01:47 by daegulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= ./body/main.c \
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
					./parser/parser/stack_util.c \
					./parser/tree/tree.c \
					./parser/tree/act_r5,1.c \
					./parser/tree/act_r11,10,9,7,6.c \
					./parser/tree/act_r16,15,14,13,12.c \
					./parser/tree/act_r21,20,19,18,17.c \
					./parser/tree/act_r28,25,24,23,22.c \
					./parser/tree/act_r33,32,31,30,29.c \
					./parser/tree/debug_tree.c 
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LINKING_FLAGS = -lreadline $(LD_CLUSTER)
LD_CLUSTER=-L${HOME}/.brew/opt/readline/lib
LD_M1=-L/opt/homebrew/opt/readline/lib
COMFILE_FLAGS = $(CD_CLUSTER) -MD 
CD_CLUSTER=-I${HOME}/.brew/opt/readline/include
CD_M1=-I/opt/homebrew/opt/readline/include
CC = cc
DEPS = ${OBJS:.o=.d}
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
		rm -f $(DEPS)

fclean	:	clean
		make -C ./libft fclean
		make -C ./gnl fclean
		rm -f $(NAME)

re	:
	make fclean 
	make all

.PHONY	:	all clean fclean re

-include ${DEPS}
