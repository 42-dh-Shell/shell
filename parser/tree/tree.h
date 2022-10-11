/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:42:38 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/11 13:00:17 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

//CMD
typedef enum e_redir_type
{
	LESS = 0,
	DLESS,
	GREATE,
	DGREATE,
}	t_redir_t;

typedef struct s_redir
{
	t_redir_t		rd_t;
	t_token			*f_name;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd_prefix
{
	t_redir	*head;
}	t_cmd_pre;

typedef struct s_cmd_name
{
	t_token	*c_name;
}	t_cmd_name;

typedef struct s_redir_lst
{
	t_redir	*head;
}	t_redir_lst;

typedef struct s_cmd_suffix
{
	t_token_list	*para_lst;
	t_redir_lst		*pre_rd_lst;
}	t_cmd_suf;

typedef struct s_cmd
{
	t_cmd_pre	*cmd_prefix;
	t_cmd_name	*cmd_name;
	t_cmd_suf	*cmd_suffix;
}	t_cmd;

//Control
typedef enum e_control
{
	NOT = 0,
	CONTROL_PIPE = 1,
	CONTROL_OR,
	CONTROL_AND
}	t_control;

//subshell
typedef struct s_subshell	t_subshell;
struct s_subshell
{
	void			*subtree;
	t_redir_lst		*sub_rd_lst;
	t_subshell		*parent_sub;
};

//AST

typedef enum e_ast_node_t
{
	N_NON = 0,
	N_CMD = 1,
	N_CONTROL_OP,
	N_SUBSHELL
}	t_ast_node_t;

typedef struct s_ast_node
{
	t_ast_node_t		ast_n_type;
	struct s_ast_node	*parent;
	struct s_ast_node	*l_child;
	struct s_ast_node	*r_child;
	t_cmd				*cmd;
	t_control			control;
	t_subshell			*subshell;
}	t_ast_node;

////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//Wait
typedef struct s_wait
{
	t_cmd_name	*cmd_name;
	t_cmd_pre	*cmd_pref;
	t_cmd_suf	*cmd_suf;
	t_cmd		*cmd;
	t_redir_lst	*rd_lst;
	t_redir		*io_redir;
	t_token		*f_name;
	t_token		*end;
	t_subshell	*subshell;
}	t_wait;

typedef struct s_ast
{
	t_ast_node	*root;
	t_ast_node	*last_in;
}	t_ast;
//////////////////////////////////////////////

typedef struct s_support
{
	t_stack			*stack;
	t_token_list	*t_list;
	t_ast			*ast;
	t_wait			*wait;
	t_ast			*cur;
	t_subshell		*subshell;
}	t_support;
////// sup
void		act_r1(t_support *sup);
void		act_r5(t_support *sup);
void		act_r6(t_support *sup);
void		act_r7(t_support *sup);
void		act_r9(t_support *sup);
void		act_r10(t_support *sup);
void		act_r11(t_support *sup);
void		act_r12(t_support *sup);
void		act_r13(t_support *sup);
void		act_r14(t_support *sup);
void		act_r15(t_support *sup);
void		act_r16(t_support *sup);
void		act_r17(t_support *sup);
void		act_r18(t_support *sup);
void		act_r19(t_support *sup);
void		act_r20(t_support *sup);
void		act_r21(t_support *sup);
void		act_r22(t_support *sup);
void		act_r23(t_support *sup);
void		act_r24(t_support *sup);
void		act_r25(t_support *sup);
void		act_r28(t_support *sup);
void		act_r29(t_support *sup);
void		act_r30(t_support *sup);
void		act_r31(t_support *sup);
void		act_r32(t_support *sup);
void		act_r33(t_support *sup);

void		init_ast(t_ast **ast);
void		build_subshell(t_support *sup);
void		finish_subshell(t_ast *ast);
t_ast_node	*init_ast_node(t_ast_node_t node_type);

void		do_print(t_ast_node *cur);
void		print_tree(t_ast *ast);

#endif