/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:04:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/17 23:39:52 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../execute/execute.h"

void	print_ast(t_ast_node *ast)
{
	t_expand_info	*info;
	t_suffix		*suffix;

	if (ast->left != 0)
		print_ast(ast->left);
	printf("=========node=========\n");
	if (ast->node_type == NODE_SUBSHELL)
		printf("subshell\n");
	printf("str = %s\n", ast->str);
	if (ast->redir_token != 0)
		printf("redir_token = %s\n", ast->redir_token->str);
	if (ast->expand_info != 0)
	{
		info = ast->expand_info;
		while (info)
		{
			printf("==expand_info==\n");
			printf("%s\n", info->str);
			info = info->next;
		}
	}
	if (ast->suffix_list != 0)
	{
		suffix = ast->suffix_list;
		while (suffix)
		{
			printf("==suffix==\n");
			printf("%s\n", suffix->str);
			suffix = suffix->next;
		}
	}
	if (ast->right != 0)
		print_ast(ast->right);
}

void	print_ast_status(t_ast *ast)
{
	printf("head_node\n");
	printf("%s \n", ast->head->str);
	if (ast->subshell_head != 0)
	{
		printf("subshell\n");
	}
	if (ast->command_node != 0)
	{
		printf("command_node\n");
		printf("%s \n", ast->command_node->str);
	}
	if (ast->last_added != 0)
	{
		printf("last_added\n");
		printf("%s \n", ast->last_added->str);
	}
}

char	*get_full_filename(int file_num)
{
	char		*file_name;

	file_name = ft_calloc (sizeof (char), ft_strlen(TMP_FILENAME) + \
		ft_strlen(TMP_DIR) + ft_strlen(ft_itoa(file_num)) + 1);
	ft_strlcat(file_name, TMP_DIR, ft_strlen(TMP_DIR) + 1);
	ft_strlcat(file_name, TMP_FILENAME, ft_strlen(TMP_FILENAME) + \
			ft_strlen(TMP_DIR) + 1);
	ft_strlcat(file_name, ft_itoa(file_num), ft_strlen(TMP_FILENAME) + \
		ft_strlen(TMP_DIR) + ft_strlen(ft_itoa(file_num)) + 1);
	return (file_name);
}

void	read_start(t_ast_node *ast, int write_flag, int fd)
{
	char	*line;

	while (1)
	{
		line = readline(">");
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
	if (write_flag && ast->node_type == NODE_DLESS && ast->redir_token != 0)
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
		ast->redir_token != 0)
		read_start(ast, write_flag, -1);
	if (ast->left != 0)
		read_heredoc(ast->left, write_flag);
	if (ast->right != 0)
		read_heredoc(ast->right, write_flag);
}

void	start_parse(t_token	*tokens)
{
	t_stack	*stack;
	t_ast	*ast;

	stack = get_stack();
	ast = pushdown_automata(stack, tokens, 0, 0);
	release_stack(stack);
	if (!ast)
	{
		fail_make_token_release(tokens);
		return ;
	}
	release_token_lst(tokens);
	read_heredoc(ast->head, 1);
	// execute_command(ast->head, 0, C_NORMAL);
}
