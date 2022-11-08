/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:43:55 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/08 14:44:55 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute_builtin_parent(t_ast_node *head, char **argv)
{
	execute_builtin(head, argv);
	stdio_rollback();
}

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

void	store_stdout(void)
{
	g_shell->io_filename[1] = get_io_filename(1);
	g_shell->std_io[1] = open(g_shell->io_filename[1], O_CREAT, 0644);
	if (g_shell->std_io[1] < 0)
		ft_exit("open error\n", 1);
	if (dup2(STDOUT_FILENO, g_shell->std_io[1]) < 0)
		ft_exit("dup2 error\n", 1);
}

void	store_stdin(void)
{
	g_shell->io_filename[0] = get_io_filename(0);
	g_shell->std_io[0] = open(g_shell->io_filename[0], O_CREAT, 0644);
	if (g_shell->std_io[0] < 0)
		ft_exit("open error\n", 1);
	if (dup2(STDIN_FILENO, g_shell->std_io[0]) < 0)
		ft_exit("dup2 error\n", 1);
}
