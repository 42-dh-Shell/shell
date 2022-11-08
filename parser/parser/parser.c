/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:04:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/08 15:45:11 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../execute/execute.h"
#include "../../signal/signal.h"

char	*get_full_filename(int file_num)
{
	char		*file_name;
	char		*tmp_dir;

	if (g_shell->tmp != NULL)
		tmp_dir = g_shell->tmp;
	else
		tmp_dir = TMP_DIR;
	file_name = ft_calloc (sizeof (char), ft_strlen(TMP_FILENAME) + \
		ft_strlen(tmp_dir) + ft_strlen(ft_itoa(file_num)) + 1);
	ft_strlcat(file_name, tmp_dir, ft_strlen(tmp_dir) + 1);
	ft_strlcat(file_name, TMP_FILENAME, ft_strlen(TMP_FILENAME) + \
			ft_strlen(tmp_dir) + 1);
	ft_strlcat(file_name, ft_itoa(file_num), ft_strlen(TMP_FILENAME) + \
		ft_strlen(tmp_dir) + ft_strlen(ft_itoa(file_num)) + 1);
	return (file_name);
}

void	read_start(char *end_flag, int write_flag, int fd)
{
	char	*line;

	while (1)
	{
		line = readline(">");
		if (!line)
			return ;
		if (ft_strcmp(line, end_flag) == 0)
		{
			free(line);
			break ;
		}
		if (write_flag)
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		free(line);
	}
	free(end_flag);
	close(fd);
}

void	stdio_rollback(void)
{
	if (g_shell->io_filename[0])
	{
		unlink(g_shell->io_filename[0]);
		free(g_shell->io_filename[0]);
		g_shell->io_filename[0] = NULL;
		if (dup2(g_shell->std_io[0], STDIN_FILENO) < 0)
			ft_exit("dup error\n", 1);
		close(g_shell->std_io[0]);
		g_shell->std_io[0] = 0;
	}
	if (g_shell->io_filename[1])
	{
		unlink(g_shell->io_filename[1]);
		free(g_shell->io_filename[1]);
		g_shell->io_filename[1] = NULL;
		if (dup2(g_shell->std_io[1], STDOUT_FILENO) < 0)
			ft_exit("dup error\n", 1);
		close(g_shell->std_io[1]);
		g_shell->std_io[1] = 0;
	}
}

void	start_parse(t_token	*tokens)
{
	t_stack		*stack;
	t_ast		*ast;

	stack = get_stack();
	ast = pushdown_automata(stack, tokens, 0, 0);
	release_stack(stack);
	if (!ast)
	{
		g_shell->exit_status = 258;
		return ;
	}
	start_read_heardoc(ast->head, 1);
	if (g_shell->signal_status == 130)
	{
		release_all_ast(ast);
		return ;
	}
	execute_command(ast->head, NULL, NULL, C_NORMAL);
	wait_all_pids();
	if (g_shell->signal_status)
	{
		g_shell->exit_status = g_shell->signal_status;
		g_shell->signal_status = 0;
	}
	release_all_ast(ast);
}
