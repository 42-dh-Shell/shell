/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:38:41 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/20 22:52:46 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

void	init_ast(t_ast **ast)
{
	*ast = malloc(sizeof(t_ast));
	if (*ast == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(*ast, 0, sizeof(t_ast));
}

// void	free_ast(t_ast **ast)
// {
	
// }

t_ast_node	*init_ast_node(t_ast_node_t node_type)
{
	t_ast_node	*new;

	new = malloc(sizeof(t_ast_node));
	if (new == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(new, 0, sizeof(t_ast_node));
	new->ast_n_type = node_type;
	return (new);
}

void	build_subshell(t_support *sup)
{
	t_subshell	*subshell;

	subshell = ft_malloc(sizeof(t_subshell));
	subshell->parent_sub = sup->subshell;
	subshell->subtree = ft_malloc(sizeof(t_ast));
	sup->subshell = subshell;
	sup->cur = (t_ast *)(subshell->subtree);
}
// (lldb) p ast
// (t_ast *) $2 = 0x0000000100404250
// (lldb) p ast->root
// (t_ast_node *) $3 = 0x0000000000000000
// (lldb) n
// (lldb) p sup
// (t_support *) $4 = 0x00000001003040b0
// (lldb) p sup->stack
// (t_stack *) $5 = 0x00000001004040e0
// (lldb) p sup->t_list
// (t_token_list *) $6 = 0x00007ffeefbff6c0
// (lldb) p sup->ast
// (t_ast *) $7 = 0x0000000100404250
// (lldb) p sup->wait
// (t_wait *) $8 = 0x00000001003040e0
// (lldb) p sup->cur
// (t_ast *) $9 = 0x0000000100404250
// (lldb) p sup->subshell
// (t_subshell *) $10 = 0x0000000000000000