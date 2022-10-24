/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:04:19 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/24 20:47:26 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <fcntl.h>
# include"../lexer/lexer.h"
# include "../../stack/stack.h"
# include "../../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define TMP_FILENAME "tmp"
# define TMP_DIR "/var/folders/zz/zyxvpxvq6csfxvn_n000csj80036c_/T/"

# define IDX_PIPE 0
# define IDX_OR 1 
# define IDX_AND 2
# define IDX_LBRAC 3
# define IDX_RBRAC 4
# define IDX_WORD 5
# define IDX_LESS 6
# define IDX_GREAT 7
# define IDX_DGREAT 8
# define IDX_DLESS 9
# define IDX_LAST 10
# define IDX_DATA_LIST 11
# define IDX_N_PIPE 12
# define IDX_N_OR 13
# define IDX_N_AND 14
# define IDX_CMD 15
# define IDX_SUBSHELL 16
# define IDX_SIMPLE_COMMAND 17
# define IDX_CMD_NAME 18
# define IDX_CMD_SUFFIX 19
# define IDX_CMD_PREFIX 20
# define IDX_REDIR_LIST 21
# define IDX_IO_REDIR 22
# define IDX_IO_FILE 23
# define IDX_IO_HERE 24
# define IDX_F_NAME 25
# define IDX_END 26

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
	int				wildcard_flag;
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

typedef struct s_subshell_list
{
	t_ast_node				*subshell_ast_node;
	struct s_subshell_list	*next;
}	t_subshell_node;

typedef struct s_ast
{
	t_ast_node		*head;
	t_ast_node		*last_added;
	t_subshell_node	*subshell_head;
	t_ast_node		*command_node;
	int				subshell_flag;
	int				subshell_idx;
	int				subshell_cnt;
}	t_ast;

void			start_parse(t_token	*tokens);
t_stack_data	*get_stack_data(t_token *token, t_type_data type, int status, \
								int n_terminal_type);
t_stack			*get_stack(void);
t_ast			*allocate_ast(void);
t_node			*get_stack_node(t_stack_data *data);;
int				do_reduce(t_stack *stack, int cnt, int reduce_grammer);
int				get_reduce_num(int reduce_num);
int				get_reduce_grammer(int reduce_tg);
int				get_y_idx(t_token *tokens);
void			make_ast(t_token *token, t_ast *ast);
void			do_shift(t_stack *stack, t_token *tokens, \
						int status, t_ast *ast);
t_ast			*pushdown_automata(t_stack *stack, t_token *tokens, \
						int state, int y);
void			add_head_redir(t_token *token, t_ast *ast);
void			add_head_subshell(t_ast *ast);
void			add_head_command(t_token *token, t_ast *ast);
void			add_redir_token(t_token *token, t_ast *ast);
void			add_command_node_right(t_token *token, t_ast *ast);
void			add_subshell_command(t_token *token, t_ast *ast);
void			add_command_node(t_token *token, t_ast *ast);
void			add_suffix_node(t_token *token, t_ast *ast);
void			and_or_handler(t_token *token, t_ast *ast);
void			redir_handler(t_token *token, t_ast *ast);
void			subshell_handler(t_token *token, t_ast *ast);
int				is_node_pipe_and_or(t_ast_node	*node);
void			print_ast(t_ast_node *ast);
void			print_ast_status(t_ast *ast);
void			add_and_or_node_in_subshell(t_ast *ast, t_ast_node *new_node);
void			add_last_subshell_node(t_ast *ast, t_ast_node *new_node);
void			reset_sub_idx(t_ast *ast);
void			release_all_ast(t_ast *ast);
void			read_heredoc(t_ast_node *ast, int write_flag);
void			release_all_subshell_node(t_subshell_node *sub_node);
void			pipe_handler(t_token *token, t_ast *ast);
t_expand_info	*dup_expand_info(t_expand_info *old);
void			add_command_node_left(t_token *token, t_ast *ast);
void			pipe_handler(t_token *token, t_ast *ast);
t_ast_node		*get_pipe_or_and_ast_token(t_token *token);
#endif