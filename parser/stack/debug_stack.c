/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:03:13 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 05:58:43 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static const char	*g_type_table[18] = {
	"init", "Word", "Double", "Single", "Expansion", \
	">", ">>", "<", "<<", ")", "(", \
	"&", "&&", "ERROR", "|", "||", "is_space", "FINISH"
};

void	print_stack(t_stack *stack)
{
	t_node	*cur;

	if (stack->top == NULL)
	{
		printf("No Node in stack.\n");
		return ;
	}
	cur = stack->top;
	while (cur)
	{
		printf("Token Type = %s\n", g_type_table[cur->token->token_type]);
		printf("TOken data = %s\n", cur->token->token_data);
		printf("##########################\n");
		cur = cur->bottom;
	}
}
