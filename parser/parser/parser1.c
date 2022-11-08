/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:04:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/08 17:23:04 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../execute/execute.h"
#include "../../signal/signal.h"

int	is_valid_filenum(int file_num)
{
	char		*file_name;
	struct stat	file_info;
	int			result;

	file_name = get_full_filename(file_num);
	result = stat(file_name, &file_info);
	free(file_name);
	if (result == -1)
		return (1);
	return (0);
}

int	get_file_num(void)
{
	int	file_num;

	file_num = 0;
	while (!is_valid_filenum(file_num))
		file_num++;
	return (file_num);
}

int	add_filename_open(t_ast_node *ast)
{
	char	*file_name;
	int		file_num;
	int		fd;

	file_num = get_file_num();
	file_name = get_full_filename(file_num);
	ast->redir_token->str = file_name;
	fd = open(file_name, O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		ft_exit("file open failed\n", 1);
	return (fd);
}

int	read_heardoc(pid_t	pid, char *end_flag, int fd, int write_flag)
{
	int	status;

	if (pid < 0)
		ft_exit("fork error\n", 1);
	if (pid == 0)
	{
		signal(SIGINT, signal_here_doc);
		read_start(end_flag, write_flag, fd);
		exit(0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &status, 0);
		g_shell->exit_status = WEXITSTATUS(status);
		if (g_shell->exit_status == 130)
		{
			g_shell->signal_status = 130;
			return (0);
		}
		return (1);
	}
}

void	start_read_heardoc(t_ast_node *ast, int write_flag)
{
	pid_t	pid;
	int		fd;
	char	*end_flag;

	if (!ast)
		return ;
	if (ast->node_type == NODE_DLESS)
	{
		end_flag = ast->redir_token->str;
		fd = add_filename_open(ast);
		pid = fork();
		if (!read_heardoc(pid, end_flag, fd, write_flag))
		{
			free(end_flag);
			return ;
		}
		free(end_flag);
	}
	if (ast->left != 0)
		start_read_heardoc(ast->left, write_flag);
	if (ast->right != 0 && g_shell->signal_status != 130)
		start_read_heardoc(ast->right, write_flag);
}
