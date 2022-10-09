/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:54:31 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/09 18:46:09 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../lexer/lexer.h"
# include <fcntl.h>
# include "../../gnl/get_next_line.h"
# include "../stack/stack.h"

typedef char*	t_string;

# define TABLE_HEIGHT 44

// lalr_col idx
# define ACTION_PIPE 0
# define ACTION_OR 1
# define ACTION_AND 2
# define ACTION_L_BRAKIT 3
# define ACTION_R_BRAKIT 4
# define ACTION_WORD 5
# define ACTION_LESS 6
# define ACTION_GREATE 7
# define ACTION_DGREATE 8
# define ACTION_DLESS 9
# define ACTION_BOTTOM 10
# define GOTO_DATALIST 11
# define GOTO_PIPE 12
# define GOTO_OR 13
# define GOTO_AND 14
# define GOTO_CMD 15
# define GOTO_SUBSHELL 16
# define GOTO_SIMPLE_CMD 17
# define GOTO_CMD_NAME 18
# define GOTO_CMD_SUF 19
# define GOTO_CMD_PRE 20
# define GOTO_REDIR_LIST 21
# define GOTO_IO_REDIR 22
# define GOTO_IO_FILE 23
# define GOTO_IO_HERE 24
# define GOTO_F_NAME 25
# define GOTO_END 26
// change goto idx
# define P_RULE_TO_GOTO 10

typedef struct s_grammer
{
	char *grammer;
	int	pop_nb;
	int	p_rule_idx;
}	t_grammer;

void	make_lalr_table(void);
int		get_action_idx(t_token_list *t_list);
char	*look_lalr_goto(t_stack *stack, char *str, int go_to);
char	*look_lalr_action(t_stack *stack, char *str, t_token_list *t_list);
//
void	push_down(t_stack *stack, t_token_list t_list);
void	parser(char *str);
// stack_util.c
void	stack_shift(char **str, t_stack *stack, t_token_list *t_list);
int		get_reduce_pop_nb(int reduce_idx);
void	stack_reduce(char **str, t_stack *stack, t_token_list *t_list);

#endif
