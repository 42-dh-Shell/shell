/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:42:37 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/28 10:57:41 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"
#include "../../stack/stack.h"
#include "../../minishell.h"

extern t_shell	*g_shell;

void	do_shift(t_stack *stack, t_token *tokens, int status, t_ast *ast)
{
	t_stack_data	*data;

	data = get_stack_data(tokens, TOKEN, -1, -1);
	ft_push(stack, get_stack_node(data));
	data = get_stack_data(0, STATUS, status, -1);
	ft_push(stack, get_stack_node(data));
	make_ast(tokens, ast);
}

int	action_handler(const char *action, t_stack *stack, \
	t_token **tokens, t_ast *ast)
{
	if (action[0] == 'N')
		return (0);
	else if (action[0] == 's')
	{
		do_shift(stack, *tokens, ft_atoi(action + 1, 0), ast);
		(*tokens) = (*tokens)->next;
		return (1);
	}
	else
	{
		if (do_reduce(stack, get_reduce_num(ft_atoi(action + 1, 0)) \
			, get_reduce_grammer(ft_atoi(action + 1, 0))))
			return (1);
		else
			return (0);
	}
}

int	do_reduce(t_stack *stack, int cnt, int reduce_grammer)
{
	int			i;
	t_node		*node;
	t_node		*tg_node;
	const char	*goto_action;

	i = 0;
	while (i != cnt)
	{
		node = ft_pop(stack);
		if (node->data->type != STATUS)
			i++;
		free(node->data);
		free(node);
	}
	node = ft_peek(stack);
	tg_node = get_stack_node(get_stack_data(0, NON_T, -1, reduce_grammer));
	ft_push(stack, tg_node);
	goto_action = g_shell->lr_table[node->data->state][reduce_grammer];
	if (goto_action[0] == 'N')
		return (0);
	tg_node = get_stack_node(get_stack_data(0, STATUS, \
				ft_atoi(goto_action, 0), -1));
	ft_push(stack, tg_node);
	return (1);
}

void	print_stack(t_stack *stack)
{
	t_node			*head;
	t_stack_data	*data;

	head = stack->head;
	while (head)
	{
		data = head->data;
		printf("=======================\n");
		if (data->type == STATUS)
		{
			printf("TYPE = STATUS\n");
			printf("status = %d\n", data->state);
		}
		else if (data->type == TOKEN)
		{
			printf("TYPE = TOKEN\n");
			printf("token = %s\n", data->token->str);
		}
		else if (data->type == NON_T)
		{
			printf("TYPE = NON_T\n");
			printf("idx = %d\n", data->n_terminal_type);
		}
		head = head->next;
	}
}

t_ast	*pushdown_automata(t_stack *stack, t_token *tokens, \
			int state, int y)
{
	const char	*action;
	t_ast		*ast;
	t_token		*prev;

	ast = allocate_ast();
	while (1)
	{
		state = ft_peek(stack)->data->state;
		y = get_y_idx(tokens);
		action = g_shell->lr_table[state][y];
		if (tokens->token_type != LAST)
			prev = tokens;
		if (action[0] == 'A')
			return (ast);
		if (action_handler(action, stack, &tokens, ast) == 0)
		{
			ft_color_printft2(prev->str);
			read_heredoc(ast->head, 1);
			release_all_ast(ast);
			return (0);
		}
	}
}
