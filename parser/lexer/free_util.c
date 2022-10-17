/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 04:45:23 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 05:49:53 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	free_auto(t_auto_data *data)
{
	free(data->buffer);
	free(data->exps_list);
	free(data);
}

void	free_token(t_token *token)
{
	t_exps	*cur;
	t_exps	*prev;

	if (token->exps_list)
	{
		cur = token->exps_list->head;
		while (cur)
		{
			prev = cur;
			cur = cur->next;
			free(prev->str);
			free(prev);
		}
	}
	free(token->exps_list);
	free(token->token_data);
	free(token);
}

void	free_t_lst(t_token_list **t_lst)
{
	t_token	*cur;
	t_token	*prev;

	cur = NULL;
	if (*t_lst)
		cur = (*t_lst)->head;
	prev = NULL;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free_token(prev);
	}
	free(*t_lst);
	*t_lst = NULL;
}
