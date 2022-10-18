/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:14:06 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/18 15:48:34 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../parser/parser.h"

void	print_token_data(t_token *head)
{
	int i = 1;
	int j;
	t_expand_info	*info;

	while (head)
	{
		printf("====== token %d =====\n", i++);
		printf("str = %s\n", head->str);
		if (head->token_type == WORD)
			printf("token_type = %s\n", "WORD");
		else if (head->token_type == PIPE)
			printf("token_type = %s\n", "PIPE");
		else if (head->token_type == AND)
			printf("token_type = %s\n", "AND");
		else if (head->token_type == OR)
			printf("token_type = %s\n", "OR");
		else if (head->token_type == LESS)
			printf("token_type = %s\n", "LESS");
		else if (head->token_type == GREAT)
			printf("token_type = %s\n", "GREAT");
		else if (head->token_type == DLESS)
			printf("token_type = %s\n", "DLESS");
		else if (head->token_type == DGREAT)
			printf("token_type = %s\n", "DGREAT");
		else if (head->token_type == LBRAC)
			printf("token_type = %s\n", "LBRAC");
		else if (head->token_type == RBRAC)
			printf("token_type = %s\n", "RBRAC");
		else if (head->token_type == LAST)
			printf("token_type = %s\n", "LAST");
		printf("wildcard_flag = %d\n", head->wildcard_flag);
		j = 1;
		info = head->expand_info;
		while (info)
		{
			printf("\t====== expand_info %d =====\n", j++);
			printf("\tinfo_str = %s\n", info->str);
			printf("\texpand_size = %d\n", info->size);
			printf("\tsplit_arg_flag = %d\n", info->split_arg);
			printf("\tstart_index = %d\n", info->start);
			info = info->next;
		}
		head = head->next;
		printf("\n");
	}
}

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

	last_token = malloc (sizeof(t_token));
	if (!last_token)
		ft_exit("malloc error", 0);
	while (head->next)
		head = head->next;
	last_token->token_type = LAST;
	last_token->expand_info = NULL;
	last_token->next = NULL;
	last_token->wildcard_flag = 0;
	last_token->str = NULL;
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
			validation_ex_info(token->expand_info);
		token_lst_add(&head, token);
		while (is_space(*line))
			line++;
	}
	add_last_token(head);
	print_token_data(head);
	//start_parse(head);
}
