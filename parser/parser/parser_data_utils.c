/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:28:53 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/05 20:45:54 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"
#include "../../stack/stack.h"

t_stack_data	*get_stack_data(t_token *token, t_type_data type, int status, \
								int n_terminal_type)
{
	t_stack_data	*result;

	result = malloc (sizeof(t_stack_data));
	if (!result)
		ft_exit("malloc error", 0);
	result->token = token;
	result->state = status;
	result->type = type;
	result->n_terminal_type = n_terminal_type;
	return (result);
}

t_node	*get_stack_node(t_stack_data *data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		ft_exit("malloc error", 0);
	node->data = data;
	node->next = 0;
	return (node);
}

t_stack	*get_stack(void)
{
	t_stack			*result;
	t_stack_data	*data;

	result = malloc (sizeof(t_stack));
	if (!result)
		ft_exit("malloc error", 0);
	result->count = 0;
	result->head = 0;
	data = get_stack_data(0, STATUS, 0, -1);
	ft_push(result, get_stack_node(data));
	return (result);
}

t_ast	*allocate_ast(void)
{
	t_ast	*result;

	result = malloc(sizeof(t_ast));
	if (!result)
		ft_exit("malloc error", 0);
	result->head = 0;
	result->last_added = 0;
	result->subshell_head = 0;
	return (result);
}
