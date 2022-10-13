/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:28:45 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/13 17:29:04 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	read_heredoc_token(t_token *head)
{
	char	*line;

	while (head)
	{
		if (head->token_type == DLESS)
		{
			while (1)
			{
				line = readline(">");
				if (ft_strcmp(line, ast->redir_token->str) == 0)
					break ;
			}
		}
		head = head->next;
	}
}
