/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:30:22 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/09 19:29:19 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

static const int	g_reduce_nb[34] = {
	1,
	1,
	2,
	2,
	2,
	2,
	2,
	2,
	1,
	1,
	2,
	3,
	3,
	2,
	1,
	1,
	2,
	1,
	1,
	2,
	1,
	2,
	1,
	2,
	1,
	2,
	1,
	1,
	2,
	2,
	2,
	2,
	1,
	1,
};

static const int	g_reduce_to_goto[34] = {
	0,
	GOTO_DATALIST,
	GOTO_DATALIST,
	GOTO_DATALIST,
	GOTO_DATALIST,
	GOTO_PIPE,
	GOTO_OR,
	GOTO_AND,
	GOTO_CMD,
	GOTO_CMD,
	GOTO_CMD,
	GOTO_SUBSHELL,
	GOTO_SIMPLE_CMD,
	GOTO_SIMPLE_CMD,
	GOTO_SIMPLE_CMD,
	GOTO_SIMPLE_CMD,
	GOTO_SIMPLE_CMD,
	GOTO_CMD_NAME,
	GOTO_CMD_SUF,
	GOTO_CMD_SUF,
	GOTO_CMD_SUF,
	GOTO_CMD_SUF,
	GOTO_CMD_PRE,
	GOTO_CMD_PRE,
	GOTO_REDIR_LIST,
	GOTO_REDIR_LIST,
	GOTO_IO_REDIR,
	GOTO_IO_REDIR,
	GOTO_IO_FILE,
	GOTO_IO_FILE,
	GOTO_IO_FILE,
	GOTO_IO_HERE,
	GOTO_F_NAME,
	GOTO_END
};

void	stack_shift(char **str, t_stack *stack, t_token_list *t_list)
{
	t_snode	*new;
	int		state;

	new = new_snode(TOKEN, t_list->head);
	stack_push(stack, new);
	t_list->head = t_list->head->next;
	state = ft_atoi(*str + 1);
	new = new_snode(STATE, &state);
	stack_push(stack, new);
	*str = look_lalr_action(stack, *str, t_list);
}

int	get_reduce_pop_nb(int reduce_idx)
{
	return (g_reduce_nb[reduce_idx]);
}

void	stack_reduce(char **str, t_stack *stack, t_token_list *t_list)
{
	int			pop_nb;
	int			reduce_idx;
	t_snode		*new;
	int			state;
	t_product	p_rule;

	reduce_idx = ft_atoi(*str + 1);
	pop_nb = 2 * get_reduce_pop_nb(reduce_idx);
	printf("pop_nb %d\n", pop_nb);
	while (pop_nb)
	{
		stack_pop(stack);
		pop_nb--;
	}
	p_rule = g_reduce_to_goto[reduce_idx];
	*str = look_lalr_goto(stack, *str, p_rule);
	new = new_snode(PRODUCTION, &p_rule);
	printf("p_rule %d\n", p_rule);
	stack_push(stack, new);
	state = ft_atoi(*str);
	printf("state = %d\n", state);
	new = new_snode(STATE, &state);
	stack_push(stack, new);
	*str = look_lalr_action(stack, *str, t_list);
	printf("next action table %s\n", *str);
}
