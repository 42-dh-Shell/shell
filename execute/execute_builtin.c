/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:37:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/07 14:59:45 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*get_io_filename(int in_out_flag)
{
	char		*file_name;
	char		*tmp_dir;
	char		*result;

	if (g_shell->tmp != NULL)
		tmp_dir = g_shell->tmp;
	else
		tmp_dir = TMP_DIR;
	if (in_out_flag)
		file_name = ft_strdup("tmp_out");
	else
		file_name = ft_strdup("tmp_in");
	result = ft_calloc(sizeof(char), ft_strlen(tmp_dir) + \
		ft_strlen(file_name) + 1);
	ft_strlcat(result, tmp_dir, ft_strlen(tmp_dir) + 1);
	ft_strlcat(result, file_name, ft_strlen(tmp_dir) + \
		ft_strlen(file_name) + 1);
	free(file_name);
	return (result);
}

void	execute_dup(enum e_ast_types type, int fd)
{
	int	status;
	int	status2;

	if (type == NODE_DGREAT || type == NODE_GREAT)
	{
		g_shell->io_filename[1] = get_io_filename(1);
		g_shell->std_io[1] = open(g_shell->io_filename[1], O_CREAT, 0644);
		if (g_shell->std_io[1] < 0)
			ft_exit("open error\n", 1);
		status2 = dup2(STDOUT_FILENO, g_shell->std_io[1]);
		status = dup2(fd, STDOUT_FILENO);
	}
	else
	{
		g_shell->io_filename[0] = get_io_filename(0);
		g_shell->std_io[0] = open(g_shell->io_filename[0], O_CREAT, 0644);
		if (g_shell->std_io[0] < 0)
			ft_exit("open error\n", 1);
		status2 = dup2(STDIN_FILENO, g_shell->std_io[0]);
		status = dup2(fd, STDIN_FILENO);
	}
	if (status < 0 || status2 < 0)
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
		error_printf("minishell : %s\n", strerror(errno));
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
	expand_exit_status(argv);
	result = dup_builtin_fd(argv[0], head->node_type);
	release_argv(argv);
	return (result);
}

void	execute_builtin(t_ast_node *head, char **argv)
{
	int		result;

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
