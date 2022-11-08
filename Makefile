# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:07:35 by hyunkyle          #+#    #+#              #
#    Updated: 2022/11/07 21:02:07 by daegulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS				= main.c \
					./lalr_table.c \
					./signal/signal.c \
					./signal/signal1.c \
					./parser/lexer/lexer_list_utils.c \
					./parser/lexer/lexer_list_utils1.c \
					./parser/lexer/lexer_token_utils.c \
					./parser/lexer/lexer_token_utils1.c \
					./parser/lexer/lexer_token_utils2.c \
					./parser/lexer/lexer_utils.c \
					./parser/lexer/lexer_while_utils.c \
					./parser/lexer/lexer.c \
					./stack/stack.c \
					./parser/parser/parser.c \
					./parser/parser/parser1.c \
					./parser/parser/automata.c \
					./parser/parser/automata1.c \
					./parser/parser/parser_data_utils.c \
					./parser/parser/parser_data_utils1.c \
					./parser/parser/ast.c \
					./parser/parser/ast_data_utils.c \
					./parser/parser/ast_utils.c \
					./parser/parser/ast_utils1.c \
					./parser/parser/ast_utils2.c \
					./parser/parser/ast_utils3.c \
					./parser/parser/ast_utils4.c \
					./hash/hash.c \
					./hash/hash_utils.c \
					./hash/hash_utils1.c \
					./hash/ft_find_next_prime.c \
					./execute/execute.c \
					./execute/execute1.c \
					./execute/execute2.c \
					./execute/execute_expand1.c \
					./execute/execute_expand2.c \
					./execute/execute_expand3.c \
					./execute/execute_utils.c \
					./execute/execute_utils1.c \
					./execute/execute_utils2.c \
					./execute/execute_utils3.c \
					./execute/execute_builtin.c \
					./execute/pipe_list.c \
					./execute/free_queue.c \
					./execute/queue_util.c \
					./execute/wild_expand.c \
					./execute/wild_expand2.c \
					./builtin/argv_sort.c \
					./builtin/cd.c \
					./builtin/echo.c \
					./builtin/env.c \
					./builtin/exit.c \
					./builtin/export.c \
					./builtin/is_builtin.c \
					./builtin/pwd.c \
					./builtin/unset.c \
					  
OBJS = $(SRCS:.c=.o)
DEPS = ${OBJS:.o=.d}

FLAGS = -lncurses
LINKING_FLAGS = -lreadline $(LD_CLUS) -fsanitize=address
COMFILE_FLAGS = -Wall -Wextra -Werror -g $(CPP_CLUS) -MD -fsanitize=address
CC = cc
LD_CLUS=-L${HOME}/.brew/opt/readline/lib 
CPP_CLUS=-I${HOME}/.brew/opt/readline/include
LD_HOME="-L/opt/homebrew/opt/readline/lib"
CPP_HOME="-I/opt/homebrew/opt/readline/include"
NAME = mini

$(NAME)	: $(OBJS)
	make -C ./libft
	make -C ./error_printf
	make -C ./get_next_line
	$(CC) $(LINKING_FLAGS)  $(FLAGS) -o $(NAME) $(OBJS) ./libft/libft.a ./get_next_line/libgnl.a ./error_printf/errorprintf.a 

.c.o :
	$(CC) -c $< -o $@ $(COMFILE_FLAGS)

all	: $(NAME)

clean	:
		make -C ./libft clean
		make -C ./get_next_line clean
		make -C ./error_printf clean
		rm -f $(OBJS)
		rm -f ${DEPS}

fclean	:	clean
		make -C ./libft fclean
		make -C ./get_next_line fclean
		make -C ./error_printf fclean
		rm -f $(NAME)

re	:
	make -C ./get_next_line re
	make -C ./libft re
	make -C ./error_printf re
	make fclean
	make all

.PHONY	:	all clean fclean re

-include ${DEPS}
