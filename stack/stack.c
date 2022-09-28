/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:36:57 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/29 00:08:50 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

//basic  선입 선출 ..list..void pointer로 받게 .. pop .. push..new

t_node	*new_node(t_token *token)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(new, 0, sizeof(t_node));
	new->token = token;
	return (new);
}

void	stack_push(t_stack **stack, t_node *new)
{
	if ((*stack) == NULL)
	{
		*stack = malloc(sizeof(t_stack));
		if ((*stack) == NULL)
			ft_exit("malloc error.\n", 1);
		(*stack)->top = new;
		return ;
	}
	new->bottom = (*stack)->top;
	(*stack)->top = new;
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
