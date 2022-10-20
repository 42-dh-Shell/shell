/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:03:13 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/20 23:06:16 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_snode(t_snode *snode)
{
	if (snode->token)
	{
		free(snode->token->token_data);
		free(snode->token);
	}
	free(snode);
}

void	free_stack(t_stack *stack)
{
	t_snode	*tmp;

	if (stack->top == NULL)
	{
		free(stack);
		return ;
	}
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->bottom;
		free(tmp);
	}
	free(stack);
}