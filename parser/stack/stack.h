/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:37:42 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/10 17:16:27 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "../lexer/lexer.h"

typedef enum e_production{
	PROGRAM = 0,
	DATA_lIST = 11,
	PIPE,
	OR,
	AND,
	CMD,
	SUBSHELL,
	SIMPLE_CMD,
	CMD_NAME,
	CMD_SUFFIX,
	CMD_PREFIX,
	REDIR_LIST,
	IO_REDIR,
	IO_FILE,
	IO_HERE,
	F_NAME,
	END
}	t_product;

typedef enum e_type{
	TOKEN = 0,
	STATE,
	PRODUCTION
}	t_node_type;

typedef struct s_snode
{
	struct s_snode	*bottom;
	t_token			*token;
	t_node_type		node_type;
	t_product		p_rule;
	int				state;
}	t_snode;

typedef struct s_stack
{
	t_snode	*top;
}	t_stack;

t_stack		*init_stack(void);
t_snode		*stack_pop(t_stack *stack);
void		stack_push(t_stack *stack, t_snode *new);
t_snode		*new_snode(t_node_type type, void *data);

#endif
