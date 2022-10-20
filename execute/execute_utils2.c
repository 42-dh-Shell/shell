/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:00:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/20 16:49:56 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	is_last_pipe(t_ast_node *head)
{
	t_ast_node	*lst;

	lst = head->parent;
	while (lst)
	{
		if (lst->node_type == NODE_SUBSHELL)
			return (1);
		if (lst->node_type == NODE_PIPE)
			return (0);
		lst = lst->parent;
	}
	return (1);
}

void	wait_all_pids(t_pid_list **pids)
{
	t_pid_list	*lst;
	int			status;

	lst = *pids;
	while (lst)
	{
		waitpid(lst->pid, &status, 0);
		g_shell->exit_status = WEXITSTATUS(status);
		lst = lst->next;
	}
	*pids = NULL;
}
