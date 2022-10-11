/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:53:58 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/11 19:16:22 by daegulee         ###   ########.fr       */
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
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		if (ft_strnstr(str, "s", ft_strlen(str)) != NULL)
			st_shift(&str, sup);
		else
			st_reduce(&str, sup);
	}
	printf("last ! %s\n", str);
	//free(sup);
	// printf("ast p %p\n", ast->root->cmd->cmd_suffix->pre_rd_lst->head);
	if (str_equal(str, "N"))
		return (NULL);
	else
		return (ast);
}
