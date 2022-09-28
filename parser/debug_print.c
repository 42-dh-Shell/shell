/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:39:23 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/28 19:36:25 by daegulee         ###   ########.fr       */
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

void	print_exps(t_exps *exp, int j)
{
	printf("##############\n");
	printf("exp [%d] -- start %d\n", j, exp->start);
	printf("exp [%d] -- end %d\n", j, exp->end);
	printf("exp [%d] -- data %s\n", j, exp->str);
}

void	print_token(t_token_list *t_list)
{
	t_token	*cur;
	t_exps	*cur_exp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cur = t_list->head;
	while (cur)
	{
		i++;
		print_type(cur, i);
		print_data(cur, i);
		printf("###############\n");
		if (cur->exps_list != NULL)
		{
			cur_exp = cur->exps_list->head;
			while (cur_exp)
			{
				j++;
				print_exps(cur_exp, j);
				if (cur_exp->is_quote)
					printf("This exps is is_quote!\n");
				cur_exp = cur_exp->next;
			}
		}
		cur = cur->next;
	}
}
