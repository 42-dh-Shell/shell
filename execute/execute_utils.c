/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:12:35 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/17 10:53:54 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	has_event(t_ast_node *head)
{
	while (head)
	{
		if (head->node_type == NODE_SUBSHELL || head->node_type == NODE_AND \
			|| head->node_type == NODE_OR || head->node_type == NODE_PIPE)
			return (1);
		head = head->left;
	}
	return (0);
}
