/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:37:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/21 17:30:21 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	dup_builtin_fd(char *filename, enum	e_ast_types type)
{
	int	fd;
	int	status;

	if (type == NODE_DGREAT)
		fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else if (type == NODE_GREAT)
		fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else
		fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		if (errno == 2)
			print_no_file_error(filename);
		g_shell->exit_status = 1;
		return (0);
	}
	if (type == NODE_DGREAT || type == NODE_GREAT)
		status = dup2(fd, STDOUT_FILENO);
	else
		status = dup2(fd, STDIN_FILENO);
	if (status < 0)
		ft_exit("dup2 error\n", 1);
	close(fd);
	return (1);
}

int	execute_buitin_redir(t_ast_node *head)
{
	char	**argv;

	if (!is_valid_redir_filename(head->redir_token->expand_info))
		return (0);
	system("leaks mini");
	argv = expand_str(head->redir_token->str, \
		head->redir_token->expand_info);
	return (dup_builtin_fd(argv[0], head->node_type));
}

void	execute_builtin(t_ast_node *head, char **argv, t_command_io io)
{
	int		result;

	if (head->node_type == NODE_DGREAT || head->node_type == NODE_LESS \
	|| head->node_type == NODE_DLESS || head->node_type == NODE_GREAT)
	{
		result = execute_buitin_redir(head);
		if (!result)
			return ;
		if (head->left != NULL)
			execute_builtin(head->left, argv, io);
	}
	else
	{
		if (io == C_NORMAL)
			g_shell->exit_status = do_builtin(argv);
	}
}
