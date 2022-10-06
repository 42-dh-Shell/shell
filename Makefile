# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:07:35 by hyunkyle          #+#    #+#              #
#    Updated: 2022/10/06 13:16:57 by hyunkyle         ###   ########.fr        #
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

					  
OBJS = $(SRCS:.c=.o)

FLAGS = -lncurses 
CFLAGS = -Wall -Wextra -Werror -g
LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
COMFILE_FLAGS = -I${HOME}/.brew/opt/readline/include

CC = cc

NAME = mini

$(NAME)	: $(OBJS)
	make -C ./libft
	make -C ./get_next_line
	$(CC) $(LINKING_FLAGS) $(FLAGS) -o $(NAME) $(OBJS) ./libft/libft.a ./get_next_line/libgnl.a

.c.o :
	$(CC)  $(COMFILE_FLAGS) -c $< -o $@

all	: $(NAME)

clean	:
		make -C ./libft clean
		make -C ./get_next_line clean
		rm -f $(OBJS)

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
