/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:04:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/07 11:52:19 by daegulee         ###   ########.fr       */
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

void	read_start(t_ast_node *ast, int write_flag, int fd)
{
	char	*line;

	while (1)
	{
		line = readline(">");
		if (!line)
			return ;
		if (ft_strcmp(line, ast->redir_token->str) == 0)
		{
			free(line);
			break ;
		}
		if (write_flag)
		{
			write(fd, line, ft_strlen(line));
			write (fd, "\n", 1);
		}
		free(line);
	}
}

void	read_heredoc(t_ast_node *ast, int write_flag)
{
	char		*file_name;
	static int	file_num = 0;
	int			fd;

	if (!ast)
		return ;
	if (write_flag && ast->node_type == NODE_DLESS && ast->redir_token)
	{
		file_name = get_full_filename(file_num);
		fd = open (file_name, O_WRONLY | O_CREAT, 0644);
		if (fd < 0)
			ft_exit("file open failed\n", 1);
		read_start(ast, write_flag, fd);
		ast->redir_token->str = file_name;
		close(fd);
		file_num += 1;
	}
	else if (!write_flag && ast->node_type == NODE_DLESS && \
		ast->redir_token)
		read_start(ast, write_flag, -1);
	if (ast->left != 0)
		read_heredoc(ast->left, write_flag);
	if (ast->right != 0)
		read_heredoc(ast->right, write_flag);
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
	else if (g_shell->io_filename[1])
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

void	print_token_data(t_token *head)
{
	int i = 1;
	int j;
	t_expand_info	*info;

	while (head)
	{
		printf("====== token %d =====\n", i++);
		printf("str = %s\n", head->str);
		if (head->token_type == WORD)
			printf("token_type = %s\n", "WORD");
		else if (head->token_type == PIPE)
			printf("token_type = %s\n", "PIPE");
		else if (head->token_type == AND)
			printf("token_type = %s\n", "AND");
		else if (head->token_type == OR)
			printf("token_type = %s\n", "OR");
		else if (head->token_type == LESS)
			printf("token_type = %s\n", "LESS");
		else if (head->token_type == GREAT)
			printf("token_type = %s\n", "GREAT");
		else if (head->token_type == DLESS)
			printf("token_type = %s\n", "DLESS");
		else if (head->token_type == DGREAT)
			printf("token_type = %s\n", "DGREAT");
		else if (head->token_type == LBRAC)
			printf("token_type = %s\n", "LBRAC");
		else if (head->token_type == RBRAC)
			printf("token_type = %s\n", "RBRAC");
		else if (head->token_type == LAST)
			printf("token_type = %s\n", "LAST");
		printf("wildcard_flag = %d\n", head->wildcard_flag);
		j = 1;
		info = head->expand_info;
		while (info)
		{
			printf("\t====== expand_info %d =====\n", j++);
			printf("\tinfo_str = %s\n", info->str);
			printf("\texpand_size = %d\n", info->size);
			printf("\tsplit_arg_flag = %d\n", info->split_arg);
			printf("\tstart_index = %d\n", info->start);
			info = info->next;
		}
		head = head->next;
		printf("\n");
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
		return ;
	signal(SIGINT, signal_here_doc);
	read_heredoc(ast->head, 1);
	signal(SIGINT, signal_handler);
	execute_command(ast->head, NULL, NULL, C_NORMAL);
	stdio_rollback();
	wait_all_pids();
	release_all_ast(ast);
}
