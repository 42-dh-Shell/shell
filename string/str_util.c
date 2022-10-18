/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:37:30 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 11:42:52 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mystring.h"

void	push_string_char(t_string *string, char c)
{
	t_ch	*cur;

	cur = string->head;
	if (cur == NULL)
	{
		string->head = make_char(c);
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = make_char(c);
	cur->next->idx = string->len;
	(string->len++);
}
