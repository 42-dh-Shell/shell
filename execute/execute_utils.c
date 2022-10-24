/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:12:35 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/24 14:43:53 by hyunkyle         ###   ########.fr       */
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

int	is_valid_redir_filename(t_expand_info *expand_info)
{
	char	*key;
	char	*value;

	if (expand_info == 0)
		return (1);
	while (expand_info)
	{
		if (expand_info->split_arg == 1)
		{
			key = ft_substr(expand_info->str, expand_info->start + 1, \
				expand_info->size);
			value = get_hash(g_shell->h_table, key);
			if (value != NULL && get_argv_size(ft_split(value, ' ')) > 1)
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(key, 2);
				ft_putstr_fd(": ambiguous redirect\n", 2);
				free(key);
				return (0);
			}
			free(key);
		}
		expand_info = expand_info->next;
	}
	return (1);
}

void	add_last_pid(pid_t pid)
{
	t_pid_list	*pid_node;
	t_pid_list	*lst;

	pid_node = ft_calloc(sizeof(t_pid_list), 1);
	if (!pid_node)
		ft_exit("malloc error\n", 1);
	pid_node->pid = pid;
	if (g_shell->pids == 0)
	{
		g_shell->pids = pid_node;
		return ;
	}
	lst = g_shell->pids;
	while (lst->next)
		lst = lst->next;
	lst->next = pid_node;
}
