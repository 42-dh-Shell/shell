/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:30:22 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/11 15:41:25 by daegulee         ###   ########.fr       */
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

static const t_rp	g_act_reduce[34] = {
	NULL, act_r1, NULL, NULL, NULL, act_r5, act_r6, act_r7, NULL, \
	act_r9, act_r10, act_r11, act_r12, act_r13, act_r14, act_r15, act_r16, \
	act_r17, act_r18, act_r19, act_r20, act_r21, act_r22, act_r23, act_r24, \
	act_r25, NULL, NULL, act_r28, act_r29, act_r30, act_r31, act_r32, \
	act_r33
};

void	st_shift(char **str, t_support *sup)
{
	t_snode	*new;
	int		state;

	new = new_snode(TOKEN, sup->t_list->head);
	if (new->token->token_type == T_L_BRAKIT)
		build_subshell(sup);
	stack_push(sup->stack, new);
	sup->t_list->head = sup->t_list->head->next;
	state = ft_atoi(*str + 1);
	new = new_snode(STATE, &state);
	stack_push(sup->stack, new);
	*str = look_lalr_action(sup->stack, *str, sup->t_list);
}

int	get_reduce_pop_nb(int reduce_idx)
{
	return (g_reduce_nb[reduce_idx]);
}

void	reduce_pop(t_stack *stack, int reduce_idx)
{
	int	pop_nb;

	pop_nb = 2 * get_reduce_pop_nb(reduce_idx);
	while (pop_nb)
	{
		stack_pop(stack);
		pop_nb--;
	}
}

void	st_reduce(char **str, t_support *sup)
{
	int			reduce_idx;
	t_snode		*new;
	int			state;
	t_product	p_rule;

	reduce_idx = ft_atoi(*str + 1);
	if (g_act_reduce[reduce_idx] != NULL)
		g_act_reduce[reduce_idx](sup);
	reduce_pop(sup->stack, reduce_idx);
	p_rule = g_reduce_to_goto[reduce_idx];
	*str = look_lalr_goto(sup->stack, *str, p_rule);
	new = new_snode(PRODUCTION, &p_rule);
	stack_push(sup->stack, new);
	state = ft_atoi(*str);
	new = new_snode(STATE, &state);
	stack_push(sup->stack, new);
	*str = look_lalr_action(sup->stack, *str, sup->t_list);
}
