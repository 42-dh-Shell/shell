/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:14:06 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/28 10:55:37 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../parser/parser.h"

t_token	*word_token_control(char **line, int i, int str_idx)
{
	t_token	*result;

	result = allocate_token(get_word_len(line));
	while ((*line)[i] != 0 && !is_space((*line)[i]) && !is_meta((*line)[i]))
	{
		if (is_div_wd((*line)[i]))
		{
			if (!division_word(line, result, &i, &str_idx))
				return (0);
		}
		else
		{
			result->str[str_idx] = (*line)[i];
			if (result->str[str_idx] == '*')
				result->wildcard_flag = 1;
			str_idx++;
			i++;
		}
	}
	result->str[str_idx] = 0;
	(*line) += i;
	return (result);
}

t_token	*meta_token_control(char **line)
{
	if (**line == ASCII_PIPE)
	{
		(*line)++;
		return (get_pipe_or_token(line));
	}
	else if (**line == ASCII_GREAT)
	{
		(*line)++;
		return (get_great_dgreat_token(line));
	}
	else if (**line == ASCII_LESS)
	{
		(*line)++;
		return (get_less_dless_token(line));
	}
	else if (**line == ASCII_LBRAK || **line == ASCII_RBRAK)
		return (get_bracket_toekn(line));
	else
	{
		(*line)++;
		return (get_and_token(line));
	}
}

t_token	*get_one_token(char **line)
{
	if (is_meta(**line))
		return (meta_token_control(line));
	else
		return (word_token_control(line, 0, 0));
}

void	add_last_token(t_token *head)
{
	t_token	*last_token;

	last_token = ft_calloc (sizeof(t_token), 1);
	if (!last_token)
		ft_exit("malloc error", 0);
	while (head->next)
		head = head->next;
	last_token->token_type = LAST;
	head->next = last_token;
}

void	lexer_parse(char *line)
{
	t_token	*token;
	t_token	*head;

	head = 0;
	while (is_space(*line))
		line++;
	if (*line == 0)
		return ;
	while (*line != 0)
	{
		token = get_one_token(&line);
		if (token == 0)
		{
			fail_make_token_release(head);
			return ;
		}
		if (token->expand_info != 0)
			validation_ex_info(token);
		token_lst_add(&head, token);
		while (is_space(*line))
			line++;
	}
	add_last_token(head);
	start_parse(head);
	fail_make_token_release(head);
}
