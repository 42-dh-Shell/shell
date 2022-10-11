/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_r11,10,9,7,6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:24:04 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/11 10:48:29 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

void	act_r11(t_support *sup)
{
	sup->wait->subshell = sup->subshell;
}

void	act_r10(t_support *sup)
{
	sup->wait->subshell->sub_rd_lst = sup->wait->rd_lst;
	sup->wait->rd_lst = NULL;
	sup->subshell = sup->subshell->parent_sub;
	if (sup->subshell != NULL)
		sup->cur = (t_ast *)sup->subshell->subtree;
	else
		sup->cur = sup->ast;
}

void	act_r9(t_support *sup)
{
	sup->subshell = sup->subshell->parent_sub;
	if (sup->subshell != NULL)
		sup->cur = (t_ast *)sup->subshell->subtree;
	else
		sup->cur = sup->ast;
}

void	act_r7(t_support *sup)
{
	t_ast_node	*c_op;
	t_ast_node	*new;

	c_op = init_ast_node(N_CONTROL_OP);
	c_op->control = CONTROL_AND;
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

void	act_r6(t_support *sup)
{
	t_ast_node	*c_op;
	t_ast_node	*new;

	c_op = init_ast_node(N_CONTROL_OP);
	c_op->control = CONTROL_OR;
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
