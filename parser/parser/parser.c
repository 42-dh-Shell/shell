/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:04:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/14 15:08:44 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

char	*write_line_in_file(char *line, int file_num)
{
	int			fd;
	char		*full_path;

	full_path = ft_calloc (sizeof (char), ft_strlen(TMP_FILENAME) + \
		ft_strlen(TMP_DIR) + ft_strlen(ft_itoa(file_num)) + 1);
	ft_strlcat(full_path, TMP_DIR, ft_strlen(TMP_DIR) + 1);
	ft_strlcat(full_path, TMP_FILENAME, ft_strlen(TMP_FILENAME) + \
			ft_strlen(TMP_DIR) + 1);
	ft_strlcat(full_path, ft_itoa(file_num), ft_strlen(TMP_FILENAME) + \
		ft_strlen(TMP_DIR) + ft_strlen(ft_itoa(file_num)) + 1);
	fd = open(full_path, O_CREAT, O_WRONLY, 0666);
	if (fd < 0)
		ft_exit("file open failed\n", 1);
	write(fd, line, ft_strlen(line));
	close(fd);
	return (full_path);
}

void	read_start(t_ast_node *ast, int write_flag)
{

}

void	read_heredoc(t_ast_node *ast, int write_flag)
{
	char		*line;
	char		*file_name;
	static int	file_num = 0;

	if (ast != 0 && ast->node_type == NODE_DLESS && ast->redir_token != 0)
	{
		while (1)
		{
			line = readline(">");
			if (ft_strcmp(line, ast->redir_token->str) == 0)
			{
				free(line);
				break ;
			}
			if (write_flag)
				file_name = write_line_in_file(line, file_num);
			free(line);
		}
		ast->redir_token->str = file_name;
	}
	file_num += 1;
	if (ast != 0 && ast->left != 0)
		read_heredoc(ast->left, write_flag);
	if (ast != 0 && ast->right != 0)
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
	print_ast(ast->head);
	//execute_command(ast->head);
}
