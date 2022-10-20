/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:53:58 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/21 00:50:28 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
// push_down automata 이후에 토큰리스트 프리 푸시다운은 로컬로 들고감 

t_ast	*push_down(t_stack *stack, t_token_list t_list);

t_ast	*parser(char *str)
{
	t_token_list	*t_list;
	t_stack			*stack;
	t_ast			*ast;

	t_list = lexer(str);
	if (t_list == NULL)
		return (NULL);
	stack = init_stack();
	ast = push_down(stack, *t_list);
	free_stack(stack);
	free_t_lst(&t_list);
	print_tree(ast);
	return (ast);
}

void	init_sup(t_ast *ast, t_support **sup, t_token_list *t_list, \
t_stack *stack)
{
	*sup = ft_malloc(sizeof(t_support));
	(*sup)->ast = ast;
	(*sup)->t_list = t_list;
	(*sup)->stack = stack;
	(*sup)->wait = ft_malloc(sizeof(t_wait));
	(*sup)->cur = ast;
}

void	print_unexpect(t_token *token, t_stack *stack)
{
	if (token->token_type == T_WORD)
		printf("minishell : syntax error near unexpected token %s\n", \
		token->token_data);
	else if (token->token_type == T_GREATE)
		printf("minishell : syntax error near unexpected token >\n");
	else if (token->token_type == T_DGREATE)
		printf("minishell : syntax error near unexpected token >>\n");
	else if (token->token_type == T_LESS)
		printf("minishell : syntax error near unexpected token <\n");
	else if (token->token_type == T_DLESS)
		printf("minishell : syntax error near unexpected token <<\n");
	else if (token->token_type == T_R_BRAKIT)
		printf("minishell : syntax error near unexpected token )\n");
	else if (token->token_type == T_L_BRAKIT)
		printf("minishell : syntax error near unexpected token (\n");
	else if (token->token_type == T_PIPE)
		printf("minishell : syntax error near unexpected token |\n");
	else if (token->token_type == T_AND)
		printf("minishell : syntax error near unexpected token &&\n");
	else
		print_unexpect(stack->top->bottom->token, stack);
}

void	free_sup(t_support *sup)
{
	free(sup->wait);
	free(sup);
}

t_ast	*push_down(t_stack *stack, t_token_list t_list)
{
	char			*str;
	t_ast			*ast;
	t_support		*sup;

	str = NULL;
	init_ast(&ast);
	init_sup(ast, &sup, &t_list, stack);
	str = look_lalr_action(stack, str, &t_list);
	while (!str_equal(str, "N") && !str_equal(str, "A"))
	{
		if (ft_strnstr(str, "s", ft_strlen(str)) != NULL)
			st_shift(&str, sup);
		else
			st_reduce(&str, sup);
	}
	free_sup(sup);
	if (str_equal(str, "N"))
	{
		print_unexpect(t_list.head, stack);
		// free_ast(ast);
		return (NULL);
	}
	return (ast);
}
