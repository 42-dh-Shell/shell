/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:07:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/09/28 13:13:22 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../libft/libft.h"
#include <stdio.h>

void	dquote_expand_handler(char **line, int *i, t_token *token, int *str_idx)
{
	int				cnt;
	t_expand_info	*new_ex_info;
	int				start_idx;

	cnt = 1;
	new_ex_info = allocate_expand_info();
	new_ex_info->start = *str_idx;
	start_idx = *i;
	(token->str)[*str_idx] = '$';
	(*i)++;
	(*str_idx)++;
	while (ft_isdigit((*line)[*i]) || ft_isalpha((*line)[*i]) || \
				(*line)[*i] == '_')
	{
		(token->str)[*str_idx] = (*line)[*i];
		*i += 1;
		cnt++;
		*str_idx += 1;
	}
	new_ex_info->str = ft_substr((char const *) *line, start_idx, cnt);
	new_ex_info->size = cnt;
	expand_lst_add(token, new_ex_info);
}

void	dquote_handler(int *i, t_token *token, char **line, int *str_idx)
{
	*i += 1;
	if (!closed_quote_dquote(*i, line, 34))
		exit(1);
	while ((*line)[*i] != ASCII_DQUOTE)
	{
		if ((*line)[*i] == ASCII_EXPAND_SIG)
			dquote_expand_handler(line, i, token, str_idx);
		else
		{
			token->str[*str_idx] = (*line)[*i];
			*i += 1;
			*str_idx += 1;
		}
	}
}

void	quote_handler(int *i, t_token	*token, char **line, int *str_idx)
{
	*i += 1;
	if (!closed_quote_dquote(*i, line, ASCII_QUOTE))
		exit(1);
	while ((*line)[*i] != ASCII_QUOTE)
	{
		token->str[*str_idx] = (*line)[*i];
		*i += 1;
		*str_idx += 1;
	}
}

void	expand_handler(int *i, t_token	*token, char **line, int *str_idx)
{
	int				cnt;
	t_expand_info	*new_ex_info;
	int				start_idx;

	cnt = 0;
	new_ex_info = allocate_expand_info();
	new_ex_info->start = *str_idx;
	new_ex_info->split_arg = 1;
	start_idx = *i;
	while ((*line)[*i] != 0 && !is_space((*line)[*i]) \
		&& (*line)[*i] != ASCII_DQUOTE && (*line)[*i] != ASCII_QUOTE)
	{
		token->str[*str_idx] = (*line)[*i];
		*i += 1;
		cnt++;
		*str_idx += 1;
	}
	new_ex_info->str = ft_substr((char const *) *line, start_idx, cnt);
	new_ex_info->size = cnt;
	expand_lst_add(token, new_ex_info);
}

void	division_word(char **line, t_token *token, int *i, int *str_idx)
{
	if ((*line)[*i] == ASCII_DQUOTE)
		dquote_handler(i, token, line, str_idx);
	else if ((*line)[*i] == ASCII_QUOTE)
		quote_handler(i, token, line, str_idx);
	else if ((*line)[*i] == ASCII_EXPAND_SIG)
		expand_handler(i, token, line, str_idx);
}
