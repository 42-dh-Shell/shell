/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:38:41 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/20 16:20:33 by daegulee         ###   ########.fr       */
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
