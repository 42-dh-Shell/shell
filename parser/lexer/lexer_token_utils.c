/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:07:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/18 15:44:45 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../../libft/libft.h"

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

int	dquote_handler(int *i, t_token *token, char **line, int *str_idx)
{
	*i += 1;
	if (!closed_quote_dquote(*i, line, 34))
	{
		printf("unclosed dquote\n");
		return (0);
	}
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
	*i += 1;
	return (1);
}

int	quote_handler(int *i, t_token	*token, char **line, int *str_idx)
{
	*i += 1;
	if (!closed_quote_dquote(*i, line, ASCII_QUOTE))
	{
		printf("unclosed quote\n");
		return (0);
	}
	while ((*line)[*i] != ASCII_QUOTE)
	{
		token->str[*str_idx] = (*line)[*i];
		*i += 1;
		*str_idx += 1;
	}
	*i += 1;
	return (1);
}

int	expand_handler(int *i, t_token	*token, char **line, int *str_idx)
{
	int				cnt;
	t_expand_info	*new_ex_info;
	int				start_idx;

	cnt = 1;
	new_ex_info = allocate_expand_info();
	new_ex_info->start = *str_idx;
	new_ex_info->split_arg = 1;
	start_idx = *i;
	(token->str)[*str_idx] = '$';
	(*i)++;
	(*str_idx)++;
	while (ft_isdigit((*line)[*i]) || ft_isalpha((*line)[*i]) || \
				(*line)[*i] == '_')
	{
		token->str[*str_idx] = (*line)[*i];
		*i += 1;
		cnt++;
		*str_idx += 1;
	}
	new_ex_info->str = ft_substr((char const *) *line, start_idx, cnt);
	new_ex_info->size = cnt;
	expand_lst_add(token, new_ex_info);
	return (1);
}

int	division_word(char **line, t_token *token, int *i, int *str_idx)
{
	if ((*line)[*i] == ASCII_DQUOTE)
		return (dquote_handler(i, token, line, str_idx));
	else if ((*line)[*i] == ASCII_QUOTE)
		return (quote_handler(i, token, line, str_idx));
	else
		return (expand_handler(i, token, line, str_idx));
}
