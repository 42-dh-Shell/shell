/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:43:55 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/19 18:44:06 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute_and_or_handler(t_ast_node *head)
{
	execute_command(head->left, 0, C_NORMAL);
	//if (head->node_type == NODE_AND)
		// if exit_status == 0
			//execute_command(head->right);
	//else
		// if exit_status != 0
			//execute_command(head->right);
}
