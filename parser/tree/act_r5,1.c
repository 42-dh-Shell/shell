/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_r5,1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:50:18 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/11 19:02:46 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

void	act_r5(t_support *sup)
{
	t_ast_node	*c_op;
	t_ast_node	*new;

	c_op = init_ast_node(N_CONTROL_OP);
	c_op->control = CONTROL_PIPE;
	if (sup->wait->subshell)
	{
		new = init_ast_node(N_SUBSHELL);
		new->subshell = sup->wait->subshell;
		sup->wait->subshell = NULL;
	}
	else
	{
		new = init_ast_node(N_CMD);
		new->cmd = sup->wait->cmd;
		sup->wait->cmd = NULL;
	}
	sup->cur->root->parent = c_op;
	c_op->l_child = sup->cur->root;
	c_op->r_child = new;
	new->parent = c_op;
	sup->cur->root = c_op;
}

void	act_r1(t_support *sup)
{
	t_ast_node	*new;

	if (sup->wait->subshell)
	{
		new = init_ast_node(N_SUBSHELL);
		new->subshell = sup->wait->subshell;
		sup->wait->subshell = NULL;
	}
	else
	{
		new = init_ast_node(N_CMD);
		new->cmd = sup->wait->cmd;
		sup->wait->cmd = NULL;
	}
	sup->cur->root = new;
}
