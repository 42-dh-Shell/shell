/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:04:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/04 17:58:25 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"
#include "../../stack/stack.h"
#include "../../libft/libft.h"

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

int	get_y_idx(t_token *tokens)
{
	if (tokens->token_type == WORD)
		return (IDX_WORD);
	else if (tokens->token_type == LBRAC)
		return (IDX_LBRAC);
	else if (tokens->token_type == RBRAC)
		return (IDX_RBRAC);
	else if (tokens->token_type == LESS)
		return (IDX_LESS);
	else if (tokens->token_type == GREAT)
		return (IDX_GREAT);
	else if (tokens->token_type == DLESS)
		return (IDX_DLESS);
	else if (tokens->token_type == DGREAT)
		return (IDX_DGREAT);
	else if (tokens->token_type == PIPE)
		return (IDX_PIPE);
	else if (tokens->token_type == OR)
		return (IDX_OR);
	else if (tokens->token_type == AND)
		return (IDX_AND);
	else
		return (IDX_LAST);
}

int	action_handler(char *action, t_stack *stack, t_token **tokens)
{
	char	***lalr_table;

	lalr_table = get_table();
	if (action[0] == 'N')
		return (0);
	else if (action[0] == 's')
	{
		do_shift(stack, *tokens, ft_atoi(action + 1, 0));
		(*tokens) = (*tokens)->next;
		return (1);
	}
	else
	{
		if (do_reduce(stack, lalr_table, get_reduce_num(ft_atoi(action + 1, 0)) \
			, get_reduce_grammer(ft_atoi(action + 1, 0))))
			return (1);
		else
			return (0);
	}
}

int	pushdown_automata(t_stack *stack, t_token *tokens, char ***lalr_table)
{
	int		state;
	int		y;
	char	*action;

	while (1)
	{
		state = ft_peek(stack)->data->state;
		y = get_y_idx(tokens);
		action = lalr_table[state][y];
		if (action[0] == 'A')
			return (1);
		else
		{
			if (action_handler(action, stack, &tokens) == 0)
			{
				printf("Syntex Error\n");
				return (0);
			}
		}
	}
	return (0);
}

void	start_parse(t_token	*tokens)
{
	t_stack	*stack;
	t_ast	*ast;

	stack = get_stack();
	if (pushdown_automata(stack, tokens, get_table()))
		ast = make_ast(tokens);
}
