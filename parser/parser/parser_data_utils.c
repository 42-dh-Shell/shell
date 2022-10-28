/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:28:53 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/24 21:20:43 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"
#include "../../stack/stack.h"

t_stack_data	*get_stack_data(t_token *token, t_type_data type, int status, \
								int n_terminal_type)
{
	t_stack_data	*result;

	result = ft_calloc (sizeof(t_stack_data), 1);
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

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		ft_exit("malloc error", 0);
	node->data = data;
	return (node);
}

t_stack	*get_stack(void)
{
	t_stack			*result;
	t_stack_data	*data;

	result = ft_calloc (sizeof(t_stack), 1);
	if (!result)
		ft_exit("malloc error", 0);
	data = get_stack_data(0, STATUS, 0, -1);
	ft_push(result, get_stack_node(data));
	return (result);
}

t_ast	*allocate_ast(void)
{
	t_ast	*result;

	result = ft_calloc(sizeof(t_ast), 1);
	if (!result)
		ft_exit("malloc error", 0);
	result->subshell_idx = -1;
	return (result);
}
