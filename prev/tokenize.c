/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:01:36 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/26 19:58:17 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const t_fp	g_action[2] = {
	do_s0, do_s1, do_s2, do_s3, do_s4, do_s5, do_s6, do_s7, do_s8, \
	do_s9, do_s10, do_s11, do_s12, do_s13, do_s14, do_s15, do_s16, \
	do_s17
};

int	is_alpha_digit(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') \
	|| (c >= '0' && c <= '9'));
}

int	is_space(char c)
{
	return (c >= 9 && c <= 13);
}

t_token	lex_automata(char *str)
{
	t_auto_data		data;
	t_token_list	*list;
	int				i;

	i = -1;
	ft_memset(&data, 0, sizeof(t_auto_data));
	data.str = str;
	while (data.next_state != L_S17 || data.next_state != L_S13 && *(data.str))
	{
		g_action[data.next_state](&data);
	}
	g_action[data.next_state](&data);
}

int	main(int argc, char **argv)
{
	argc = 1;
	lex_automata(argv[1]);
}
