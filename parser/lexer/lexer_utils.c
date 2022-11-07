/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:09:02 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/13 17:28:58 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	closed_quote_dquote(int i, char **line, char quote_code)
{
	while ((*line)[i] != 0)
	{
		if ((*line)[i] == quote_code)
			return (1);
		i++;
	}
	return (0);
}

void	cnt_word_indquote(char *line, int *i, int *cnt)
{
	(*i)++;
	while (line[*i] != 0 && line[*i] != ASCII_DQUOTE)
	{
		(*i)++;
		(*cnt)++;
	}
	if (line[*i] == ASCII_DQUOTE)
		(*i)++;
}

void	cnt_word_inquote(char *line, int *i, int *cnt)
{
	(*i)++;
	while (line[*i] != 0 && line[*i] != ASCII_QUOTE)
	{
		(*i)++;
		(*cnt)++;
	}
	if (line[*i] == ASCII_QUOTE)
		(*i)++;
}

int	is_div_wd(char ch)
{
	return (ch == ASCII_DQUOTE || ch == ASCII_QUOTE || \
					ch == ASCII_EXPAND_SIG);
}

int	get_word_len(char **line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while ((*line)[i] != 0 && !is_space((*line)[i]) && !is_meta((*line)[i]))
	{
		if ((*line)[i] == ASCII_DQUOTE)
			cnt_word_indquote(*line, &i, &cnt);
		else if ((*line)[i] == ASCII_QUOTE)
			cnt_word_inquote(*line, &i, &cnt);
		else
		{
			cnt++;
			i++;
		}
	}
	return (cnt);
}
