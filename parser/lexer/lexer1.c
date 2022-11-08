/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:14:06 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/08 17:10:03 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../parser/parser.h"

void	parsing(t_token *head)
{
	add_last_token(head);
	start_parse(head);
	fail_make_token_release(head);
}
