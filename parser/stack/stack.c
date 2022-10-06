/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:36:57 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/06 16:44:32 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

//basic  선입 선출 ..list..void pointer로 받게 .. pop .. push..new

t_node	*new_node(t_node_type type, void *data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(new, 0, sizeof(t_node));
	new->node_type = type;
	if (new->node_type == TOKEN)
		new->token = (t_token *)data;
	else if (new->node_type == STATE)
		new->state = *((int *)data);
	else
		new->p_rule = *((t_product *)data);
	return (new);
}

void	stack_push(t_stack *stack, t_node *new)
{
	new->bottom = stack->top;
	stack->top = new;
}

t_node	*stack_pop(t_stack *stack)
{
	t_node	*node;

	if (stack->top == NULL)
		return (NULL);
	node = stack->top;
	stack->top = stack->top->bottom;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;
	t_state	s0;

	s0 = P_S0;
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(stack, 0, sizeof(stack));
	stack_push(stack, new_node(STATE, &s0));
	return (stack);
}
