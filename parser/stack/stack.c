/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:36:57 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/20 23:48:20 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_snode	*new_snode(t_node_type type, void *data)
{
	t_snode	*new;

	new = malloc(sizeof(t_snode));
	if (new == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(new, 0, sizeof(t_snode));
	new->node_type = type;
	if (new->node_type == TOKEN)
		new->token = token_dup((t_token *)data);
	else if (new->node_type == STATE)
		new->state = *((int *)data);
	else
		new->p_rule = *((t_product *)data);
	return (new);
}

void	stack_push(t_stack *stack, t_snode *new)
{
	new->bottom = stack->top;
	stack->top = new;
}

t_snode	*stack_pop(t_stack *stack)
{
	t_snode	*node;

	if (stack->top == NULL)
		return (NULL);
	node = stack->top;
	stack->top = stack->top->bottom;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;
	int		state;

	state = 0;
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(stack, 0, sizeof(stack));
	stack_push(stack, new_snode(STATE, &state));
	return (stack);
}
