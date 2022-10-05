/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:04:19 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/04 19:31:33 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include<fcntl.h>
# include"../lexer/lexer.h"
# include "../../stack/stack.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define IDX_LBRAC 0
# define IDX_RBRAC 1 
# define IDX_WORD 2
# define IDX_LESS 3
# define IDX_GREAT 4
# define IDX_DLESS 5
# define IDX_DGREAT 6
# define IDX_PIPE 7
# define IDX_OR 8
# define IDX_AND 9
# define IDX_LAST 10
# define IDX_DATA_LIST 11
# define IDX_SIMPLE_COMMAND 12
# define IDX_SUBSHELL 13
# define IDX_COMMAND_ELEM 14
# define IDX_REDIR 15
# define IDX_REDIR_WORD 16
# define IDX_N_PIPE 17
# define IDX_N_OR 18
# define IDX_N_AND 19

enum	e_ast_types
{
	NODE_COMMAND = 0,
	NODE_PIPE,
	NODE_SUBSHELL,
	NODE_AND,
	NODE_OR,
	NODE_LESS,
	NODE_GREAT,
	NODE_DLESS,
	NODE_DGREAT
};

typedef struct s_suffix
{
	char			*str;
	t_expand_info	*expand_info;
	struct s_suffix	*next;
}	t_suffix;

typedef struct s_redir_token
{
	char			*str;
	t_expand_info	*expand_info;
}	t_redir_token;

typedef struct s_ast_node
{
	char				*str;
	t_redir_token		*redir_token;
	t_suffix			*suffix_list;
	int					wildcard_flag;
	t_expand_info		*expand_info;
	enum e_ast_types	node_type;
	struct s_ast_node	*parent;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}	t_ast_node;

typedef struct s_ast
{
	t_ast_node	*head;
	t_ast_node	*last_added;
	t_ast_node	*subshell_head;
	t_ast_node	*command_node;
}	t_ast;

void			start_parse(t_token	*tokens);
char			***get_table(void);
t_stack_data	*get_stack_data(t_token *token, t_type_data type, int status, \
								int n_terminal_type);
t_stack			*get_stack(void);
t_ast			*allocate_ast(void);
t_node			*get_stack_node(t_stack_data *data);;
int				do_reduce(t_stack *stack, char ***lalr_table, int cnt, \
					int reduce_tg);
void			do_shift(t_stack *stack, t_token *tokens, int status);
int				get_reduce_num(int reduce_num);
int				get_reduce_grammer(int reduce_tg);
t_ast			*make_ast(t_token *token);
#endif