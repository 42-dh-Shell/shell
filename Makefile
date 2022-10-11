# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:07:35 by hyunkyle          #+#    #+#              #
#    Updated: 2022/10/11 10:38:44 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS				= main.c \
					./signal/signal.c \
					./parser/lexer/lexer_list_utils.c \
					./parser/lexer/lexer_list_utils1.c \
					./parser/lexer/lexer_token_utils.c \
					./parser/lexer/lexer_token_utils1.c \
					./parser/lexer/lexer_utils.c \
					./parser/lexer/lexer_while_utils.c \
					./parser/lexer/lexer.c \
					./stack/stack.c \
					./parser/parser/parser.c \
					./parser/parser/lalr_table.c \
					./parser/parser/automata.c \
					./parser/parser/automata1.c \
					./parser/parser/parser_data_utils.c \
					./parser/parser/ast.c \
					./parser/parser/ast_utils.c \
					./parser/parser/ast_utils1.c \
					./parser/parser/ast_utils2.c \
					./parser/parser/ast_utils3.c \
					./hash/hash.c \
					./hash/hash_utils.c \
					./hash/ft_find_next_prime.c \
					./hash/hash_data_utils.c

					  
OBJS = $(SRCS:.c=.o)
DEPS = ${OBJS:.o=.d}

FLAGS = -lncurses 
CFLAGS = -Wall -Wextra -Werror -g
LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
COMFILE_FLAGS = -Wall -Wextra -Werror -g -I${HOME}/.brew/opt/readline/include -MD
CC = cc

NAME = mini

$(NAME)	: $(OBJS)
	make -C ./libft
	make -C ./get_next_line
	$(CC) $(LINKING_FLAGS) $(FLAGS) -o $(NAME) $(OBJS) ./libft/libft.a ./get_next_line/libgnl.a

.c.o :
	$(CC) -c $< -o $@ $(COMFILE_FLAGS)

all	: $(NAME)

clean	:
		make -C ./libft clean
		make -C ./get_next_line clean
		rm -f $(OBJS)
		rm -f ${DEPS}

fclean	:	clean
		make -C ./libft fclean
		make -C ./get_next_line fclean
		rm -f $(NAME)

re	:
	make -C ./get_next_line re
	make -C ./libft re
	make fclean
	make all

.PHONY	:	all clean fclean re

-include ${DEPS}
