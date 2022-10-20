/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:45:06 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/20 15:41:47 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	t_list_addback(t_token_list *t_list, t_token *new)
{
	t_token	*cur;

	if (t_list->head == NULL)
	{
		t_list->head = new;
		return ;
	}
	cur = t_list->head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

void	exps_lst_addback(t_exps_list **exps_lst, t_exps *new)
{
	t_exps	*cur;

	if (*exps_lst == NULL)
	{
		*exps_lst = malloc(sizeof(t_exps_list));
		if (*exps_lst == NULL)
			ft_exit("malloc error.\n", 1);
		(*exps_lst)->head = new;
		return ;
	}
	cur = (*exps_lst)->head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

t_token	*init_token(t_auto_data *data)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(token, 0, sizeof(t_token));
	token->token_type = data->type;
	token->token_data = ft_strdup(data->buffer);
	token->flag_wild = data->flag_wild;
	if (data->exps_list != NULL)
	{
		token->exps_list = malloc(sizeof(t_exps_list));
		if (token->exps_list == NULL)
			ft_exit("malloc error.\n", 1);
		token->exps_list->head = data->exps_list->head;
	}
	return (token);
}

t_token	*token_dup(t_token *origin)
{
	t_token	*dup;

	dup = ft_malloc(sizeof(t_token));
	dup->token_type = origin->token_type;
	dup->token_data = ft_strdup(origin->token_data);
	dup->flag_wild = origin->flag_wild;
	dup->exps_list = origin->exps_list;
	dup->next = NULL;
	return (dup);
}
