/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:00:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/24 11:29:32 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	print_no_file_error(char *filename)
{
	ft_putstr_fd("minishell: no such file or directory: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd("\n", 2);
}

char	*get_envp_path(void)
{
	char	*envp;
	char	*key;

	key = ft_strdup("PATH");
	envp = get_hash(g_shell->h_table, key);
	free(key);
	return (envp);
}

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

void	wait_all_pids(void)
{
	t_pid_list	*lst;
	int			status;

	lst = g_shell->pids;
	while (lst)
	{
		waitpid(lst->pid, &status, 0);
		g_shell->exit_status = WEXITSTATUS(status);
		lst = lst->next;
	}
	release_pid_list(g_shell->pids);
	g_shell->pids = NULL;
}

void	release_pid_list(t_pid_list	*pids)
{
	t_pid_list	*tar;

	while (pids)
	{
		tar = pids;
		pids = pids->next;
		free(tar);
	}
}
