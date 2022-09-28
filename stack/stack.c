/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:32:58 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/09/28 16:39:54 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_push(t_stack *st, t_node *target)
{
	t_node	*head;

	if (st->count == 0)
	{
		st->head = target;
		st->count += 1;
		return ;
	}
	head = st->head;
	st->head = target;
	st->head->next = head;
	st->count += 1;
}

t_node	*ft_pop(t_stack *st)
{
	t_node	*result;

	if (st->count == 0)
		return (0);
	if (st-> count == 1)
	{
		st->count = 0;
		result = st->head;
		st->head = 0;
		return (result);
	}
	result = st->head;
	st->head = st->head->next;
	st->count -= 1;
	result->next = 0;
	return (result);
}
