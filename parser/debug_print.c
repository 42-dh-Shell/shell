/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:39:23 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/28 13:07:44 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static const char *g_type_table[18] = {
	"init", "Word", "Double", "Single", "Expansion", \
	">", ">>", "<", "<<", ")", "(", \
	"&", "&&", "ERROR", "|", "||", "is_space", "FINISH"
};

void	print_type(t_token *token, int i)
{
	printf("Token [%d] type == %s\n", i, \
	g_type_table[token->token_type]);
	if (token->flag_wild)
		printf("token [%d] is_wild!\n", i);
}

void	print_data(t_token *token, int i)
{
	printf("Token [%d] data == %s\n", i, token->token_data);
}

void	print_token(t_token_list *t_list)
{
	t_token	*cur;
	int		i;

	i = 0;
	cur = t_list->head;
	while (cur)
	{
		i++;
		print_type(cur, i);
		print_data(cur, i);
		cur = cur->next;
	}
}
