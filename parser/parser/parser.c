/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:04:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/10 12:37:09 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"
#include "../../stack/stack.h"
#include "../../libft/libft.h"

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

void	start_parse(t_token	*tokens)
{
	t_stack	*stack;
	t_ast	*ast;

	stack = get_stack();
	ast = pushdown_automata(stack, tokens);
	release_token_lst(tokens);
	if (!ast)
		return ;
	print_ast(ast->head);
	//execute_command(ast->head);
}
