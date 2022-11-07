/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_expand3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:26:37 by daegulee          #+#    #+#             */
/*   Updated: 2022/11/07 14:51:50 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	get_expd_str_help(char *str, t_expand_info *expand_info, \
char *value, int *i)
{
	expand_info->start = ft_strlen(str);
	expand_info->size = ft_strlen(value);
	ft_strlcat (str + ft_strlen(str), value, ft_strlen(str) + \
		ft_strlen(value) + 1);
	(*i) += ft_strlen(value);
}

t_ast_node	*get_command_node(t_ast_node *head)
{
	while (head && head->node_type != NODE_COMMAND)
		head = head->left;
	if (!head)
		return (NULL);
	return (head);
}

char	**get_argv_data(t_ast_node *head)
{
	t_ast_node	*command_node;
	char		**argv;

	command_node = get_command_node(head);
	if (!command_node)
		return (0);
	argv = get_command_info(command_node);
	return (argv);
}
