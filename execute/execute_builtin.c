/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:37:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/08 14:40:49 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute_dup(enum e_ast_types type, int fd)
{
	int	status;

	if (type == NODE_DGREAT || type == NODE_GREAT)
	{
		if (g_shell->sh_lv == 0 && g_shell->io_filename[1] == NULL)
			store_stdout();
		status = dup2(fd, STDOUT_FILENO);
	}
	else
	{
		if (g_shell->sh_lv == 0 && g_shell->io_filename[0] == NULL)
			store_stdin();
		status = dup2(fd, STDIN_FILENO);
	}
	if (status < 0)
		ft_exit("dup2 error\n", 1);
}

int	dup_builtin_fd(char *filename, enum	e_ast_types type)
{
	int	fd;

	if (type == NODE_DGREAT)
		fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else if (type == NODE_GREAT)
		fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else
		fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error_printf("minishell : %s: %s\n", strerror(errno), filename);
		g_shell->exit_status = 1;
		return (0);
	}
	execute_dup(type, fd);
	return (1);
}

int	execute_buitin_redir(t_ast_node *head)
{
	char	**argv;
	int		result;

	if (!is_valid_redir_filename(head->redir_token->expand_info))
		return (0);
	argv = expand_str(head->redir_token->str, \
		head->redir_token->expand_info);
	result = dup_builtin_fd(argv[0], head->node_type);
	release_argv(argv);
	return (result);
}

void	execute_builtin(t_ast_node *head, char **argv)
{
	int		result;

	while (g_shell->redir_list)
	{
		result = execute_buitin_redir(g_shell->redir_list);
		if (!result)
			return ;
		g_shell->redir_list = g_shell->redir_list->left;
	}
	g_shell->redir_list = NULL;
	if (head->node_type == NODE_DGREAT || head->node_type == NODE_LESS \
	|| head->node_type == NODE_DLESS || head->node_type == NODE_GREAT)
	{
		result = execute_buitin_redir(head);
		if (!result)
			return ;
		if (head->left != NULL)
			execute_builtin(head->left, argv);
	}
	else
			g_shell->exit_status = do_builtin(argv);
}
